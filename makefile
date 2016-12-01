carteX = carte1
All = Outil.o CreaCarte.o CreaCarte.h carte1.o

$(carteX):$(All)
	gcc -o $(carteX) $(All) -lm
Outil.o:Outil.c
	gcc -c Outil.c -g
CreaCarte.o:CreaCarte.c CreaCarte.h
	gcc -c CreaCarte.c CreaCarte.h -g
$(carteX).o:$(carteX).c CreaCarte.h
	 gcc -c $(carteX).c CreaCarte.h -g

clean:
	rm -i *.o
