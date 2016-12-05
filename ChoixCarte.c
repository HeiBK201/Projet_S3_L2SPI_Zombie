#include "Outilcpy.h"

void choixCarte()
{
	int alea = uHasard(4);
	//printf("Carte %i :",alea);
	Ligne();
	Ligne();
	switch(alea)
	{
		case 1:carte1();break;
		case 2:carte2();break;
		case 3:carte3();break;
		case 4:carte4();break;
		default:printf("Erreur");
	}
}