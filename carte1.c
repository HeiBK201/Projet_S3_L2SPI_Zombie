#include "Outil.h"
#include "CreaCarte.h"
#define N 11

void creer_route1(int mat[N][N]){
//Creation des routes
	int i;
	int j;

	
//routes verticales de gauche a  droite
	for(i=0;i<=9;i++){
		j = 3;
		mat[i][j]=1;
	}
	for(i=4;i<=6;i++){
		j=5;
		mat[i][j]=1;
	}		
	for(i=2;i<=4;i++){
		j = 7;
		mat[i][j]=1;
	}
	for(i=6;i<=8;i++){
		j = 7;
		mat[i][j]=1;
	}
	for(i=2;i<=10;i++){
		j=9;
		mat[i][j]=1;
	}
	
//routes horizontales de haut en bas
	
	for(j=3;j<=10;j++){
		i=2;
		mat[i][j] = 1;
	}
	mat[4][6]=1;
	for(j=0;j<=3;j++){
		i=5;
		mat[i][j] = 1;
	}
	for(j=5;j<=9;j++){
		i=6;
		mat[i][j] = 1;
	}
	for(j=3;j<=7;j++){
		i=9;
		mat[i][j] = 1;
	}
}

void carte1(){
	int mat[N][N];
	srand(time(NULL));
	initialisation_mat(mat);

	creer_route1(mat);

	voisin_route(mat);
	Placement_Batiment(mat);
	
	affichage_carte(mat);
}
