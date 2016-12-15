#include "Outilcpy.h"
#include "bibliotheque.h"
#include "evenement.h"


//Initialisation du bus
void defStructBus()
{
	//Initialisation des caractéristiques
	bus.hp = 250;
	bus.entrepot = 200;
	bus.survivant_max = 10;
	bus.consoV = 5;
	bus.consoS = 5;

	//Initialisation de l'inventaire
	inventaire.materiaux = 200;
	inventaire.vivre = 100;
	inventaire.soin = 100;
	
	//Initialisation des amelioration du bus
	modif.barr = 0;
	modif.pareB = 0;
	modif.blind = 0;
	modif.infirm = 0;
	modif.cuisine = 0;
	modif.couch = 0;
	modif.entrepot = 0;

}

//Affichage des caractéristiques du bus
void afficher()
{
	printf("\nBus\nVie : %i\nDégâts : %i\nLimites ressources : %i\nLimites survivants : %i\nVivre par tour : %i\nSoin par tour : %i\n",
		bus.hp, bus.degat, bus.entrepot, bus.survivant_max, bus.consoV, bus.consoS);
}

//Amélioration du bus
void ameliorer()
{
	int choix;
	
	 printf(" 1 - Barricade\n");
	 printf(" 2 - Pare-buffle\n");
	 printf(" 3 - Blindage\n");
	 printf(" 4 - Infirmerie\n");
	 printf(" 5 - Cuisine\n");
	 printf(" 6 - Couchette\n");
	 printf(" 7 - Entrepôt\n");
	 printf(" 8 - Quitter\n");
	 
	do
	{
		printf("Choix de la construction : ");
		scanf("%i", &choix);
	
		switch(choix)
		{
			case 1:
				if(inventaire.materiaux >= 50 && modif.barr == 0)
				{
					bus.hp += 150; 
					bus.degat += 15;
					inventaire.materiaux -= 50;
					modif.barr++;
					printf("La barrière à été construite\n");
				}
				else
					erreur(50);
				break;
				
			case 2: 
				if(inventaire.materiaux >= 120 && modif.pareB == 0)
				{
					bus.degat += 35;
					inventaire.materiaux -= 120;
					modif.pareB ++;
					printf("Le pare-buffle à été construit\n");
				}					 
				else
					erreur(120);
				break;
				
			 
			case 3: 
				if(inventaire.materiaux >= 300 && modif.blind == 0)
				{
					bus.hp += 500;
					inventaire.materiaux -= 300;
					modif.blind ++;
					printf("Le blindage à été construit\n");
				}					
				else
					erreur(300);
				break;
			 
			case 4: 
			 	if(inventaire.materiaux >= 250 && modif.infirm == 0)
				{
					bus.consoV -= 2;
					inventaire.materiaux -= 250;
					modif.infirm ++;
					printf("L'infirmerie à été construite\n");
			 	}
			 	else
					erreur(250);
			 	break;
			 	
			case 5: 
				if(inventaire.materiaux >= 250 && modif.cuisine == 0)
				{
					bus.consoS -= 2;
					inventaire.materiaux -= 250;
					modif.cuisine ++;
					printf("La cuisine à été construite\n");
			 	}
			 	else
					erreur(250);
			 	break;
			 	
			case 6: 
				if(inventaire.materiaux >= 250 && modif.couch == 0)
				{
					bus.survivant_max += 10;
					inventaire.materiaux -= 250;
					modif.couch ++;
					printf("Les couchettes ont été construites\n");
				}
				else
					erreur(250);
				break;
			 
			case 7: 
				if(inventaire.materiaux >= 100 && modif.entrepot == 0)
				{
					bus.entrepot += 300;
					inventaire.materiaux -= 100;
					modif.entrepot ++;
					printf("L'entrepôt à été construit\n");
				}
				else
					erreur(100);
				break;
			case 8: break;
			 
			default : printf("Choix invalide\n");
		}
	}
	while(choix<8);
}