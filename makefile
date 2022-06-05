all: tetris

main.o: main.c fonctions.h
	gcc -c main.c -o main.o

fonctions.o: fonctions.c fonctions.h
	gcc -c fonctions.c -o fonctions.o

tetris: main.o fonctions.o
	gcc fonctions.o main.o -o tetris
	
clean:
	rm *.o
