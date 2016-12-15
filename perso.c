#include "Outil.h"
#include "bibliotheque.h"


//Initialisation des personnages
void defStructPerso(int j)
{
	int i;
		
	//Initialisation de N survivant à ces variables suivantes
	surv[j].hp = 100;
	surv[j].attaque = 20;
	surv[j].nb_materiaux = 0;
	surv[j].nb_soins = 0;
	surv[j].nb_vivres = 0;
	surv[j].arme = 0;
	surv[j].etat = 1;
	surv[j].deplacement = 5;
	surv[j].action = 1;
	surv[j].posX = 2;
	surv[j].posY = 3;
	 
	printf("%i", surv[j].deplacement);
	 	 			 	
	for(i=0; i<Z; i++)
	{
		//Initialisation de Z zombies à ces variables suivantes
		zomb[i].hp = 100;
		zomb[i].attaque = 5;
		zomb[i].etat = 1;
		
	}
}



void afficherInfoPerso(int i)
{
	//Affichage des informations du survivant choisit
	
	if(i == 0)
	{
		printf("Survivant à regarder : ");
		scanf("%i", &i);
	}
	
	printf("Vie : %i\nAttaque : %i\nNombre de matériaux : %i\nNombre de médicament : %i\nNombre de vivre : %i\nArme : %i\nEtat : %i",
		surv[i].hp, surv[i].attaque, surv[i].nb_materiaux, surv[i].nb_soins, surv[i].nb_vivres, surv[i].arme, surv[i].etat);
}


void changerPerso()
{
	//Changement des variables du survivant choisit
	
	int choix;
	int j;
	
	int i;
	printf("Survivant à modifier : ");
	scanf("%i", &i);
	
	do
	{	
		printf("\nMenu :\n");
		printf(" 1 - Changement de la vie\n");
		printf(" 2 - Changement de l'attaque\n");
		printf(" 3 - Changement du nombre de matériaux\n");
		printf(" 4 - Changement du nombre de soins\n");
		printf(" 5 - Changement du nombre de vivre\n");
		printf(" 6 - Changement de l'arme\n");
		printf(" 7 - Quitter\n");
		printf("Votre choix : ");
		scanf("%d",&choix);
	
// Traitement du choix de l'utilisateur 
		switch(choix)
		{	
			
			case 1: 
					printf("Vie du survivant %i : ", i);
					scanf("%i", &j);
					surv[i].hp = j;
					afficherInfoPerso(i);
					break;
			case 2:
					printf("Attaque du survivant %i : ", i);
					scanf("%i", &j);
					surv[i].attaque = j;
					afficherInfoPerso(i);								
					break;
			case 3: 
					printf("Nombre de matériaux du survivant %i : ", i);
					scanf("%i", &j);
					surv[i].nb_materiaux = j;
					afficherInfoPerso(i);								
					break;
			case 4: 
					printf("Nombre de médicament du survivant %i : ", i);
					scanf("%i", &j);
					surv[i].nb_soins = j;	
					afficherInfoPerso(i);							
					break;
			case 5: 
					printf("Nombre de vivre du survivant %i : ", i);
					scanf("%i", &j);
					surv[i].nb_vivres = j;	
					afficherInfoPerso(i);							
					break;
			case 6: 
					printf("Arme du survivant %i : ", i);
					scanf("%i", &j);
					surv[i].arme = j;
					afficherInfoPerso(i);
					break;
			case 7: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 7\n");
		}
	}
	while(choix<7);
}

void dev()
{
	
	int choix;
	
	// Affichage du menu et saisie du choix 
	do
	{	
		printf("\nMenu :\n");
		printf(" 1 - Afficher un Survivant\n");
		printf(" 2 - Modifier un Survivant\n");
		printf(" 3 - \n");
		printf(" 4 - \n");
		printf(" 5 - Quitter\n");
		printf("Votre choix : ");
		scanf("%d",&choix);
	
// Traitement du choix de l'utilisateur 
		switch(choix)
		{	
			case 1: afficherInfoPerso(0); break;
			case 2: changerPerso(); break;
			case 3: ; break;
			case 4: ; break;
			case 5: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 5\n");
		}
	}
	while(choix<5);
		printf("Au revoir !\n");
	
}

