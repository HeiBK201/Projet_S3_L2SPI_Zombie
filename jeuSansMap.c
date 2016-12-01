#include "Outilcpy.h"
#include "bus.h"
#include "perso.h"
#include "evenement.h"
#include "CreaCarte.h"
 
//Appel des commandes du jeu
void jeu()
{
	int j;
	for(j=0; j<=3; j++)//Initialisation du nombre de survivant au début
	{
		defStructPerso(j);
	}
	choixCarte(); //Initialisation de la carte
	
	defStructBus();//Initialisation du bus
	
	char commande[20];
	
	do//Liste des commandes du jeu
	{
		printf("Commande : ");//Affiche 2x Commande : -> A revoir
		fgets(commande, sizeof commande, stdin);
	
		if(strcmp(commande, "ameliorer\n") == 0 || strcmp(commande, "amelioration\n") == 0)
			ameliorer();
			
		if(strcmp(commande, "inventaire\n") == 0)
			afficherInventaire();
		
		if(strcmp(commande, "inventaire arme\n") == 0 || strcmp(commande, "inventairearme\n") == 0)
			afficherInventArme();
		
		if(strcmp(commande, "batiment\n") == 0)
			casBat();
		
		if(strcmp(commande, "carte\n") == 0)
			afficherCarte();
			
		if(strcmp(commande, "passer\n") == 0 || strcmp(commande, "fin du tour\n") == 0 || strcmp(commande, "findutour\n") == 0)
			passTour();
			
		if(strcmp(commande, "bouger\n") == 0 || strcmp(commande, "deplacer\n") == 0)
			bouger();
			
		if(strcmp(commande, "fouiller\n") == 0)
			fouiller();
			
		if(strcmp(commande, "attaquer\n") == 0)
			attaquer();
			
		if(strcmp(commande, "voyage\n") == 0)
			changerCarte();
			
		if(strcmp(commande, "cheat\n") == 0)
			dev();
	}	
	while(!strcmp(commande, "quitter\n") == 0);
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
		
	jeu();
		
	Appel1("");//NE PAS TOUCHER; ce code doit toujours être placé à la fin du main, juste avant le return()
    return 0;
}