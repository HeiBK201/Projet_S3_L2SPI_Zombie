/**
\file carte7.c
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
\fn void creerRoute7();
\brief Création des routes de la carte 7
*/
void creerRoute7()
{
//Creation des routes
	int i;
	int j;

	
//routes verticales de gauche a  droite

	mat[10][3] = 1;
	for(i=0;i<=9;i++)
	{
		j=5;
		mat[i][j] = 1;
	}

	
//routes horizontales de haut en bas

	for(j=0;j<=5;j++)
	{	
		i = 2;
		mat[i][j]=1;
	}
	for(j=9;j<=10;j++)
	{
		i= 2;
		mat[i][j]=1;
	}		
	for(j=6;j<=9;j++)
	{
		i = 3;
		mat[i][j]=1;
	}
	for(j=0;j<=5;j++)
	{
		i=6;
		mat[i][j]=1;
	}
	for(j=5;j<=8;j++)
	{
		i = 8;
		mat[i][j]=1;
	}
	for(j=3;j<=5;j++)
	{
		i=9;
		mat[i][j]=1;
	}
}

/**
\fn void initPosPerso7();
\brief Initialisation de la position des survivants de la carte 7
*/
void initPosPerso7()
{
	for(int i=1; i<N; i++)
	{
		if(surv[i].etat != 1)
		{
			surv[i].posX = 5;
			surv[i].posY = 4;
		}
	}
}

/**
\fn void carte7();
\brief "Traitement" de la carte 7 
*/
void carte7()
{
	initialisation(mat);
	initialisation(carte);
	initPosPerso7();

	creerRoute7();
	
	voisinRoute();
	placerBatiment();
}


