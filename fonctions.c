#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonctions.h"

typedef struct {
	char** form;
	int nb_orient;
}Piece

void show(char** grille){
}

void createPiece(Piece* pieces){
}

void saveScore(int score, char pseudo[]){
}

void recup_Score(){
}

char getChar()
{
    int c = 0;
	c = getc(stdin);
    while (getc(stdin) != '\n' && getc(stdin) != EOF);
    return c;
}

void game(){
//je sais pas encore quoi mettre là dedans
}



