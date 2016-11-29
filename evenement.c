#include "Outilcpy.h"
#include "bibliotheque.h"
#include "perso.h"

//Bibliothèque local
int i;
int j;
int x;
int y;
int nb_arme;

void casBat()//Cas de ressource lors d'une fouille d'un bâtiment
{
	int choix;
	
	do
	{	
		printf("\nMenu :\n");
		printf(" 1 - Vivres \n");
		printf(" 2 - Soins\n");
		printf(" 3 - Matériaux\n");
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
				printf("10 vivres en plus\n");
				break;
			case 2: 
				inventaire.soin += 10;
				printf("10 soins en plus\n");
				break;
			case 3: 
				inventaire.materiaux += 20;
				printf("20 matériaux en plus\n");
				break;
			case 4: 
				for(j=1; j<N; j++)
				{
					if(surv[j].etat != 1)
					{
						defStructPerso(j);
						j=N;
					}
				}
				printf("1 survivant en plus\n");
				break;
			case 5:
				inventArme.machette++;//À compléter avec le programme d'Alexandre
				break;
			case 6: break;
			default: printf("Erreur\n");
		}
	}
	while(choix==999);
	
	
}

void erreur(int materiaux)
{
	if(inventaire.materiaux < materiaux)
		printf("Pas assez de matériaux\n");
	else
		printf("Modification déjà construite\n");
}

void coordonnee()
{
	printf("Entrez les coordonnées en x : ");
	scanf("%i", &x);
	printf("Entrez les coordonnées en y : ");
	scanf("%i", &y);
}

void passTour()
{
	
	for(i = 0; i<= N; i++)
	{
		if(surv[i].etat == 1)
		{
			surv[i].deplacement = 5;
			surv[i].action = 1;
		}
	}
	
	inventaire.vivre -= bus.consoV;
	inventaire.soin -= bus.consoS;
	
	if(inventaire.vivre < 0 || inventaire.soin < 0)
	{
		for(i = 0; i<= N; i++)
		{
			surv[i].hp -= 20;
		}
		if(inventaire.vivre < 0)
			inventaire.vivre = 0;
		else
			inventaire.soin = 0;
	}
}
	
void bouger()
{
	
	printf("Survivant à bouger : ");
	scanf("%i", &i);
	
	if(surv[i].deplacement > 0 && surv[i].etat == 1)
	{
		printf("Entrez les coordonnées du survivant\n");
		coordonnee();
	
		//Programme qui nécessite la carte
		
	}
	else
		printf("Ce survivant n'a plus de déplacement\n");
}

void fouiller()
{
	printf("Survivant qui doit fouiller : ");
	scanf("%i", &i);
	
	if(surv[i].action > 0 && surv[i].etat == 1)
	{
		printf("Entrez les coordonnées du bâtiment\n");
		coordonnee();
		
		//Programme qui nécessite la carte
		casBat();
		surv[i].action = 0;
	}
	else
		printf("Ce survivant n'a plus d'action\n");
}

void attaquer()
{
	printf("Survivant qui doit attaquer : ");
	scanf("%i", &i);
	
	if(surv[i].action > 0 && surv[i].etat == 1)
	{
		printf("Entrez les coordonnées de l'ennemie\n");
		coordonnee();
		
		//Programme qui nécessite la carte
		
	}
	else
		printf("Ce survivant n'a plus d'action\n");
}
	
void afficherInventaire()
{
	nb_arme = inventArme.machette + inventArme.hache + inventArme.epee + inventArme.arc + 
		inventArme.arbalete + inventArme.pistolet + inventArme.mitraillette + inventArme.sniper;
	
	printf("Vivres : %i\nSoins : %i\nMatériaux : %i\nArmes : %i\n",
		 inventaire.vivre, inventaire.soin, inventaire.materiaux, nb_arme);
	
}	
	
void afficherInventArme()
{
	printf("Machette : %i\nHache : %i\nÉpée : %i\nArc : %i\nArbalète : %i\nPistolet : %i\nMitraillette : %i\nSnper : %i\n",
		 inventArme.machette, inventArme.hache, inventArme.epee, inventArme.arc, 
		 inventArme.arbalete, inventArme.pistolet, inventArme.mitraillette, inventArme.sniper);
}
	
	