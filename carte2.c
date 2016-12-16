/**
\file carte2.c
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
\fn void creerRoute2();
\brief Création des routes de la carte 2
*/
void creerRoute2()
{
//Creation des routes
	int i;
	int j;
	
	
//routes verticales de gauche à droite

	for(i=3;i<=10;i++){
		j=2;
		mat[i][j] = 1;
	}
	mat[6][4]=1;
	for(i=0;i<=3;i++){
		j=5;
		mat[i][j] = 1;
	}
	for(i=5;i<=9;i++){
		j=6;
		mat[i][j] = 1;
	}
	for(i=3;i<=7;i++){
		j=9;
		mat[i][j] = 1;
	}

	
//routes horizontales de haut en bas
	
	for(j=0;j<=9;j++){
		i = 3;
		mat[i][j]=1;
	}
	for(j=4;j<=6;j++){
		i=5;
		mat[i][j]=1;
	}		
	for(j=2;j<=4;j++){
		i = 7;
		mat[i][j]=1;
	}
	for(j=6;j<=8;j++){
		i = 7;
		mat[i][j]=1;
	}
	for(j=2;j<=10;j++){
		i = 9;
		mat[i][j]=1;
	}

}

/**
\fn void initPosPerso2();
\brief Initialisation de la position des survivants de la carte 2
*/
void initPosPerso2()
{
	for(int i=1; i<N; i++)
	{
		if(surv[i].etat == 1)
		{
			surv[i].posX = 0;
			surv[i].posY = 5;
		}
	}
}

/**
\fn void carte2();
\brief "Traitement" de la carte 2 
*/
void carte2()
{
	initialisation(mat);
	initialisation(carte);
	initPosPerso2();

	creerRoute2();

	voisinRoute();
	placerBatiment();
}