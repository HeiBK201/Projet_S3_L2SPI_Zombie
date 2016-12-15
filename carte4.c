/**
\file carte4.c
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
\fn void creerRoute4();
\brief Création des routes de la carte 4
*/
void creerRoute4()
{
//Creation des routes
	int i;
	int j;


//routes verticales de gauche à droite

	for(i=0;i<=10;i++){
		j = 4;
		mat[i][j]=1;
	}
	mat[2][6]=1;
	for(i=2;i<=8;i++){
		j=9;
		mat[i][j]=1;
	}

	
//routes horizontales de haut en bas
	

	for(j=0;j<=2;j++){
		i=1;
		mat[i][j] = 1;
	}
	for(j=4;j<=6;j++){
		i=1;
		mat[i][j] = 1;
	}
	for(j=2;j<=4;j++){
		i=2;
		mat[i][j] = 1;
	}
	for(j=4;j<=6;j++){
		i=3;
		mat[i][j] = 1;
	}
	for(j=0;j<=4;j++){
		i=5;
		mat[i][j] = 1;
	}
	for(j=2;j<=10;j++){
		i=8;
		mat[i][j] = 1;
	}
	for(j=0;j<=2;j++){
		i=9;
		mat[i][j] = 1;
	}
}

/**
\fn void initPosPerso4();
\brief Initialisation de la position des survivants de la carte 4
*/
void initPosPerso4()
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
\fn void carte4();
\brief "Traitement" de la carte 4
*/
void carte4()
{
	initialisation(mat);
	initialisation(carte);
	initPosPerso4();

	creerRoute4();

	voisinRoute();
	placerBatiment();
}


