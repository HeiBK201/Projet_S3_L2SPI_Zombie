/**
\file carte5.c
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
\fn void creerRoute5();
\brief Création des routes de la carte 5
*/
void creerRoute5()
{
//Creation des routes
	int i;
	int j;

	
//routes verticales de gauche a  droite
	for(i=2;i<=5;i++)
	{	
		j = 1;
		mat[i][j]=1;
	}
	for(i=8;i<=10;i++)
	{
		j= 1;
		mat[i][j]=1;
	}		
	for(i=0;i<=9;i++)
	{
		j = 4;
		mat[i][j]=1;
	}
	for(i=4;i<=6;i++)
	{
		j = 6;
		mat[i][j]=1;
	}
	for(i=1;i<=4;i++)
	{
		j=8;
		mat[i][j]=1;
	}
	for(i=6;i<=9;i++)
	{
		j=9;
		mat[i][j]=1;
	}
	
//routes horizontales de haut en bas

	for(j=5;j<=7;j++)
	{
		i=1;
		mat[i][j] = 1;
	}
	mat[2][0]=1;
	for(j=9;j<=10;j++)
	{
		i=2;
		mat[i][j] = 1;
	}
	mat[4][7]=1;
	for(j=1;j<=3;j++)
	{
		i=5;
		mat[i][j] = 1;
	}
	mat[6][5]=1;
	mat[6][10]=1;
	for(j=2;j<=3;j++)
	{
		i=8;
		mat[i][j] = 1;
	}
	for(j=4;j<=9;j++)
	{
		i=9;
		mat[i][j] = 1;
	}
}

/**
\fn void creerRoute5();
\brief Création des routes de la carte 5
*/
void initPosPerso5()
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
\fn void carte5();
\brief "Traitement" de la carte 5 
*/
void carte5()
{
	initialisation(mat);
	initialisation(carte);
	initPosPerso5();

	creerRoute5();
	
	voisinRoute();
	placerBatiment();
}


