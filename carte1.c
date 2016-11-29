#include "Outilcpy.h"

#define N 11

int mat[N][N];

void initialisation_mat()//Initialisation de la matrice
{
	int i;
	int j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			mat[i][j] = 0;
		}
	}
}

char bati_alea()//Batiment aleatoire
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


void voisin_route()//Cherche les cases voisines d'une route
{
	int i;
	int j;
	int voisinR = 2;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(mat[i][j] == 1)
			{
				//if(bCroit(0,i-1,N-1)&&
				if(i-1 >=0 && j-1 >= 0)
					if(mat[i-1][j-1] == 0)
						mat[i-1][j-1] = voisinR;
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
				if(i+1 < N && j-1 >= 0)
					if(mat[i+1][j-1] == 0)
						mat[i+1][j-1] = voisinR;
				if(i+1 < N && j+1 < N)
					if(mat[i+1][j+1] == 0)
						mat[i+1][j+1] = voisinR;
				if(i-1 >=0 && j+1 < N)
					if(mat[i-1][j+1] == 0)
						mat[i-1][j+1] = voisinR;
			}
		}
	}
}

void creer_route()//Creation des routes
{
	int i;
	int j;

	
//routes verticales de gauche a  droite
	for(i=0;i<=9;i++)
	{
		j = 3;
		mat[i][j]=1;
	}
	for(i=4;i<=6;i++)
	{
		j=5;
		mat[i][j]=1;
	}		
	for(i=2;i<=4;i++)
	{
		j = 7;
		mat[i][j]=1;
	}
	for(i=6;i<=8;i++)
	{
		j = 7;
		mat[i][j]=1;
	}
	for(i=2;i<=10;i++)
	{
		j=9;
		mat[i][j]=1;
	}
	
//routes horizontales de haut en bas
	
	for(j=3;j<=10;j++)
	{
		i=2;
		mat[i][j] = 1;
	}
	mat[4][6]=1;
	for(j=0;j<=3;j++)
	{
		i=5;
		mat[i][j] = 1;
	}
	for(j=5;j<=9;j++)
	{
		i=6;
		mat[i][j] = 1;
	}
	for(j=3;j<=7;j++)
	{
		i=9;
		mat[i][j] = 1;
	}
}
	

void afficher_carte()//Affichage carte
{	
	//int compteurM = 0; //compteur de maisons
	int compteurR = 0; //compteur de restaurants
	int compteurClinique = 0; //compteur de cliniques
	int compteurU = 0; //compteur d'usines
	int compteurE = 0; //compteur d'epiceries
	int compteurC = 0; //compteur de champs
	int compteurG = 0; //compteur de garages
	int compteurtotal;

	char route = 'X';
	char reste = '.';
	char batiment;
	char maison = 'M';

	int i;
	int j;
	for(i=0;i<N;i++)
	{
		compteurtotal = 0;
		for(j=0;j<N;j++)
		{
			if(mat[i][j] == 1)
			{ 
			//Affichage de la route
				Assert1("probleme matrice route",mat[i][j]==1);
				printf("%c%c ",route,route);
				
			}
			else if(mat[i][j] == 2)
			{
			//Affichage des batiments
				Assert1("probleme matrice batiment",mat[i][j]==2);
				batiment = bati_alea();


				if((batiment == 'R') && (compteurR == 0) && (compteurtotal == 0))
				{
					compteurR ++;
					compteurtotal++;
					//printf("%c  ",batiment);
					mat[i][j] = 3;
					printf("%i  ", mat[i][j]);
				}
				else if((batiment == '+') && (compteurClinique == 0) && (compteurtotal == 0))
				{
					compteurClinique ++;
					compteurtotal++;
					//printf("%c  ",batiment);
					mat[i][j] = 4;
					printf("%i  ", mat[i][j]);
				} 
				else if((batiment == 'U') && (compteurU == 0) && (compteurtotal == 0))
				{
					compteurU ++;
					compteurtotal++;
					//printf("%c  ",batiment);
					mat[i][j] = 5;
					printf("%i  ", mat[i][j]);
				}
				else if((batiment == 'E') && (compteurE == 0) && (compteurtotal == 0))
				{
					compteurE ++;
					compteurtotal++;	
					//printf("%c  ",batiment);
					mat[i][j] = 6;
					printf("%i  ", mat[i][j]);
				}
				else if((batiment == 'C') && (compteurC == 0) && (compteurtotal == 0))
				{
					compteurC ++;
					compteurtotal++;
					//printf("%c  ",batiment);
					mat[i][j] = 7;
					printf("%i  ", mat[i][j]);
				}
				else if((batiment == 'G') && (compteurG == 0) && (compteurtotal == 0))
				{
					compteurG ++;
					compteurtotal++;
					//printf("%c  ",batiment);
					mat[i][j] = 8;
					printf("%i  ", mat[i][j]);
				}
				
			
				else if(batiment == '.'){
					printf("%c  ",batiment);
				}
				else{
					printf("%c  ",maison);	
				}
			
			}	
		
			else{ // Lorsque mat[i][j] == 0
				Assert2("probleme matrice autre",mat[i][j] !=1, mat[i][j] !=2);
				printf("%c  ", reste);
			}
		}
		Ligne();
		Ligne();
	}
	
}



void carte()
{
	int mat[N][N];
	//srand(time(NULL));
	initialisation_mat(mat);

	creer_route(mat);

	voisin_route(mat);
	afficher_carte(mat);
}
