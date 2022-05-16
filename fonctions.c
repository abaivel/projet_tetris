#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonctions.h"
#define NB_PIECES 7

typedef struct {
	char** form;
	int nb_orient;
}Piece

void show(char** grille){
}

void createPiece(Piece* pieces, int** sizes){
	for (int i=0;i<NB_PIECES;i++){
		pieces[i].form=malloc(sizes[i][0]*sizeof(char*));
		for (int j=0;j<sizes[i][0];j++){
			pieces[i].form[j]=malloc(sizes[i][1]*sizeof(int));
		}
	}
	for (int i=0;i<4;i++){
		pieces[0].form[0][i]='@';
	}
	for (int i=0;i<2;i++){
		for (int j=0;j<2;j++){
			pieces[1].form[i][j]='@';
		}
	}
	for (int i=0;i<3;i++){
		pieces[2].form[0][i]='@';
		pieces[3].form[0][i]='@';
		pieces[4].form[0][i]='@';
	}
	pieces[2].form[1][1]='@';
	pieces[3].form[1][0]='@';
	pieces[4].form[1][2]='@';
	for (int i=0;i<3;i++){
		if (pieces[2].form[1][i]!='@'){
			pieces[2].form[1][i]=' '
		}
		if (pieces[3].form[1][i]!='@'){
			pieces[3].form[1][i]=' '
		}
		if (pieces[4].form[1][i]!='@'){
			pieces[4].form[1][i]=' '
		}
	}
	for (int i=0;i<2;i++){
		for (int j=0;j<3;j++){
			if (i==0 && j==2){
				pieces[5].form[i][j]=' ';
			}else if (i==1 && j==0){
				pieces[5].form[i][j]=' ';
			}else{
				pieces[5].form[i][j]='@';
			}
			if (i==0 && j==0){
				pieces[6].form[i][j]=' ';
			}else if (i==1 && j==2){
				pieces[6].form[i][j]=' ';
			}else{
				pieces[6].form[i][j]='@';
			}
		}
	}
	pieces[0].nb_orient=2;
	pieces[1].nb_orient=1;
	pieces[2].nb_orient=4;
	pieces[3].nb_orient=4;
	pieces[4].nb_orient=4;
	pieces[5].nb_orient=2;
	pieces[6].nb_orient=2;
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


