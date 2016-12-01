#include "Outil.h"
#include "CreaCarte.h"
#define N 11


void creer_route(int mat[N][N]){
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

void main2(){
	int mat[N][N];
	srand(time(NULL));
	initialisation_mat(mat);

	creer_route(mat);

	voisin_route(mat);
	Placement_Batiment(mat);
	
	affichage_carte(mat);
}


void ModuleAmorceR(){
	//amorce tous les modules (code à exécuter une fois pour toutes AVANT d'utiliser un quelconque module depuis le main)
	OutilAMORCER();//NE PAS DECLASSER:doit toujours être appelé en premier
	//amorcer TOUS les modules autres que Outil mentionnés dans les include de main.c

}//ModuleAmorceR

int main (int argc, const char * argv[]) {
	Appel0("");//NE PAS TOUCHER; ce code doit toujours être placé au début du main
		ModuleAmorceR();//NE PAS TOUCHER; ce code doit toujours suivre immédiatement Appel0("")
		main2();
	Appel1("");//NE PAS TOUCHER; ce code doit toujours être placé à la fin du main, juste avant le return()
    return 0;
}//main
