programme: exe
Carte = CreaCarte.o CreaCarte.h carte1.o carte2.o carte3.o carte4.o carte5.o carte6.o carte7.o carte8.o carte9.o carte10.o ChoixCarte.c
All = Outil.o perso.o evenement.o bus.o Fonction_bat.o $(Carte) jeu.o


jeu.o:jeu.c
	gcc -c jeu.c -g
	
bus.o:bus.c
	gcc -c bus.c -g
	
perso.o:perso.c
	gcc -c perso.c -g

Outil.o:Outil.c
	gcc -c Outil.c -g
	
evenement.o:evenement.c
	gcc -c evenement.c -g
	
Fonction_bat.o:Fonction_bat.c
	gcc -c Fonction_bat.c -g
	
CreaCarte.o:CreaCarte.c
	gcc -c CreaCarte.c -g
	
carte1.o:carte1.c
	gcc -c carte1.c CreaCarte.h -g

carte2.o:carte2.c
	gcc -c carte2.c CreaCarte.h -g
	
carte3.o:carte3.c
	gcc -c carte3.c CreaCarte.h -g
	
carte4.o:carte4.c
	gcc -c carte4.c CreaCarte.h -g
	
carte5.o:carte5.c
	gcc -c carte5.c CreaCarte.h -g
	
carte6.o:carte6.c
	gcc -c carte6.c CreaCarte.h -g
	
carte7.o:carte7.c
	gcc -c carte7.c CreaCarte.h -g
	
carte8.o:carte8.c
	gcc -c carte8.c CreaCarte.h -g
	
carte9.o:carte9.c
	gcc -c carte9.c CreaCarte.h -g
	
carte10.o:carte10.c
	gcc -c carte10.c CreaCarte.h -g
	
ChoixCarte.o:ChoixCarte.c CreaCarte.h
	 gcc -c ChoixCarte.c CreaCarte.h -g

exe: $(All)
	gcc -o exe $(All) -lm
	
clean:
	rm *.o
