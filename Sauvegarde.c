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
fclose(ficBus);
fclose(ficAmelio);

//Ecriture dans les fichiers lorsque l'on demande la commande "enregistrer"

//Pour la carte
int i, j;
for(i = 0; i < N; i++)
{
	for(j = 0; j < N; j++)
	{
		fscanf(ficCarte, "%i ", &idCase);
	}
}

//Pour le numéro du tour

int nbTour;
fscanf(ficTour, "%i", &nbTour);

//Pour les survivants

int j, hp, attaque, nb_materiaux, nb_soins, nb_vivres, arme, etat, deplacement, action, posX, posY;

for(j = 1; j <= N; j++)
{
	hp = surv[j].hp;
	attaque = surv[j].attaque;
	nb_materiaux = surv[j].nb_materiaux;
	nb_soins = surv[j].nb_soins;
	nb_vivres = surv[j].nb_vivres;
	arme = surv[j].arme;
	etat = surv[j].etat;
	deplacement = surv[j].deplacement;
	action = surv[j].action;
	posX = surv[j].posX;
	posY = surv[j].posY;
	
	fscanf(ficSurvivant, "%i ", &hp);
	fscanf(ficSurvivant, "%i ", &attaque);
	fscanf(ficSurvivant, "%i ", &nb_materiaux);
	fscanf(ficSurvivant, "%i ", &nb_soins);
	fscanf(ficSurvivant, "%i ", &nb_vivres);
	fscanf(ficSurvivant, "%i ", &arme);
	fscanf(ficSurvivant, "%i ", &etat);
	fscanf(ficSurvivant, "%i ", &deplacement);
	fscanf(ficSurvivant, "%i ", &action);
	fscanf(ficSurvivant, "%i ", &posX);
	fscanf(ficSurvivant, "%i ", &posY);
}

//Pour les zombies

int i, hp, attaque, etat, posX, posY;
for(i = 0; i < Z; i++)
{
	hp = zomb[i].hp;
	attaque = zomb[i].attaque;
	etat = zomb[i].etat;
	posX = zomb[i].posX;
	posY = zomb[i].posY;
	
	fscanf(ficZombie, "%i ", &hp);
	fscanf(ficZombie, "%i ", &attaque);
	fscanf(ficZombie, "%i ", &etat);
	fscanf(ficZombie, "%i ", &posX);
	fscanf(ficZombie, "%i ", &posY);
}

//Pour l'inventaire

int materiaux, vivre, soin;

fscanf(ficInventaire, "%i ", &materiaux);
fscanf(ficInventaire, "%i ", &vivre);
fscanf(ficInventaire, "%i ", &soin);

//Pour le bus et les améliorations


int hp_bus, entrepot_bus, survivant_max_bus, consoV_bus, consoS_bus, barr_bus, pareB_bus, blind_bus, infirm_bus, cuisine_bus, couch_bus, entrepot_bus;

hp_bus = bus.hp;
entrepot_bus = bus.entrepot;
survivant_max_bus = bus.survivant_max;
consoV_bus = bus.consoV;
consoS_bus = bus.consoS;
barr_bus = modif.barr;
pareB_bus = modif.pareB;
blind_bus = modif.blind;
infirm_bus = modif.infirm;
cuisine_bus = modif.cuisine;
couch_bus = modif.couch;
modif_entrepot_bus = modif.entrepot;

fscanf(ficBus, "%i ", hp_bus);
fscanf(ficBus, "%i ", entrepot_bus);
fscanf(ficBus, "%i ", survivant_max_bus);
fscanf(ficBus, "%i ", consoV_bus);
fscanf(ficBus, "%i ", consoS_bus);
fscanf(ficBus, "%i ", barr_bus);
fscanf(ficBus, "%i ", pareB_bus);
fscanf(ficBus, "%i ", blind_bus);
fscanf(ficBus, "%i ", infirm_bus);
fscanf(ficBus, "%i ", cuisine_bus);
fscanf(ficBus, "%i ", couch_bus);
fscanf(ficBus, "%i ", modif_entrepot_bus);


//Lecture dans les fichiers lorsque l'on demande la commande "charger la partie"

//Pour la carte



//Pour le numéro du tour



//Pour les survivants



//Pour les zombies



//Pour l'inventaire



//Pour le bus



//Pour les améliorations



