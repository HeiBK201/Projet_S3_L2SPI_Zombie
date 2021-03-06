/**
\file carte10.c
\brief Création "brute" des routes
\author Sadonnet Alexandre, Cohen Mehdi & Bouquet Tristan
\version 1.0
\date 15/12/2016
*/

#include "Outil.h"
#include "CreaCarte.h"

int mat[T][T];
int carte[T][T];


/**
\fn void creerRoute10();
\brief Création des routes de la carte 10
*/
void creerRoute10()
{
//Creation des routes
	int i;
	int j;

	
//routes verticales de gauche a  droite

	for(i=0;i<=2;i++)
	{
		j=1;
		mat[i][j] = 1;
	}
	for(i=8;i<=10;i++)
	{
		j=2;
		mat[i][j] = 1;
	}
	for(i=2;i<=6;i++)
	{
		j=5;
		mat[i][j] = 1;
	}
	for(i=3;i<=6;i++)
	{
		j=9;
		mat[i][j] = 1;
	}
	
	
//routes horizontales de haut en bas

	for(j=1;j<=5;j++)
	{	
		i = 2;
		mat[i][j]=1;
	}
	for(j=9;j<=10;j++)
	{
		i = 3;
		mat[i][j]=1;
	}		
	for(j=2;j<=5;j++)
	{
		i = 4;
		mat[i][j]=1;
	}
	for(j=2;j<=9;j++)
	{
		i=7;
		mat[i][j]=1;
	}

}

/**
\fn void initPosPerso10();
\brief Initialisation de la position des survivants de la carte 10
*/
void initPosPerso10()
{
	for(int i=1; i<N; i++)
	{
		if(surv[i].etat == 1)
		{
			surv[i].posX = 0;
			surv[i].posY = 1;
		}
	}
}

/**
\fn void carte10();
\brief "Traitement" de la carte 10
*/
void carte10()
{
	initialisation(mat);
	initialisation(carte);
	initPosPerso10();

	creerRoute10();
	
	voisinRoute();
	placerBatiment();
}