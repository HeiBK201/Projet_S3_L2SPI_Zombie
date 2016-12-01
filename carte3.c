#include "Outil.h"
#include "CreaCarte.h"
#define N 11


void creer_route3(int mat[N][N]){
	int i;
	int j;
	char test = 'X';
	char centre = '.';
	

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

void carte3(){
	int mat[N][N];
	srand(time(NULL));
	initialisation_mat(mat);

	creer_route3(mat);

	voisin_route(mat);
	Placement_Batiment(mat);
	
	affichage_carte(mat);
}
