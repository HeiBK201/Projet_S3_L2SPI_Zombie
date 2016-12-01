#include "Outil.h"
#include "CreaCarte.h"
#define N 11

void choixCarte(){
	int alea = uHasard(4);
	printf("Carte %i :",alea);
	Ligne();
	Ligne();
	switch(alea){
		case 1:carte1();break;
		case 2:carte2();break;
		case 3:carte3();break;
		case 4:carte4();break;
		default:printf("Erreur");
	}
}

void ModuleAmorceR(){
	//amorce tous les modules (code a  executer une fois pour toutes AVANT d'utiliser un quelconque module depuis le main)
	OutilAMORCER();//NE PAS DECLASSER:doit toujours etre appele en premier
	//amorcer TOUS les modules autres que Outil mentionnes dans les include de main.c

}//ModuleAmorceR

int main (int argc, const char * argv[]) {
	Appel0("");//NE PAS TOUCHER; ce code doit toujours etre place au debut du main
		ModuleAmorceR();//NE PAS TOUCHER; ce code doit toujours suivre immÃ©diatement Appel0("")
		srand(time(NULL));
		choixCarte();
	Appel1("");//NE PAS TOUCHER; ce code doit toujours etre place a la fin du main, juste avant le return()
    return 0;
}//main
