#include "Outil.h"
#include "CreaCarte.h"
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
	char route = '#';
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(mat[i][j] == 0)
				printf("\033[0m%c  ",rien);
			if(mat[i][j] == 1)
				printf("\033[31m%c  ",route);
			if(mat[i][j] == 2)
				printf("\033[0m%c  ",maison);
			if(mat[i][j] == 3)
				printf("\033[0m%c  ",restaurant);
			if(mat[i][j] == 4)
				printf("\033[0m%c  ",clinique);
			if(mat[i][j] == 5)
				printf("\033[0m%c  ",usine);
			if(mat[i][j] == 6)
				printf("\033[0m%c  ",epicerie);
			if(mat[i][j] == 7)
				printf("\033[0m%c  ",champs);
			if(mat[i][j] == 8)
				printf("\033[0m%c  ",garage);
		}
		Ligne();
		Ligne();
	}
}

