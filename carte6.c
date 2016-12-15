/**
\file carte6.c
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
\fn void creerRoute6();
\brief Création des routes de la carte 6
*/
void creerRoute6()
{
//Creation des routes
	int i;
	int j;

	
//routes verticales de gauche a  droite

	for(i=5;i<=7;i++)
	{
		j=1;
		mat[i][j] = 1;
	}
	mat[0][2]=1;
	for(i=9;i<=10;i++)
	{
		j=2;
		mat[i][j] = 1;
	}
	mat[7][4]=1;
	for(i=1;i<=3;i++)
	{
		j=5;
		mat[i][j] = 1;
	}
	mat[5][6]=1;
	mat[10][6]=1;
	for(i=2;i<=3;i++)
	{
		j=8;
		mat[i][j] = 1;
	}
	for(i=4;i<=9;i++)
	{
		j=9;
		mat[i][j] = 1;
	}
	
//routes horizontales de haut en bas

	for(j=2;j<=5;j++)
	{	
		i = 1;
		mat[i][j]=1;
	}
	for(j=8;j<=10;j++)
	{
		i= 1;
		mat[i][j]=1;
	}		
	for(j=0;j<=9;j++)
	{
		i = 4;
		mat[i][j]=1;
	}
	for(j=4;j<=6;j++)
	{
		i = 6;
		mat[i][j]=1;
	}
	for(j=1;j<=4;j++)
	{
		i=8;
		mat[i][j]=1;
	}
	for(j=6;j<=9;j++)
	{
		i=9;
		mat[i][j]=1;
	}
}

/**
\fn void initPosPerso6();
\brief Initialisation de la position des survivants de la carte 6
*/
void initPosPerso6()
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
\fn void carte6();
\brief "Traitement" de la carte 6 
*/
void carte6()
{
	initialisation(mat);
	initialisation(carte);
	initPosPerso6();

	creerRoute6();
	
	voisinRoute();
	placerBatiment();
}


