/**
\file CreaCarte.c
\brief Initialisations, placement des bâtiments de façon aléatoire, affichage de la carte.
\author Sadonnet Alexandre, Cohen Mehdi & Bouquet Tristan
\version 1.0
\date 15/12/2016
*/

#include "Outil.h"
#include "bibliotheque.h"

int mat[T][T];
int carte[T][T];

char batiment;

/**
\fn void initialisation(int mat[T][T]);
\brief initialisation de la matrice
\param Matrice
*/
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

/**
\fn char batiAlea();
\brief Selection d'un caractère aléatoirement, représentant un bâtiment.
*/
char batiAlea()//Batiment aleatoire
{
	int nb;
	char maison = 'M';
	char restaurant = 'R';
	char clinique = '+'; 
	char usine = 'U';
	char epicerie = 'E'; 
	char champs = 'C'; 
	char garage = 'G';
	char rien = '.';
	char batiment;
	

	nb = uHasard(10);//Nombre aléatoire de 1 à 10 (8 a 10 représentant sur la carte des cases vides)
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

/**
\fn void voisinRoute();
\brief Détection des cases voisines aux routes en affectant une valeur à la matrice pour le placement des bâtiments
*/
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

/**
\fn void placerBatiment();
\brief Placement aléatoire des bâtiments
*/
void placerBatiment()//Affichage carte
{	
	//un batiment "spécial" par carte générée
	int compteurR = 0; //compteur de restaurants
	int compteurClinique = 0; //compteur de cliniques
	int compteurU = 0; //compteur d'usines
	int compteurE = 0; //compteur d'epiceries
	int compteurC = 0; //compteur de champs
	int compteurG = 0; //compteur de garages
	
	int compteurtotal; //compteur permettant de placer un batiment par ligne (permet une homogénéité de la carte)

	int i;
	int j;
	for(i=0;i<T;i++)
	{
		compteurtotal = 0;
		for(j=0;j<T;j++)
		{
			if(mat[i][j] == 1)
			{ 
			//Placement des routes
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
				Assert1("probleme matrice autre",mat[i][j] == 0);
			}
		}
	}
}

/**
\fn void afficherPerso();
\brief Renvoie la valeur des survivants dans la matrice carte
*/
void afficherPerso()
{
	for(int i=1; i<N; i++)
	{
		if(surv[i].etat == 1)
		{
			carte[surv[i].posX][surv[i].posY] = 9;
		}
	}
}

/**
\fn void afficherCarte();
\brief Affichage de la carte
*/
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
	
	system("clear");
	
	afficherPerso();	
		
	for(i=0;i<T;i++){
		printf("	");
		for(j=0;j<T;j++){
			if(carte[i][j] == 0)
				printf(" \033[0m%c ", rien);
			if(carte[i][j] == 1)
				printf(" \033[31m%c ", route);
			if(carte[i][j] == 2)
				printf(" \033[0m%c ", maison);
			if(carte[i][j] == 3)
				printf(" \033[0m%c ", restaurant);
			if(carte[i][j] == 4)
				printf(" \033[0m%c ", clinique);
			if(carte[i][j] == 5)
				printf(" \033[0m%c ", usine);
			if(carte[i][j] == 6)
				printf(" \033[0m%c ", epicerie);
			if(carte[i][j] == 7)
				printf(" \033[0m%c ", champs);
			if(carte[i][j] == 8)
				printf(" \033[0m%c ", garage);
			if(carte[i][j] == 9)
				printf(" \033[34m%c ", survivant);
			if(carte[i][j] == 10)
				printf(" \033[0m%c ", zombie);
		}
		Ligne();
		Ligne();
	}
	printf("\033[0m");
}

/**
\fn int verifierCarte(int x, int y);
\brief Vérifie si là où le joueur veut aller il y a bien une route, un bâtiment ou un survivant
*/
int verifierCarte(int x, int y)
{
	int i;
	//Cas si on cherche une route
	//Assert1("Probleme parametre verifierRoute", x==surv[1].posX+1);
	if(mat[x][y] == 1)//En utilisant la matrice mat on a uniquement les routes
	{
		/*Assert1("Probleme if verifier route", carte[x][y] == 1);*/
		return 1;	
	}
	//Cas si on cherche un batiment
	/*Assert1("Probleme carte > 1", carte[x][y] > 1);
	Assert1("Probleme carte < 10", carte[x][y] != 10);
	Assert1("Probleme mat = 0", mat[x][y] == 2);*/
	if(carte[x][y] == 9 && carte[x][y] == 1)
		return 1;
	if(carte[x][y] > 1 && carte[x][y] < 10 && mat[x][y] == 2)
	{
		for(i=0; i<Z; i++)
		{
			if(infoBatiment[i].posX == x && infoBatiment[i].posY == y)
			{
				return 1;
			}
		}
		for(i=0; i<Z; i++)
		{
			if(infoBatiment[i].fouilleBat == 0)
			{
				infoBatiment[i].posX = x;
				infoBatiment[i].posY = y;
				infoBatiment[i].typeBat = carte[x][y];
				return 3;
			}
		}		
	}		
}

/**
\fn void verifierPerso(int i);
\brief Vérifie s'il y a un personnage sur la même case qu'un autre, Affiche le bâtiment ou la route correspondant à la case après le depart du personnage
*/
void verifierPerso(int i)
{
	int j;
	int n = 0;
	for(j=0; j<N; j++)
	{
		//Vérifie s'il y a un survivant sur la même case et si c'est une route
		if(surv[j].posX != surv[i].posX && surv[j].posY != surv[i].posY && j != i && mat[surv[i].posX][surv[i].posY] == 1)
			carte[surv[i].posX][surv[i].posY] = 1;
		//Vérifie
		else
		{
			while(surv[i].posX != infoBatiment[n].posX && surv[i].posY != infoBatiment[n].posY)
			{
				n++;
			}
			if(mat[surv[i].posX][surv[i].posY] == 2)
				carte[surv[i].posX][surv[i].posY] = infoBatiment[n].typeBat;
			else
				carte[surv[i].posX][surv[i].posY] = 1;
		}			
	}
}
