/**
 \file Fonction_bat.c
 \brief Fonction liés aux bâtiments
 \author Alexandre SADONNET, Mehdi COHEN et Tristan BOUQUET
 \version 1.0
 \date 15 décembre 2015
*/

#include "Outil.h"
#include "perso.h"
#include "bibliotheque.h"

/**
 \fn void batimentCase(int idCase);
 \brief Fonction qui va indiquer quel type de bâtiment il y a sur cette case
*/

int batiment;
int ressource;
int nomRessource;
int nbRessource;
int armeTrouver;
int typeArme;
int idCase;
int n;
	
int batimentCase()
{
	/*Traitement*/
	while(infoBatiment[n].fouilleBat == 1)
	{
		n++;
	}
	infoBatiment[n].fouilleBat = 1;
	idCase = infoBatiment[n].typeBat;
	switch(idCase)
	{
		case 2: idCase = maison;break;
		case 3: idCase = restaurant;break;
		case 4: idCase = clinique;break;
		case 5: idCase = usine;break;
		case 6: idCase = epicerie;break;
		case 7: idCase = champ;break;
		case 8: idCase = garage;break;
	}
	

	
}

/**
 \fn void typeRessourceBatiment(int batiment);
 \brief Fonction qui va définir ce que l'on va trouver dans chaque bâtiments (juste le type pas la quantitée) en fonction du bâtiments
*/
int typeRessourceBatiment()
{
	/*Initialisation*/
	char * tab_ressource[] = {"vivre", "soin", "materiaux", "arme", "survivant", "rien"};
	int tab_restaurant[2] = {vivre, survivant};
	int tab_clinique[2] = {soin, survivant};
	int tab_usine[3] = {materiaux, arme, survivant};
	int tab_epicerie[3] = {vivre, soin, survivant};
	int tab_champ[3] = {vivre, materiaux, survivant};
	int tab_garage[3] = {materiaux, arme, survivant};
	int ressource;
	
	/*Traitement*/
	switch(batiment)
	{
		case 0: printf("Vous rentrez dans une maison qui n'est pas encore explorée, exploration en cours...\n");
			ressource = nHasard(6);
			printf("Objet type: %i\n", ressource);
			break;
		case 1: printf("Vous rentrez dans un restaurant qui n'est pas encore exploré, exploration en cours...\n");
			ressource = tab_restaurant[nHasard(2)];
			printf("Objet type: %i\n", ressource);
			break;
		case 2: printf("Vous rentrez dans une clinique qui n'est pas encore explorée, exploration en cours...\n");
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
}

/**
 \fn void typeRessource(int ressource);
 \brief Indique quelle ressource à été trouvé
*/
int typeRessource()
{
	/*Initialisation*/
	int nomRessource;
	
	/*Traitement*/
	switch(ressource)
	{
		case 0: printf("Ressource trouvé: Vivre\n");
			nomRessource = vivre;
			break;
		case 1: printf("Ressource trouvé: Soin\n");
			nomRessource = soin;
			break;
		case 2: printf("Ressource trouvé: Matériaux\n");
			nomRessource = materiaux;
			break;
		case 3: printf("Ressource trouvé: Arme\n");
			nomRessource = arme;
			break;
		case 4: printf("Ressource trouvé: Survivant\n");
			nomRessource = survivant;
			break;
		case 5: printf("Ressource trouvé: Rien\n");
			nomRessource = rien;
			break;
	}
}

/**
 \fn void nombreRessource(int nomRessource);
 \brief Fonction qui retourne le nombre de ressources trouvé dans le bâtiment dont le type à été définie dans la fonction ressource_batiment
*/
int nombreRessource()
{
	/*Initialisation*/
	int j;
	
	/*Traitement*/
	switch(nomRessource)
	{
		case 0: inventaire.vivre += 20;
				printf("20 vivres en plus\n");
				break;
		case 1: inventaire.soin += 20;
				printf("20 soins en plus\n");
				break;
		case 2: inventaire.materiaux += 10;
				printf("10 matériaux en plus\n");
				break;
		case 3: nbRessource = 1;break;
		case 4: for(j=1; j<N; j++)
				{
					if(surv[j].etat != 1)
					{
						defStructPerso(j);
						j=N;
					}
				}
				printf("1 survivant en plus\n");
		case 5: nbRessource = 0;break;
	}
}

/**
 \fn void chanceArme();
 \brief Chance d'avoir tel ou tel type d'arme en fonction de sa catégorie
*/
int chanceArme()
{
	/*Initialisation*/
	int chance;
	int arme;
	
	/*Traitement*/
	chance = nHasard(999);
	
	if (chance <= 249) // Machette
	{
		arme = 0;
	}
	else if ((chance >= 250) && (chance <= 449)) // Hache
	{
		arme = 1;
	}
	else if ((chance >= 450) && (chance <= 474)) // Epée
	{
		arme = 2;
	}
	else if ((chance >= 475) && (chance <= 724)) // Arc
	{
		arme = 3;
	}
	else if ((chance >= 725) && (chance <= 924)) // Arbalète
	{
		arme = 4;
	}
	else if ((chance  >= 925) && (chance <= 974)) // Pistolet
	{
		arme = 5;
	}
	else if ((chance >= 975) && (chance <= 998)) // Mitraillette
	{
		arme = 6;
	}
	else if (chance == 999) // Sniper
	{
		arme = 7;
	}
}

/**
 \fn void afficherArme(int arme);
 \brief Affiche l'arme obtenue
*/
int afficherArme() 
{
	/*Initialisation*/
	int typeArme;
	
	/*Traitement*/
	switch(arme)
	{
		case 0: printf("Arme Obtenue: Machette\n");
			inventArme.machette++;
			break;
		case 1: printf("Arme Obtenue: Hache\n");
			inventArme.hache++;
			break;
		case 2: printf("Arme Obtenue: Epée\n");
			inventArme.epee++;
			break;
		case 3: printf("Arme Obtenue: Arc\n");
			inventArme.arc++;
			break;
		case 4: printf("Arme Obtenue: Arbalète\n");
			inventArme.arbalete++;
			break;
		case 5: printf("Arme Obtenue: Pistolet\n");
			inventArme.pistolet++;
			break;
		case 6: printf("Arme Obtenue: Mitraillette\n");
			inventArme.mitraillette++;
			break;
		case 7: printf("Arme Obtenue: Sniper\n");
			inventArme.sniper++;
			break;
	
	}
		
}

void actionFouiller(int i, int j)
{
 
 	//HasardInit();
	srand(time(NULL));
	
	//type du batiment(2 à 8)
	batiment = batimentCase();
	ressource = typeRessourceBatiment();
	nomRessource = typeRessource();
	nbRessource = nombreRessource();
	if (nomRessource == 3)
	{
		typeArme = chanceArme();
		armeTrouver = afficherArme();
 	}
}
