#include "Outilcpy.h"
#include "CreaCarte.h"

int mat[T][T];
int carte[T][T];

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

void initPosPerso1()
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

void carte1()
{
	initialisation(mat);
	initialisation(carte);
	initPosPerso1();

	creerRoute1();

	voisinRoute();
	placerBatiment();
}
