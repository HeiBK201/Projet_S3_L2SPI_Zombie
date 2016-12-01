#include "Outil.h"
#include "CreaCarte.h"
#define N 11


void creer_route4(int mat[N][N]){
	int i;
	int j;
	char test = 'X';
	char centre = '.';
	

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

void carte4(){
	int mat[N][N];
	srand(time(NULL));
	initialisation_mat(mat);

	creer_route4(mat);

	voisin_route(mat);
	Placement_Batiment(mat);
	
	affichage_carte(mat);
}
