#include "Outil.h"
#include "CreaCarte.h"

int mat[T][T];
int carte[T][T];

void creerRoute3()
{
//Creation des routes
	int i;
	int j;


//routes verticales de gauche à droite

	for(i=0;i<=2;i++){
		j=1;
		mat[i][j] = 1;
	}
	for(i=4;i<=6;i++){
		j=1;
		mat[i][j] = 1;
	}
	for(i=2;i<=4;i++){
		j=2;
		mat[i][j] = 1;
	}
	for(i=4;i<=6;i++){
		j=3;
		mat[i][j] = 1;
	}
	for(i=0;i<=4;i++){
		j=5;
		mat[i][j] = 1;
	}
	for(i=2;i<=10;i++){
		j=8;
		mat[i][j] = 1;
	}
	for(i=0;i<=2;i++){
		j=9;
		mat[i][j] = 1;
	}

	
//routes horizontales de haut en bas
	
	for(j=0;j<=10;j++){
		i = 4;
		mat[i][j]=1;
	}
	mat[6][2]=1;
	for(j=2;j<=8;j++){
		i=9;
		mat[i][j]=1;
	}

}

void initPosPerso3()
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


void carte3()
{
	initialisation(mat);
	initialisation(carte);
	initPosPerso3();

	creerRoute3();

	voisinRoute();
	placerBatiment();
}


