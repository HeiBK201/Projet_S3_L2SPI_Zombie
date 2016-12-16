/**
\file ChoixCarte.c
\brief Selection aléatoire d'une carte à générer
\author Sadonnet Alexandre, Cohen Mehdi & Bouquet Tristan
\version 1.0
\date 15/12/2016
*/

#include "Outil.h"

/**
\fn void choixCarte();
\brief Selection aléatoire d'une carte
*/
void choixCarte()
{
	int alea = uHasard(11); // Nombre aléatoire pour la selection de carte
	printf("Carte %i :",alea);
	Ligne();
	Ligne();
	switch(alea)
	{
		case 1:carte1();break;
		case 2:carte2();break;
		case 3:carte3();break;
		case 4:carte4();break;
		case 5:carte5();break;
		case 6:carte6();break;
		case 7:carte7();break;
		case 8:carte8();break;
		case 9:carte9();break;
		case 10:carte10();break;
		default:printf("Erreur");
	}
}
