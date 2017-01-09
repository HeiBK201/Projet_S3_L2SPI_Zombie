#include "Outil.h"
#include "bibliotheque.h"


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

/*Initialisation*/
	int x
	int y;

	int nbTour;

	int j; 
	int hp_surv[j];
	int attaque_surv[j];
	int nb_materiaux_surv[j];
	int nb_soins_surv[j];
	int nb_vivres_surv[j];
	int arme_surv[j];
	int etat_surv[j];
	int deplacement_surv[j];
	int action_surv[j];
	int posX_surv[j];
	int posY_surv[j];

	int i;
	int hp_zombie[i];
	int attaque_zombie[i];
	int etat_zombie[i];
	int posX_zombie[i];
	int posY_zombie[i];
	
	int hp_bus = bus.hp;
	int entrepot_bus = bus.entrepot;
	int survivant_max_bus = bus.survivant_max;
	int consoV_bus = bus.consoV;
	int consoS_bus = bus.consoS;
	int barr_bus = modif.barr;
	int pareB_bus = modif.pareB;
	int blind_bus = modif.blind;
	int infirm_bus = modif.infirm;
	int cuisine_bus = modif.cuisine;
	int couch_bus = modif.couch;
	int modif_entrepot_bus = modif.entrepot;


void initFichier()
{

	FILE * ficCarte;
	FILE * ficTour;
	FILE * ficSurvivant;
	FILE * ficZombie;
	FILE * ficInventaire;
	FILE * ficBus;
	FILE * ficAmelio;
}

void fichiersEnregistrer()
{

	//Pour enregistrer les données
	ficCarte = fopen("carte.txt", "w");
	ficTour = fopen("tour.txt", "w");
	ficSurvivant = fopen("survivant.txt", "w");
	ficZombie = fopen("zombie.txt", "w");
	ficInventaire = fopen("inventaire.txt", "w");
	ficBus = fopen("bus.txt", "w");
	ficAmelio = fopen("amelioration.txt", "w");
}

void fichiersCharger()
//Pour extraire les données
	ficCarte = fopen("carte.txt", "r");
	ficTour = fopen("tour.txt", "r");
	ficSurvivant = fopen("survivant.txt", "r");
	ficZombie = fopen("zombie.txt", "r");
	ficInventaire = fopen("inventaire.txt", "r");
	ficBus = fopen("bus.txt", "r");
	ficAmelio = fopen("amelioration.txt", "r");
	
 void fermerFichiers()
 {
	//Fermeture des fichiers
	fclose(ficCarte);
	fclose(ficTour);
	fclose(ficSurvivant);
	fclose(ficZombie);
	fclose(ficInventaire);
	fclose(ficBus);
	fclose(ficAmelio);
 }
	 
//Ecriture dans les fichiers lorsque l'on demande la commande "enregistrer"


void enregistrerPartie()
{		
	
	//Pour la carte
	
	for(x = 0; x < N; x++)
	{
		for(y = 0; y < N; y++)
		{
			
			fscanf(ficCarte, "%i ", &idCase);
		}
	}

	//Pour le numéro du tour

	fscanf(ficTour, "%i", &nbTour);

	//Pour les survivants

	for(j = 1; j <= N; j++)
	{
		hp_surv[j] = surv[j].hp;
		attaque_surv[j] = surv[j].attaque;
		nb_materiaux_surv[j] = surv[j].nb_materiaux;
		nb_soins_surv[j] = surv[j].nb_soins;
		nb_vivres_surv[j] = surv[j].nb_vivres;
		arme_surv[j] = surv[j].arme;
		etat_surv[j] = surv[j].etat;
		deplacement_surv[j] = surv[j].deplacement;
		action_surv[j] = surv[j].action;
		posX_surv[j] = surv[j].posX;
		posY_surv[j] = surv[j].posY;

		fscanf(ficSurvivant, "%i %i %i %i %i %i %i %i %i %i %i", &hp_surv[j], &attaque_surv[j], &nb_materiaux_surv[j], &nb_soins_surv[j], &nb_vivres_surv[j], &arme_surv[j], &etat_surv[j], &deplacement_surv[j], &action_surv[j], &posX_surv[j], &posY_surv[j]);
	}

	

	//Pour les zombies
	
	for(i = 0; i < Z; i++)
	{
		hp_zombie[i] = zomb[i].hp;
		attaque_zombie[i] = zomb[i].attaque;
		etat_zombie[i] = zomb[i].etat;
		posX_zombie[i] = zomb[i].posX;
		posY_zombie[i] = zomb[i].posY;

		fscanf(ficZombie, "%i %i %i %i %i", &hp_zombie[i], &attaque_zombie[i], &etat_zombie[i], &posX_zombie[i], &posY_zombie[i]);
	}

	//Pour l'inventaire

	int materiaux, vivre, soin;

	fscanf(ficInventaire, "%i ", &materiaux);
	fscanf(ficInventaire, "%i ", &vivre);
	fscanf(ficInventaire, "%i ", &soin);
	
	
	
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


	
}
//Lecture dans les fichiers lorsque l'on demande la commande "charger la partie"


	
//Pour la carte
void chargerPartie()
{
	/*Initialisation*/
	int i, j;
	int idCase
	
	/*Traitement*/
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			fprintf(ficCarte, "%i ", &idCase);
		}
	}


//Pour le numéro du tour



//Pour les survivants



//Pour les zombies



//Pour l'inventaire



//Pour le bus



//Pour les améliorations


}
