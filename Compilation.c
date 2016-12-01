#include "Outil.h"

#define N 11

typedef enum {intact, vide}t_fouille_batiment; // Strcture énuméré pour définir si une maison à déjà été exploré ou non
typedef enum {massue = 0, machette, hache, epee, arc, arbalete, pistolet, mitraillette, sniper}t_arme; // Structure énuméré pour définir chaque type d'arme
typedef enum {vivre = 0, soin, materiaux, arme, survivant, rien}t_objet_a_trouver; // Structure énuméré pour définir chaque type d'objet
typedef enum {maison = 0, restaurant, clinique, usine, epicerie, champ, garage}t_type_batiment; // Structure énuméré pour définir chaque type de maison

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


// Fonction qui va indiquer quel type de bâtiment il y a sur cette case
int indicateur_case(int num_case)
{
	int id_case;
	Appel0("Indicateur case");
	switch(num_case)
	{
		case 2: id_case = maison;break;
		case 3: id_case = restaurant;break;
		case 4: id_case = clinique;break;
		case 5: id_case = usine;break;
		case 6: id_case = epicerie;break;
		case 7: id_case = champ;break;
		case 8: id_case = garage;break;
	}
	
	Appel1("Indicateur case");
	return id_case;
}

// Fonction qui va définir ce que l'on va trouver dans chaque bâtiments (juste le type pas la quantitée) en fonction du bâtiments
int type_ressource_batiment(int type_bat)
{
	char * tab_ressource[] = {"vivre", "soin", "materiaux", "arme", "survivant", "rien"};
	int tab_restaurant[2] = {vivre, survivant};
	int tab_clinique[2] = {soin, survivant};
	int tab_usine[3] = {materiaux, arme, survivant};
	int tab_epicerie[3] = {vivre, soin, survivant};
	int tab_champ[3] = {vivre, materiaux, survivant};
	int tab_garage[3] = {materiaux, arme, survivant};
	int ressource;
	Appel0("type_ressource_batiment");
	
	switch(type_bat)
	{
		case 0: printf("Vous rentrez dans une maison qui n'est pas encore explorée, exploration en cours...\n");
			ressource = nHasard(6);
			printf("Objet type: %i\n", ressource);
			break;
		case 1: printf("Vous rentrez dans un restaurant qui n'est pas encore explorée, exploration en cours...\n");
			ressource = tab_restaurant[nHasard(2)];
			printf("Objet type: %i\n", ressource);
			break;
		case 2: printf("Vous rentrez dans une clinique qui n'est pas encore exploré, exploration en cours...\n");
			ressource = tab_clinique[nHasard(2)];
			printf("Objet type: %i\n", ressource);
			break;
		case 3: printf("Vous rentrez dans une usine qui n'est pas encore explorée, exploration en cours...\n");
			ressource = tab_usine[nHasard(3)];
			printf("Objet type: %i\n", ressource);
			break;
		case 4: printf("Vous rentrez dans une épicerie qui n'est pas encore explorée, exploration en cours...\n");
			ressource = tab_epicerie[nHasard(3)];
			printf("Objet type: %i\n", ressource);
			break;
		case 5: printf("Vous rentrez dans un champ qui n'est pas encore exploré, exploration en cours...\n");
			ressource = tab_champ[nHasard(3)];
			printf("Objet type: %i\n", ressource);
			break;
		case 6: printf("Vous rentrez dans un garage qui n'est pas encore exploré, exploration en cours...\n");
			ressource = tab_garage[nHasard(3)];
			printf("Objet type: %i\n", ressource);
			break;
	}
	Appel1("type_ressource_batiment");
	return ressource;
}

// Indique quelle ressource à été trouvé
int ressource_trouve(int type_ressource)
{
	int nom_ressource;
	Appel0("Ressource trouvé(es)");
	switch(type_ressource)
	{
		case 0: printf("Ressource trouvé: Vivre\n");
			nom_ressource = vivre;
			break;
		case 1: printf("Ressource trouvé: Soin\n");
			nom_ressource = soin;
			break;
		case 2: printf("Ressource trouvé: Matériaux\n");
			nom_ressource = materiaux;
			break;
		case 3: printf("Ressource trouvé: Arme\n");
			nom_ressource = arme;
			break;
		case 4: printf("Ressource trouvé: Survivant\n");
			nom_ressource = survivant;
			break;
		case 5: printf("Ressource trouvé: Rien\n");
			nom_ressource = rien;
			break;
	}
	Appel1("Ressource trouvé(es)");
	return nom_ressource;
}

// Chance d'avoir tel ou tel type d'arme en fonction de sa catégorie
int chance_type_arme()
{
	int chance;
	int type_arme;
	Appel0("chance_type_arme");
	chance = nHasard(999);
	
	if (chance <= 249) // Machette
	{
		type_arme = 0;
	}
	else if ((chance >= 250) && (chance <= 449)) // Hache
	{
		type_arme = 1;
	}
	else if ((chance >= 450) && (chance <= 474)) // Epée
	{
		type_arme = 2;
	}
	else if ((chance >= 475) && (chance <= 724)) // Arc
	{
		type_arme = 3;
	}
	else if ((chance >= 725) && (chance <= 924)) // Arbalète
	{
		type_arme = 4;
	}
	else if ((chance  >= 925) && (chance <= 974)) // Pistolet
	{
		type_arme = 5;
	}
	else if ((chance >= 975) && (chance <= 998)) // Mitraillette
	{
		type_arme = 6;
	}
	else if (chance == 999) // Sniper
	{
		type_arme = 7;
	}

	Appel1("chance_type_arme");
	return type_arme;
}

// Affiche l'arme obtenue
int affiche_type_arme(int type_arme) 
{
	int arme;
	Appel0("Afficher arme");
	switch(type_arme)
	{
		case 0: printf("Arme Obtenue: Machette\n");
			arme = machette;
			break;
		case 1: printf("Arme Obtenue: Hache\n");
			arme = hache;
			break;
		case 2: printf("Arme Obtenue: Epée\n");
			arme = epee;
			break;
		case 3: printf("Arme Obtenue: Arc\n");
			arme = arc;
			break;
		case 4: printf("Arme Obtenue: Arbalète\n");
			arme = arbalete;
			break;
		case 5: printf("Arme Obtenue: Pistolet\n");
			arme = pistolet;
			break;
		case 6: printf("Arme Obtenue: Mitraillette\n");
			arme = mitraillette;
			break;
		case 7: printf("Arme Obtenue: Sniper\n");
			arme = sniper;
			break;
	
		}
	Appel1("Afficher arme");
	return arme;	
}

// Fonction qui indique si un bâtiment à été exploré ou non lorsque l'on selectionne un bâtiment
int fouille_batiment(int statut)
{
	Appel0("Fouille bâtiment");	
	switch(statut)
	{
		case 0: statut = intact;break;
		case 1: statut = vide;break;
	}
	
	Appel1("Fouille bâtiment");
	return statut;
}

void main2(){

	HasardInit();

	int mat[N][N];
	int num_case;
	int type_bat;
	int type_ressource;
	int nom_ressource;
	int type_arme;
	int arme;
	
	initialisation_mat(mat);
	creer_route(mat);
	voisin_route(mat);
	Placement_Batiment(mat);
	affichage_carte(mat);
	
	printf("num_case = ");
	scanf("%i", num_case);
	
	type_bat = indicateur_case(num_case);
	printf("type: %i\n", type_bat);
	type_ressource = type_ressource_batiment(type_bat);
	printf("type ressource: %i");
	nom_ressource = ressource_trouve(type_ressource);
	printf("nom ressource: %i", nom_ressource);
	
	if (nom_ressource == arme)
	{
		type_arme = chance_type_arme();
		arme = affiche_type_arme(type_arme);
	}
	
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
