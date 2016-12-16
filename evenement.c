#include "Outil.h"
#include "perso.h"
#include "CreaCarte.h"
#include "Fonction_bat.h"

//Bibliothèque local
int i;
int j;
int x;
int y;
int nb_arme;
int verifCarte = 0;

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

void bougerDirection( int haut, int bas, int gauche, int droite)
{
	verifCarte = verifierCarte(surv[i].posX-haut+bas, surv[i].posY-gauche+droite);
	verifierPerso(i);
	
	if(verifCarte == 3)
	{
		if(surv[i].action > 0)
		{
			actionFouiller(surv[i].posX-haut+bas, surv[i].posY-gauche+droite);
			verifCarte = 2;
		}
		else
			printf("Ce survivant ne plus effectuer une action\n");
	}
	if(verifCarte == 2)
	{
		if(surv[i].action > 0)
		{
			surv[i].action--;
			surv[i].posX -= haut;
			surv[i].posX += bas;
			surv[i].posY -= gauche;
			surv[i].posY += droite;
			printf("%i, %i\n", surv[i].deplacement, surv[i].action);
		}
		else
			printf("Ce survivant ne plus effectuer une action\n");
	}
	if(verifCarte == 1)
	{
		if(surv[i].deplacement > 0)
		{
			surv[i].deplacement--;
			surv[i].posX -= haut;
			surv[i].posX += bas;
			surv[i].posY -= gauche;
			surv[i].posY += droite;
			printf("%i, %i\n", surv[i].deplacement, surv[i].action);
		}
		else
			printf("Ce survivant ne peut plus se déplacer\n");

	}
	afficherCarte();
}


void passTour()
{
	
	for(i = 1; i<= N; i++)
	{
		if(surv[i].etat == 1)
		{
			surv[i].deplacement = 5;
			surv[i].action = 1;
		}
	}
	
	inventaire.vivre -= bus.consoV;
	inventaire.soin -= bus.consoS;
	
	if(inventaire.vivre < 1 || inventaire.soin < 1)
	{
		for(i = 0; i<= N; i++)
		{
			if(surv[i].etat == 1)
			{
				surv[i].hp -= 20;
			}
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
 	printf("%i, %i\n", surv[i].deplacement, surv[i].action);
	
	if( surv[i].etat == 1 && (surv[i].deplacement > 0 || surv[i].action > 0))
	{
		char commande[20];
	
		do//Liste des commandes de deplacement
		{
			if(surv[i].deplacement == 0 && surv[i].action == 0)
				break;
				
			printf("Entrez la direction : ");
			
			fgets(commande, sizeof commande, stdin);
		
			if(strcmp(commande, "haut\n") == 0 || strcmp(commande, "nord\n") == 0)
				bougerDirection(1, 0, 0, 0);
		
			if(strcmp(commande, "bas\n") == 0 || strcmp(commande, "sud\n") == 0)
				bougerDirection(0, 1, 0, 0);
			
			if(strcmp(commande, "gauche\n") == 0 || strcmp(commande, "ouest\n") == 0)
				bougerDirection(0, 0, 1, 0);

			if(strcmp(commande, "droite\n") == 0 || strcmp(commande, "est\n") == 0)
				bougerDirection(0, 0, 0, 1);
			
		}	
		while(!(strcmp(commande, "stop\n") == 0 ));
		//printf();
		
	}
	else
		printf("Ce survivant n'a plus de déplacement\n");
}

void attaquer()
{
	printf("Survivant qui doit attaquer : ");
	scanf("%i", &i);
	
	if(surv[i].action > 0 && surv[i].etat == 1)
	{
		printf("Entrez les coordonnées de l'ennemie\n");
		
		
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
	

void changerCarte()
{
	for(i=0; i<3; i++)
	{
		passTour();
	}
	
	choixCarte();
}	