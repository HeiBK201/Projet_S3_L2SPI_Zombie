#include "Outil.h"
#include "CreaCarte.h"

int mat[T][T];
int carte[T][T];


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


void carte7()
{
	initialisation(mat);
	initialisation(carte);
	initPosPerso7();

	creerRoute7();
	
	voisinRoute();
	placerBatiment();
}


