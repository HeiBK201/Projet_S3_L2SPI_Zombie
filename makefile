programme: exe

jeuSansMap.o:jeuSansMap.c
	gcc -c jeuSansMap.c -g
	
bus.o:bus.c
	gcc -c bus.c -g
	
perso.o:perso.c
	gcc -c perso.c -g

Outilcpy.o:Outilcpy.c
	gcc -c Outilcpy.c -g
	
evenement.o:evenement.c
	gcc -c evenement.c -g
	
carte1.o:carte1.c
	gcc -c carte1.c -g
	
exe: Outilcpy.o perso.o evenement.o bus.o carte1.o jeuSansMap.o 
	gcc -o exe Outilcpy.o perso.o evenement.o bus.o carte1.o jeuSansMap.o -lm
	
clean:
	rm -i *.o