#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
#define NB_PIECES 7
#define TAILLE 10

int main(){
	Piece* pieces=malloc(NB_PIECES*sizeof(Piece));
	createPiece(pieces);
	char** grille=malloc(TAILLE*sizeof(char*));
	for (int i=0;i<TAILLE;i++){
		grille[i]=malloc(TAILLE*sizeof(char));
		for (int j=0;j<TAILLE;j++){
			grille[i][j]=' ';
		}
	}
	collisions(grille, pieces[1],4,1);
	show(grille);
    return 0;
}
