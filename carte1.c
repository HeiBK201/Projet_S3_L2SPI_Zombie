/**
\file carte1.c
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
\fn void creerRoute1();
\brief Création des routes de la carte 1
*/
void creerRoute1()
{
//Creation des routes
	int i;
	int j;

	
//routes verticales de gauche a  droite

	for(i=0;i<=9;i++)
	{	
		j = 3;
		mat[i][j]=1;
	}
	for(i=4;i<=6;i++)
	{
		j=5;
		mat[i][j]=1;
	}		
	for(i=2;i<=4;i++)
	{
		j = 7;
		mat[i][j]=1;
	}
	for(i=6;i<=8;i++)
	{
		j = 7;
		mat[i][j]=1;
	}
	for(i=2;i<=10;i++)
	{
		j=9;
		mat[i][j]=1;
	}
	
//routes horizontales de haut en bas
	
	for(j=3;j<=10;j++)
	{
		i=2;
		mat[i][j] = 1;
	}
	mat[4][6]=1;
	for(j=0;j<=3;j++)
	{
		i=5;
		mat[i][j] = 1;
	}
	for(j=5;j<=9;j++)
	{
		i=6;
		mat[i][j] = 1;
	}
	for(j=3;j<=7;j++)
	{
		i=9;
		mat[i][j] = 1;
	}
}

/**
\fn void initPosPerso1();
\brief Initialisation de la position des survivants de la carte 1
*/
void initPosPerso1()
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
\fn void carte1();
\brief "Traitement" de la carte 1 
*/
void carte1()
{
	initialisation(mat);
	initialisation(carte);
	initPosPerso1();

	creerRoute1();

	voisinRoute();
	placerBatiment();
}