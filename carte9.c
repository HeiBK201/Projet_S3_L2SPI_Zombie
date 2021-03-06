/**
\file carte9.c
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
\fn void creerRoute9();
\brief Création des routes de la carte 9
*/
void creerRoute9()
{
//Creation des routes
	int i;
	int j;

	
//routes verticales de gauche a  droite

	for(i=1;i<=5;i++)
	{	
		j = 2;
		mat[i][j]=1;
	}
	for(i=9;i<=10;i++)
	{
		j= 3;
		mat[i][j]=1;
	}		
	for(i=2;i<=5;i++)
	{
		j = 4;
		mat[i][j]=1;
	}
	for(i=2;i<=9;i++)
	{
		j=7;
		mat[i][j]=1;
	}
	
	
//routes horizontales de haut en bas

	for(j=0;j<=2;j++)
	{
		i=1;
		mat[i][j] = 1;
	}
	for(j=8;j<=10;j++)
	{
		i=2;
		mat[i][j] = 1;
	}
	for(j=2;j<=6;j++)
	{
		i=5;
		mat[i][j] = 1;
	}
	for(j=3;j<=6;j++)
	{
		i=9;
		mat[i][j] = 1;
	}
}

/**
\fn void initPosPerso9();
\brief Initialisation de la position des survivants de la carte 9
*/
void initPosPerso9()
{
	for(int i=1; i<N; i++)
	{
		if(surv[i].etat == 1)
		{
			surv[i].posX = 2;
			surv[i].posY = 10;
		}
	}
}

/**
\fn void carte9();
\brief "Traitement" de la carte 9
*/
void carte9()
{
	initialisation(mat);
	initialisation(carte);
	initPosPerso9();

	creerRoute9();
	
	voisinRoute();
	placerBatiment();
}