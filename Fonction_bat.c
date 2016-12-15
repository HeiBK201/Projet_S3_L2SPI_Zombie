/**
 \file Fonction_bat.c
 \brief Fonction liés aux bâtiments
 \author Alexandre SADONNET, Mehdi COHEN et Tristan BOUQUET
 \version 1.0
 \date 15 décembre 2015
*/

#include "Outil.h"
#include "bibliotheque.h"

/**
 \fn void batimentCase(int idCase);
 \brief Fonction qui va indiquer quel type de bâtiment il y a sur cette case
*/
void batimentCase(int idCase)
{
	
	Appel0("Indicateur case");
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
	
	Appel1("Indicateur case");
	
}


/**
 \fn void typeRessourceBatiment(int batiment);
 \brief Fonction qui va définir ce que l'on va trouver dans chaque bâtiments (juste le type pas la quantitée) en fonction du bâtiments
*/
void typeRessourceBatiment(int batiment)
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
	Appel0("type ressource");
	
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
	Appel1("type ressource");
}

/**
 \fn void typeRessource(int ressource);
 \brief Indique quelle ressource à été trouvé
*/
void typeRessource(int ressource)
{
	/*Initialisation*/
	int nomRessource;
	Appel0("Ressource trouvé(es)");
	
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
	Appel1("Ressource trouvé(es)");
}

/**
 \fn void nombreRessource(int nomRessource);
 \brief Fonction qui retourne le nombre de ressources trouvé dans le bâtiment dont le type à été définie dans la fonction ressource_batiment
*/
void nombreRessource(int nomRessource)
{
	/*Initialisation*/
	int nbRessource;
	Appel0("nombre_ressource_trouve");
	
	/*Traitement*/
	switch(nomRessource)
	{
		case 0: nbRessource = 20;break;
		case 1: nbRessource = 20;break;
		case 2: nbRessource = 10;break;
		case 3: nbRessource = 1;break;
		case 4: nbRessource = 1;break;
		case 5: nbRessource = 0;break;
	}
	printf("Quantité: %i\n", nbRessource);
	Appel1("nombre_ressource_trouve");
}

/**
 \fn void chanceArme();
 \brief Chance d'avoir tel ou tel type d'arme en fonction de sa catégorie
*/
void chanceArme()
{
	/*Initialisation*/
	int chance;
	int arme;
	Appel0("chanceArme");
	
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

	Appel1("chance arme");
}

/**
 \fn void afficherArme(int arme);
 \brief Affiche l'arme obtenue
*/
void afficherArme(int arme) 
{
	/*Initialisation*/
	int typeArme;
	Appel0("Afficher arme");
	
	/*Traitement*/
	switch(arme)
	{
		case 0: printf("Arme Obtenue: Machette\n");
			typeArme = machette;
			break;
		case 1: printf("Arme Obtenue: Hache\n");
			typeArme = hache;
			break;
		case 2: printf("Arme Obtenue: Epée\n");
			typeArme = epee;
			break;
		case 3: printf("Arme Obtenue: Arc\n");
			typeArme = arc;
			break;
		case 4: printf("Arme Obtenue: Arbalète\n");
			typeArme = arbalete;
			break;
		case 5: printf("Arme Obtenue: Pistolet\n");
			typeArme = pistolet;
			break;
		case 6: printf("Arme Obtenue: Mitraillette\n");
			typeArme = mitraillette;
			break;
		case 7: printf("Arme Obtenue: Sniper\n");
			typeArme = sniper;
			break;
	
		}
	Appel1("Afficher arme");
		
}

/**
 \fn void fouillerBatiment(int statut);
 \brief Fonction qui indique si un bâtiment à été exploré ou non lorsque l'on selectionne un bâtiment
*/
void fouillerBatiment(int statut)
{
	Appel0("Fouille bâtiment");	
	
	/*Traitement*/
	switch(statut)
	{
		case 0: statut = intact;break;
		case 1: statut = vide;break;
	}
	
	Appel1("Fouille bâtiment");
	
}
