#include "Outilcpy.h"
#include "bibliotheque.h"
#include "perso.h"

void event()
{
	int choix;
	int j;
	do
	{	
		printf("\nMenu :\n");
		printf(" 1 - Vivres \n");
		printf(" 2 - Soins\n");
		printf(" 3 - Materiaux\n");
		printf(" 4 - Survivant\n");
		printf(" 5 - Arme\n");
		printf(" 6 - Quitter\n");
		printf("Votre choix : ");
		scanf("%d",&choix);
	
// Traitement du choix de l'utilisateur 
		switch(choix)
		{	
			case 1: 
				inventaire.vivre += 10;
				break;
			case 2: 
				inventaire.soin += 10;
				break;
			case 3: 
				inventaire.materiaux += 20; 
				break;
			case 4: 
				for(j=0; j<=N; j++)
				{
					while(surv[j].etat == 1);
					defStructPerso(j);
				}
				break;
			case 5:
				inventArme.machette++;
				break;
			case 6: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 5\n");
		}
	}
	while(choix<6);
	printf("Au revoir !\n");
	
}

void erreur(int materiaux)
{
	if(inventaire.materiaux < materiaux)
		printf("Pas assez de matériaux\n");
	else
		printf("Modification déjà construite\n");
}