#include "Outil.h"
#include "perso.h"
#include "CreaCarte.h"

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

void coordonnee()
{
	printf("Entrez les coordonnées en x : ");
	scanf("%i", &x);
	printf("Entrez les coordonnées en y : ");
	scanf("%i", &y);
}

void bougerDirection( int haut, int bas, int gauche, int droite)
{
	verifCarte = verifierCarte(surv[i].posX-haut+bas, surv[i].pos-gauche+droite);
	verifierPerso(i);
	if(verifCarte == 2)
	{
		
	}
	if(verifCarte == 1)
	{
		surv[i].deplacement--;
		surv[i].posX -= haut;
		surv[i].posX += bas;
		surv[i].posY -= gauche;
		surv[i].posY += droite;

	}
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
		char commande[20];
	
		do//Liste des commandes du jeu
		{
			printf("Entrez la direction : ");

			if(surv[i].deplacement > 0)
				commande = "stop";
			
			fgets(commande, sizeof commande, stdin);
		
			if(strcmp(commande, "haut\n") == 0 || strcmp(commande, "nord\n") == 0)
				bougerDirection(1, 0, 0, 0);
		
			if(strcmp(commande, "bas\n") == 0 || strcmp(commande, "sud\n") == 0)
				bougerDirection(0, 1, 0, 0);
			
			if(strcmp(commande, "gauche\n") == 0 || strcmp(commande, "ouest\n") == 0)
				bougerDirection(0, 0, 1, 0);

			if(strcmp(commande, "droite\n") == 0 || strcmp(commande, "est\n") == 0)
				bougerDirection(0, 0, 0, 1);
			
			afficherCarte();
			
		}	
		while(!strcmp(commande, "stop\n") == 0 );
		printf("x = %i  y = %i\n", surv[i].posX, surv[i].posY);
		
	}
	else
		printf("Ce survivant n'a plus de déplacement\n");
}

void fouiller()// Est intégré dans les mouvements
{
	printf("Survivant qui doit fouiller : ");
	scanf("%i", &i);
	
	if(surv[i].action > 0 && surv[i].etat == 1)
	{
				
		
		casBat();//Doit changer de programme
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
	

void changerCarte()
{
	for(i=0; i<3; i++)
	{
		passTour();
	}
	
	choixCarte();
}	
