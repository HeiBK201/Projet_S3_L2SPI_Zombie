#include "Outilcpy.h"
#include "CreaCarte.h"

int mat[T][T];
int carte[T][T];


void creerRoute8()
{
//Creation des routes
	int i;
	int j;

	
//routes verticales de gauche a  droite

	for(i=0;i<=5;i++)
	{	
		j = 2;
		mat[i][j]=1;
	}
	for(i=9;i<=10;i++)
	{
		j= 2;
		mat[i][j]=1;
	}		
	for(i=6;i<=9;i++)
	{
		j = 3;
		mat[i][j]=1;
	}
	for(i=0;i<=5;i++)
	{
		j=6;
		mat[i][j]=1;
	}
	for(i=5;i<=8;i++)
	{
		i = 8;
		mat[i][j]=1;
	}
	for(i=3;i<=5;i++)
	{
		j=9;
		mat[i][j]=1;
	}
	
	
//routes horizontales de haut en bas
	mat[3][10] = 1;
	for(j=0;j<=9;j++)
	{
		i=5;
		mat[i][j] = 1;
	}
	
}

void initPosPerso8()
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

void carte8()
{
	initialisation(mat);
	initialisation(carte);
	initPosPerso8();

	creerRoute8();
	
	voisinRoute();
	placerBatiment();
}



