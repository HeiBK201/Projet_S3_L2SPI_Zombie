#include "Outilcpy.h"
#include "CreaCarte.h"

int survivant;
int verifRoute = 0;


void bougerHaut()
{
	verifRoute = verifierRoute(surv[survivant].posX, surv[survivant].posY-1);
	if(verifRoute == 1)
	{
		surv[survivant].posY -= 1;
		surv[survivant].deplacement--;
	}
	afficherCarte();
}

void bougerBas()
{
	verifRoute = verifierRoute(surv[survivant].posX, surv[survivant].posY+1);
	if(verifRoute == 1)
	{
		surv[survivant].posY += 1;
		surv[survivant].deplacement--;
	}
	afficherCarte();
}

void bougerDroite()
{
	verifRoute = verifierRoute(surv[survivant].posX+1, surv[survivant].posY);
	if(verifRoute == 1)
	{
		surv[survivant].posX += 1;
		surv[survivant].deplacement--;
	}
	afficherCarte();
	printf("%i", verifRoute);
	Assert1("probleme verif route", verifRoute==1);
}

void bougerGauche()
{
	verifRoute = verifierRoute(surv[survivant].posX-1, surv[survivant].posY);
	if(verifRoute == 1)
	{
		surv[survivant].posX -= 1;
		surv[survivant].deplacement--;
	}
	afficherCarte();
}


void mouvoir(int i)
{
	char commande[20];
	survivant = i;
	
	do//Liste des commandes du jeu
	{
				
		printf("Commande : ");//Affiche 2x Commande : -> A revoir
		fgets(commande, sizeof commande, stdin);
		
		if(strcmp(commande, "haut\n") == 0 || strcmp(commande, "nord\n") == 0)
			bougerHaut();
		
		if(strcmp(commande, "bas\n") == 0 || strcmp(commande, "sud\n") == 0)
			bougerBas();
			
		if(strcmp(commande, "droite\n") == 0 || strcmp(commande, "est\n") == 0)
			bougerDroite();
			
		if(strcmp(commande, "gauche\n") == 0 || strcmp(commande, "ouest\n") == 0)
			bougerGauche();
			
	}	
	while(!strcmp(commande, "quitter\n") == 0 || !strcmp(commande, "sortir\n") == 0 || surv[i].deplacement==0);
	
}