#include "Outil.h"

#define N 11


void initialisation_mat(int mat[N][N]){
//Initialisation de la matrice
	int i;
	int j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			mat[i][j] = 0;
		}
	}
}

char bati_alea(){
//Batiment aleatoire
	int nb;
	char maison = 'M'; // taille 1
	char restaurant = 'R'; // taille 4
	char clinique = '+'; // taille 4
	char usine = 'U'; //taille 6
	char epicerie = 'E'; //taille 2
	char champs = 'C'; // taille 4 ou 6
	char garage = 'G'; // taille 4
	char rien = '.';
	char batiment;
	

	nb = uHasard(10);
	switch(nb){
		case 1:batiment = maison;break;
		case 2:batiment = restaurant;break;
		case 3:batiment = clinique;break;
		case 4:batiment = usine;break;
		case 5:batiment = epicerie;break;
		case 6:batiment = champs;break;
		case 7:batiment = garage;break;
		default: batiment = rien;
	}
	return batiment;
}


void voisin_route(int mat[N][N]){
//Cherche les cases voisines d'une route
	int i;
	int j;
	int voisinR = 2;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(mat[i][j] == 1){
				if(j-1 >= 0)
					if(mat[i][j-1] == 0)
						mat[i][j-1] = voisinR;
				if(j+1 < N)
					if(mat[i][j+1] == 0)
						mat[i][j+1] = voisinR;
				if(i-1 >=0)
					if(mat[i-1][j] == 0)
						mat[i-1][j] = voisinR;
				if(i+1 < N)
					if(mat[i+1][j] == 0)
						mat[i+1][j] = voisinR;
			}
		}
	}
}

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

void Placement_Batiment(int mat[N][N]){	
//Affichage carte
	//int compteurM = 0; //compteur de maisons
	int compteurR = 0; //compteur de restaurants
	int compteurClinique = 0; //compteur de cliniques
	int compteurU = 0; //compteur d'usines
	int compteurE = 0; //compteur d'epiceries
	int compteurC = 0; //compteur de champs
	int compteurG = 0; //compteur de garages
	int compteurtotal;
	int compteurCase = 0;

	char route = 'X';
	char reste = '.';
	char batiment;
	char maison = 'M';

	int i;
	int j;
	int m; // Incrementation boucle
	int n; // Incrementation boucle
	for(i=0;i<N;i++){
		compteurtotal = 0;
		for(j=0;j<N;j++){
			if(mat[i][j] == 1){ 
			//Affichage de la route
				Assert1("probleme matrice route",mat[i][j]==1);		
			}
			else if(mat[i][j] == 2){
			//Affichage des batiments
				Assert1("probleme matrice batiment",mat[i][j]==2);
				batiment = bati_alea();


				if((batiment == 'R') && (compteurR == 0) && (compteurtotal == 0)){
					compteurR ++;
					compteurtotal++;
					mat[i][j] = 3;	
				}
				else if((batiment == '+') && (compteurClinique == 0) && (compteurtotal == 0)){
					compteurClinique ++;
					compteurtotal++;
					mat[i][j] = 4;
					
				} 
				else if((batiment == 'U') && (compteurU == 0) && (compteurtotal == 0)){
					compteurU ++;
					compteurtotal++;
					mat[i][j] = 5;
					
				}
				else if((batiment == 'E') && (compteurE <= 1) && (compteurtotal == 0)){
					compteurE ++;
					compteurtotal++;	
					mat[i][j] = 6;
					
				}
				else if((batiment == 'C') && (compteurC <= 2) && (compteurtotal == 0)){
					compteurC ++;
					compteurtotal++;
					mat[i][j] = 7;
					
				}
				else if((batiment == 'G') && (compteurG == 0) && (compteurtotal == 0)){
					compteurG ++;
					compteurtotal++;
					mat[i][j] = 8;
					
				}
				
			
				else if(batiment == '.'){
					mat[i][j] = 0;
				}
			}	
		
			else{ // Lorsque mat[i][j] == 0
				Assert2("probleme matrice autre",mat[i][j] !=1, mat[i][j] !=2);
			}
		}	
	}
	
}
void affichage_carte(int mat[N][N]){
	int i;
	int j;
	
	char maison = 'M';
	char restaurant = 'R'; 
	char clinique = '+'; 
	char usine = 'U'; 
	char epicerie = 'E'; 
	char champs = 'C'; 
	char garage = 'G'; 
	char rien = '.';
	char route = 'X';
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(mat[i][j] == 0)
				printf("%c  ",rien);
			if(mat[i][j] == 1)
				printf("%c%c ",route, route);
			if(mat[i][j] == 2)
				printf("%c  ",maison);
			if(mat[i][j] == 3)
				printf("%c  ",restaurant);
			if(mat[i][j] == 4)
				printf("%c  ",clinique);
			if(mat[i][j] == 5)
				printf("%c  ",usine);
			if(mat[i][j] == 6)
				printf("%c  ",epicerie);
			if(mat[i][j] == 7)
				printf("%c  ",champs);
			if(mat[i][j] == 8)
				printf("%c  ",garage);
		}
		Ligne();
		Ligne();
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
