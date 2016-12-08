#include "Outilcpy.h"
#include "bibliotheque.h"

int mat[T][T];
int carte[T][T];

char batiment;


void initialisation(int mat[T][T])//Initialisation de la matrice
{
	int i;
	int j;
	for(i=0;i<T;i++){
		for(j=0;j<T;j++){
			mat[i][j] = 0;
		}
	}

}

char batiAlea()//Batiment aleatoire
{
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
	switch(nb)
	{
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


void voisinRoute(){
//Cherche les cases voisines d'une route
	int i;
	int j;
	int voisinR = 2;
	for(i=0;i<T;i++){
		for(j=0;j<T;j++){
			if(mat[i][j] == 1){
				if(j-1 >= 0)
					if(mat[i][j-1] == 0)
						mat[i][j-1] = voisinR;
				if(j+1 < T)
					if(mat[i][j+1] == 0)
						mat[i][j+1] = voisinR;
				if(i-1 >=0)
					if(mat[i-1][j] == 0)
						mat[i-1][j] = voisinR;
				if(i+1 < T)
					if(mat[i+1][j] == 0)
						mat[i+1][j] = voisinR;
			}
		}
	}
}

void placerBatiment()//Affichage carte
{	
	//int compteurM = 0; //compteur de maisons
	int compteurR = 0; //compteur de restaurants
	int compteurClinique = 0; //compteur de cliniques
	int compteurU = 0; //compteur d'usines
	int compteurE = 0; //compteur d'epiceries
	int compteurC = 0; //compteur de champs
	int compteurG = 0; //compteur de garages
	int compteurtotal;

	

	int i;
	int j;
	for(i=0;i<T;i++)
	{
		compteurtotal = 0;
		for(j=0;j<T;j++)
		{
			if(mat[i][j] == 1)
			{ 
			//Affichage de la route
				Assert1("probleme matrice route",mat[i][j]==1);
				carte[i][j] = 1;				
			}
			else if(mat[i][j] == 2)
			{
			//Initialisation des bâtiments speciaux
				Assert1("probleme matrice batiment",mat[i][j]==2);
				batiment = batiAlea();

				if((batiment == 'R') && (compteurR == 0) && (compteurtotal == 0))
				{
					compteurR ++;
					compteurtotal++;
					carte[i][j] = 3;					
				}
				else if((batiment == '+') && (compteurClinique == 0) && (compteurtotal == 0))
				{
					compteurClinique ++;
					compteurtotal++;
					carte[i][j] = 4;					
				} 
				else if((batiment == 'U') && (compteurU == 0) && (compteurtotal == 0))
				{
					compteurU ++;
					compteurtotal++;
					carte[i][j] = 5;					
				}
				else if((batiment == 'E') && (compteurE == 0) && (compteurtotal == 0))
				{
					compteurE ++;
					compteurtotal++;
					carte[i][j] = 6;					
				}
				else if((batiment == 'C') && (compteurC == 0) && (compteurtotal == 0))
				{
					compteurC ++;
					compteurtotal++;
					carte[i][j] = 7;					
				}
				else if((batiment == 'G') && (compteurG == 0) && (compteurtotal == 0))
				{
					compteurG ++;
					compteurtotal++;
					carte[i][j] = 8;					
				}
				else if(batiment == '.')
					carte[i][j] = 0;
					
					else
						carte[i][j] = 2;			
			}	
		
			else{ // Lorsque mat[i][j] == 0
				Assert2("probleme matrice autre",mat[i][j] !=1, mat[i][j] !=2);
			}
		}
	}
}


void afficherPerso()
{
	for(int i=1; i<N; i++)
	{
		if(surv[i].etat != 1)
		{
			carte[surv[i].posX][surv[i].posY] = 9;
		}
	}
}

void afficherCarte()
{
	int i,j;
	
	char maison = 'M';
	char restaurant = 'R'; 
	char clinique = '+'; 
	char usine = 'U'; 
	char epicerie = 'E'; 
	char champs = 'C'; 
	char garage = 'G'; 
	char rien = '.';
	char route = '#';
	char survivant = 'S';
	char zombie = 'Z';
	
	afficherPerso();	
		
	for(i=0;i<T;i++){
		for(j=0;j<T;j++){
			if(carte[i][j] == 0)
				printf("\033[0m%c  ", rien);
			if(carte[i][j] == 1)
				printf("\033[31m%c  ", route);
			if(carte[i][j] == 2)
				printf("\033[0m%c  ", maison);
			if(carte[i][j] == 3)
				printf("\033[0m%c  ", restaurant);
			if(carte[i][j] == 4)
				printf("\033[0m%c  ", clinique);
			if(carte[i][j] == 5)
				printf("\033[0m%c  ", usine);
			if(carte[i][j] == 6)
				printf("\033[0m%c  ", epicerie);
			if(carte[i][j] == 7)
				printf("\033[0m%c  ", champs);
			if(carte[i][j] == 8)
				printf("\033[0m%c  ", garage);
			if(carte[i][j] == 9)
				printf("\033[34m%c  ", survivant);
			if(carte[i][j] == 10)
				printf("\033[0m%c  ", zombie);
		}
		Ligne();
		Ligne();
	}
	printf("\033[0m");
}

int verifierRoute(int x, int y)
{
	Assert1("Probleme parametre verifierRoute", x==surv[1].posX+1);
	if(carte[x][y] == 1 ||carte[x][y] == 9)
	{
		return 1;
		Assert1("Probleme if verifier route", carte[x][y] == 1);
	}
	else
		return 0;
}
