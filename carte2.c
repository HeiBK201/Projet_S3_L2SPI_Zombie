#include "Outil.h"
#include "CreaCarte.h"

int mat[T][T];
int carte[T][T];

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

void initPosPerso2()
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


void carte2()
{
	initialisation(mat);
	initialisation(carte);
	initPosPerso2();

	creerRoute2();

	voisinRoute();
	placerBatiment();
}


