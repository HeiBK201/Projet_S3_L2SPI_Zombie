#include "Outil.h"

// Liste de éléments à sauvegarder
/*
Carte actuelle
Nombre tours
Nombre survivants
Informations survivants
Informations ressources
Informations zombies
Informations bus

Enregistrement dans des fichier txt
*/

//taille compté à partie de 1

//fichier carte.txt
int carte[i][j]; //taille 12 12

//fichier tour.txt
int tour;

//fichier survivant.txt
int survivant[i][j]; //taille 20 7

//fichier zombie.txt
int zombie[i][j]; //taille 50 2

//fichier inventaire.txt
int inventaire[i][j]; //taille 3 1

//fichier bus.txt
int bus[i][j]; //taille 6 1

//fichier amelioration.txt
int amelioration[i][j]; //taille 7 1


FILE * ficCarte;
FILE * ficTour;
FILE * ficSurvivant;
FILE * ficZombie;
FILE * ficInventaire;
FILE * ficBus;
FILE * ficAmelio;


//Pour enregistrer les données
ficCarte = fopen("carte.txt", "w");
ficTour = fopen("tour.txt", "w");
ficSurvivant = fopen("survivant.txt", "w");
ficZombie = fopen("zombie.txt", "w");
ficInventaire = fopen("inventaire.txt", "w");
ficBus = fopen("bus.txt", "w");
ficAmelio = fopen("amelioration.txt", "w");

//Pour extraire les données
ficCarte = fopen("carte.txt", "r");
ficTour = fopen("tour.txt", "r");
ficSurvivant = fopen("survivant.txt", "r");
ficZombie = fopen("zombie.txt", "r");
ficInventaire = fopen("inventaire.txt", "r");
ficBus = fopen("bus.txt", "r");
ficAmelio = fopen("amelioration.txt", "r");

//Fermeture des fichiers
fclose(ficCarte);
fclose(ficTour);
fclose(ficSurvivant);
fclose(ficZombie);
fclose(ficInventaire);
fclose(ficbus);
fclose(ficAmelio);

//Ecriture dans les fichiers lorsque l'on demande la commande "enregistrer"

//Pour la carte
int i, j;
for(i = 0; i < N; i++)
{
	for(j = 0; j < N; j++)
	{
		fscanf(ficCarte, "%i", &idCase);
	}
}

//Pour le numéro du tour

//Pour les survivants

//Pour les zombies

//Pour l'inventaire

//Pour le bus

//Pour les améliorations


//Lecture dans les fichiers lorsque l'on demande la commande "charger la partie"

//Pour la carte

//Pour le numéro du tour

//Pour les survivants

//Pour les zombies

//Pour l'inventaire

//Pour le bus

//Pour les améliorations



