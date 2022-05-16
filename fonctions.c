#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonctions.h"
#define TAILLE 10
#define NB_PIECES 7

void show(char** grille){
	int i,l;
	char a;
	for (a='A';a<='J';a++){ 
		printf(" %c", a);
	}
	printf("\n");
	for(i=0;i<TAILLE;i++){
		for (l=0;l<TAILLE;l++){
			printf("|%c", grille[i][l]);
		}
		printf("|\n");
	}
}

void createPiece(Piece* pieces){
	int** sizes = malloc(7*sizeof(int*));
	sizes[0][0]=1;
	sizes[0][1]=4;
	sizes[1][0]=2;
	sizes[1][1]=2;
	for (int i=2;i<=7;i++){
		sizes[i][0]=2;
		sizes[i][1]=3;
	}
	for (int i=0;i<NB_PIECES;i++){
		pieces[i].size[0]=sizes[i][0];
		pieces[i].size[1]=sizes[i][1];
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
			pieces[2].form[1][i]=' ';
		}
		if (pieces[3].form[1][i]!='@'){
			pieces[3].form[1][i]=' ';
		}
		if (pieces[4].form[1][i]!='@'){
			pieces[4].form[1][i]=' ';
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

void remove_line(char** grille){
}

void completeLigne(char** grille, int line[TAILLE]){
}

int collisions(char** grille, Piece piece, int column, int orient){
	int i=0,j=0;
	int startline=0,startcolumn=0;
	int endline=piece.size[0],endcolumn=piece.size[1];
	int incre=1;
	if (orient==2){
		endline=piece.size[1];
		endcolumn=piece.size[0];
	}
	else if (orient==3) {
		startline=piece.size[1]-1;
		startcolumn=piece.size[0]-1;
		endline=-1;
		endcolumn=-1;
		incre=-1;
	}else if (orient==4) {
		startline=piece.size[0]-1;
		startcolumn=piece.size[1]-1;
		endline=-1;
		endcolumn=-1;
		incre=-1;
	}if (orient==1){
		for (int k=0;k<piece.size[1];k++){
			for (int p=0;p<piece.size[0];p++){
				if (grille[p][k+column]=='@'&& piece.form[p][k]=='@'){
					return 1;
				}
			}
		}
		int touche=0;
		while (i<10 && touche==0){
			for (j=0;j<piece.size[1];j++){
				if (grille[i+1][j+column]=='@' && piece.form[i-1][j]=='@'){
					touche=1;
				}
			}
			i++;
		}
		for (int m=0;m<piece.size[0];m++){
			for (int n=0;n<piece.size[1];n++){
				grille[i-m-1][column+n]='@';
			}
		}
	}
	return 0;
	
}

void game(){
//je sais pas encore quoi mettre là dedans
}



