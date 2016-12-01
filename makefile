carte = ChoixCarte
All = Outil.o CreaCarte.o CreaCarte.h carte1.o carte2.o carte3.o carte4.o ChoixCarte.c

carte:$(All)
	gcc -o carte $(All) -lm
Outil.o:Outil.c
	gcc -c Outil.c -g
CreaCarte.o:CreaCarte.c CreaCarte.h
	gcc -c CreaCarte.c CreaCarte.h -g
carte1.o:carte1.c
	gcc -c carte1.c CreaCarte.h -g
carte2.o:carte2.c
	gcc -c carte2.c CreaCarte.h -g
carte3.o:carte3.c
	gcc -c carte3.c CreaCarte.h -g
carte4.o:carte4.c
	gcc -c carte4.c CreaCarte.h -g
$(carte).o:$(carte).c CreaCarte.h
	 gcc -c $(carte).c CreaCarte.h -g

clean:
	rm *.o
