#include "Outil.h"
#include "CreaCarte.h"


int verifRoute = 0;


void bougerHaut(int i)
{
	verifRoute = verifierRoute(surv[i].posX, surv[i].posY-1);
	if(verifRoute == 1)
	{
		surv[i].posY -= 1;
		surv[i].deplacement--;
	}
	afficherCarte();
}

void bougerBas(int i)
{
	verifRoute = verifierRoute(surv[i].posX, surv[i].posY+1);
	if(verifRoute == 1)
	{
		surv[i].posY += 1;
		surv[i].deplacement--;
	}
	afficherCarte();
}

void bougerDroite(int i)
{
	printf("x = %i  y = %i\n", surv[i].posX, surv[i].posY);	
	verifRoute = verifierRoute(surv[i].posX+1, surv[i].posY);
	if(verifRoute == 1)
	{
		surv[i].posX += 1;
		surv[i].deplacement--;
	}
	afficherCarte();
	//Assert1("probleme verif route", verifRoute==1);
}

void bougerGauche(int i)
{
	verifRoute = verifierRoute(surv[i].posX-1, surv[i].posY);
	if(verifRoute == 1)
	{
		surv[i].posX -= 1;
		surv[i].deplacement--;
	}
	afficherCarte();
}


void mouvoir(int i)
{
	char commande[20];
	
	
	do//Liste des commandes du jeu
	{
				
		printf("Commande : ");//Affiche 2x Commande : -> A revoir
		fgets(commande, sizeof commande, stdin);
		
		if(strcmp(commande, "haut\n") == 0 || strcmp(commande, "nord\n") == 0)
			bougerHaut(i);
		
		if(strcmp(commande, "bas\n") == 0 || strcmp(commande, "sud\n") == 0)
			bougerBas(i);
			
		if(strcmp(commande, "droite\n") == 0 || strcmp(commande, "est\n") == 0)
			bougerDroite(i);
			
		if(strcmp(commande, "gauche\n") == 0 || strcmp(commande, "ouest\n") == 0)
			bougerGauche(i);
			
	}	
	while(!strcmp(commande, "quitter\n") == 0 || !strcmp(commande, "sortir\n") == 0 || surv[i].deplacement==0);
	
}
