#include "Outilcpy.h"
#include "CreaCarte.h"

int mat[T][T];
int carte[T][T];


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


void carte9()
{
	initialisation(mat);
	initialisation(carte);

	creerRoute9();
	
	voisinRoute();
	placerBatiment();
}
