#include "Outilcpy.h"
#include "bus.h"
#include "perso.h"
#include "evenement.h"
 
//Appel des commandes du jeu
void jeu()
{
	int j;
	for(j=0; j<=3; j++)//Initialisation du nombre de survivant au début
	{
		defStructPerso(j);
	}
	
	defStructBus();
	
	char commande[20];
	
	do
	{
		printf("Commande : ");//Affiche 2x Commande : -> A revoir
		fgets(commande, sizeof commande, stdin);
	
		if(strcmp(commande, "ameliorer\n") == 0)
			ameliorer();
		
		if(strcmp(commande, "evenement\n") == 0)
			event();
			
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