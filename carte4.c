#include "Outilcpy.h"
#include "CreaCarte.h"

int mat[T][T];
int carte[T][T];

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

void carte4()
{
	initialisation(mat);
	initialisation(carte);

	creerRoute4();

	voisinRoute();
	placerBatiment();
}
