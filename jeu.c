#include "Outil.h"
#include "bus.h"
#include "perso.h"
#include "evenement.h"
#include "CreaCarte.h"
 
 
void legende()
{
 	printf("S = survivant          Z = zombie           # = Route\n");
	printf("M = maison             E = epicerie         + = Clinique\n");
	printf("G = garage             C = champ            U = usine\n");
}
 
void aide()
{
	printf("ameliorer_____________Ameliorer le bus\n");
	printf("inventaire____________Afficher l'inventaire\n");
	printf("inventaire arme_______Afficher l'inventaire des armes\n");
	printf("info survivant________Afficher les information sur un survivant\n");
	printf("carte_________________Afficher la carte\n");
	printf("fin du tour___________Mettre fin au tour\n");
	printf("deplacer______________Déplacer un survivant\n");
	printf("attaquer______________Attaquer avec un survivant\n");
	printf("legende_______________Afficher la légende de la carte\n");
	printf("voyage________________Aller vers une nouvelle ville\n");
	
}
 
//Appel des commandes du jeu
void jeu()
{
	int j;
	for(j=1; j<=3; j++)//Initialisation du nombre de survivant au début
	{
		defStructPerso(j);
	}
	//j est à 4
	
	choixCarte(); //Initialisation de la carte
	
	defStructBus();//Initialisation du bus
	
	char commande[20];
	
	printf("Vous arrivez dans une nouvelle ville ! \n");
	
	
	do//Liste des commandes du jeu
	{
		srand(time(NULL));
		
		printf("\nPour connaître les commandes tapez 'aide'\n");
		printf("Commande : ");//Affiche 2x Commande : -> A revoir
		fgets(commande, sizeof commande, stdin);
	
		if(strcmp(commande, "ameliorer\n") == 0 || strcmp(commande, "amelioration\n") == 0)
			ameliorer();
			
		if(strcmp(commande, "inventaire\n") == 0)
			afficherInventaire();
		
		if(strcmp(commande, "inventaire arme\n") == 0 || strcmp(commande, "inventairearme\n") == 0)
			afficherInventArme();
		
		if(strcmp(commande, "survivant\n") == 0 || strcmp(commande, "info survivant\n") == 0)
			afficherInfoPerso(0);
		
		if(strcmp(commande, "batiment\n") == 0)
			casBat();
		
		if(strcmp(commande, "carte\n") == 0)
			afficherCarte();
			
		if(strcmp(commande, "passer\n") == 0 || strcmp(commande, "fin du tour\n") == 0 || strcmp(commande, "findutour\n") == 0)
			passTour();
			
		if(strcmp(commande, "bouger\n") == 0 || strcmp(commande, "deplacer\n") == 0)
			bouger();
			
		if(strcmp(commande, "attaquer\n") == 0)
			attaquer();
		
		if(strcmp(commande, "legende\n") == 0)
			legende();
		
		if(strcmp(commande, "aide\n") == 0)
			aide();
			
		if(strcmp(commande, "voyage\n") == 0)
		{
			printf("Vous arrivez dans une nouvelle ville ! \n");
			changerCarte();
		}
			
		if(strcmp(commande, "cheat\n") == 0)
			dev();
	}	
	while(!strcmp(commande, "quitter\n") == 0);
}

void introduction()
{
	system("clear");
	printf("Le monde est en proie à un désastre, les zombies sont partout!\n");
	printf("Vous dirigez une petite communautée de 3 personnes et devez les amenez\n");
	printf("à survivre à cette catastrophe. Équipé d'un bus, voyagez de ville en \n");
	printf("ville et pillez les pour vous réaprovisionner en nourriture et médicament.\n");
	Ligne();
	Ligne();
	legende();
	jeu();
}

void credit()
{
	printf("Jeu réalisé dans le carde du projet de S3 de la L2SPI-2016-2017\n");
	Ligne();
	printf("Écrit par Tristan Bouquet\n");
	printf("Réalisé par Tristan Bouquet, Mehdi Cohen, Alexandre Sadonnet\n");
}

void menu()
{
	char commande[20];
	
	
	do//Liste des actions du menu
	{
		system("clear");
		printf("	+--------------------------------------------------------------------------------------+\n");
		printf("	| ▇▇▇▇▇                       ▇▇▇▇▇                                                    |\n");
		printf("	|     ▇                         ▇                                                      |\n");
		printf("	|    ▇                          ▇                                                      |\n");
		printf("	|   ▇     ▇▇▇   ▇   ▇  ▇▇▇▇     ▇    ▇   ▇  ▇   ▇   ▇▇▇   ▇▇▇▇   ▇▇▇▇▇  ▇▇▇▇     ▇▇▇▇  |\n");
		printf("	|  ▇     ▇   ▇  ▇▇ ▇▇  ▇   ▇    ▇    ▇▇  ▇  ▇   ▇  ▇   ▇  ▇   ▇  ▇      ▇   ▇   ▇      |\n");
		printf("	| ▇      ▇   ▇  ▇ ▇ ▇  ▇▇▇▇     ▇    ▇ ▇ ▇   ▇ ▇   ▇▇▇▇▇  ▇   ▇  ▇▇▇▇   ▇▇▇▇     ▇▇▇   |\n");
		printf("	| ▇      ▇   ▇  ▇   ▇  ▇   ▇    ▇    ▇  ▇▇   ▇ ▇   ▇   ▇  ▇   ▇  ▇      ▇   ▇       ▇  |\n");
		printf("	| ▇▇▇▇▇   ▇▇▇   ▇   ▇  ▇▇▇▇   ▇▇▇▇▇  ▇   ▇    ▇    ▇   ▇  ▇▇▇▇   ▇▇▇▇▇  ▇   ▇   ▇▇▇▇   |\n");
		printf("	+--------------------------------------------------------------------------------------+\n");
		printf("		-Nouvelle partie				-Charger partie\n");
		Ligne();
		printf("		-Crédits					-Quitter\n");
		Ligne();
		printf("Votre choix :")
		
		fgets(commande, sizeof commande, stdin);
	
		if(strcmp(commande, "nouveau\n") == 0 || strcmp(commande, "nouvelle\n") || strcmp(commande, "1\n") == 0)
			introduction();
		
		if(strcmp(commande, "charger\n") == 0 || strcmp(commande, "2\n") == 0)
			printf("La sauvegarde sera bientôt disponible, nous sommes en train de fouetter le responsable de ce retard\n");
			
		if(strcmp(commande, "credits\n") == 0 || strcmp(commande, "3\n") == 0)
			credit();
			
		if(strcmp(commande, "quitter\n") == 0 || strcmp(commande, "4\n") == 0)
			system("exit");
	}	
	while(!strcmp(commande, "Message super bien caché, tu ne le devineras jamais\n") == 0);
	printf("... Oh Wait !");
}

void ModuleAmorceR()
{
	//amorce tous les modules (code à exécuter une fois pour toutes AVANT d'utiliser un quelconque module depuis le main)
	OutilAMORCER();//NE PAS DECLASSER:doit toujours être appelé en premier
	//amorcer TOUS les modules autres que Outil mentionnés dans les include de main.c
	
}//ModuleAmorceR

int main (int argc, const char * argv[]) 
{
	Appel0("");//NE PAS TOUCHER; ce code doit toujours être placé au début du main
		ModuleAmorceR();//NE PAS TOUCHER; ce code doit toujours suivre immédiatement Appel0("")
	
	srand(time(NULL));
	menu();
		
	Appel1("");//NE PAS TOUCHER; ce code doit toujours être placé à la fin du main, juste avant le return()
    return 0;
}
