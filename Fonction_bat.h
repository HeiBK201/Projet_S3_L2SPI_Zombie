#include "Outil.h"

// Fonction qui va indiquer quel type de bâtiment il y a sur cette case
int batimentCase(int mat);

// Fonction qui va définir ce que l'on va trouver dans chaque bâtiments (juste le type pas la quantitée) en fonction du bâtiments
int typeRessourceBatiment(int batiment);

// Indique quelle ressource à été trouvé
int typeRessource(int ressource);

// Fonction qui retourne le nombre de ressources trouvé dans le bâtiment dont le type à été définie dans la fonction ressource_batiment
int nombreRessource(int nomRessource);

// Chance d'avoir tel ou tel type d'arme en fonction de sa catégorie
int chanceArme();

// Affiche l'arme obtenue
int afficherArme(int arme);

// Fonction qui indique si un bâtiment à été exploré ou non lorsque l'on selectionne un bâtiment
int fouillerBatiment(int statut);


