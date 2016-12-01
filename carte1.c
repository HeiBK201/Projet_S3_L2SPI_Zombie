#include "Outil.h"
#include "CreaCarte.h"
#define N 11

void creer_route(int mat[N][N]){
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
	//amorce tous les modules (code a  executer une fois pour toutes AVANT d'utiliser un quelconque module depuis le main)
	OutilAMORCER();//NE PAS DECLASSER:doit toujours etre appele en premier
	//amorcer TOUS les modules autres que Outil mentionnes dans les include de main.c

}//ModuleAmorceR

int main (int argc, const char * argv[]) {
	Appel0("");//NE PAS TOUCHER; ce code doit toujours etre place au debut du main
		ModuleAmorceR();//NE PAS TOUCHER; ce code doit toujours suivre immÃ©diatement Appel0("")
		main2();
	Appel1("");//NE PAS TOUCHER; ce code doit toujours etre place a la fin du main, juste avant le return()
    return 0;
}//main
