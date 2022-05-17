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
    int line[TAILLE]={0};
    int k=completeLigne(grille,line);
    int y,p,t,n = 0;
    for (y=0;y<k;y++){
        for (p=0;p<TAILLE;p++){
            grille[line[y]][p]=' ';
        }
        for (t=line[y]-1;t>=0;t--){
            char* temp=grille[line[y]-(line[y]-1-t)];
            grille[line[y]-(line[y]-1-t)]=grille[t];
            grille[t]=temp;
        }
    }
}

int completeLigne(char** grille, int line[TAILLE]){
    int i,j,k=0,s;
    for (i=0;i<TAILLE;i++){
        s=0;
        for (j=0;j<TAILLE;j++){
            if (grille[i][j]=='@'){
                s++;
            }
        }if (s==TAILLE){
            line[k]=i;
            k++;
        }
    }return k;
}

int collisions(char** grille, Piece piece, int column, int orient){
	int i=3,j=0;
	int startline=0,startcolumn=0;
	int endline=piece.sizeLC[0],endcolumn=piece.sizeLC[1];
	int incre=1;
	Piece piece_orient;
	if (orient==2){
        piece_orient.form=malloc(piece.sizeLC[1]*sizeof(char*));
        for (int l=0;l<piece.sizeLC[1];l++){
            piece_orient.form[l]=malloc(piece.sizeLC[0]*sizeof(char));
            for (int t=0;t<piece.sizeLC[0];t++){
                piece_orient.form[l][t]=piece.form[piece.sizeLC[0]-1-t][l];
            }
        }
        piece_orient.sizeLC[0]=piece.sizeLC[1];
        piece_orient.sizeLC[1]=piece.sizeLC[0];
	}
	else if (orient==3) {
	    piece_orient.form=malloc(piece.sizeLC[0]*sizeof(char*));
        for (int l=piece.sizeLC[0]-1;l>=0;l--){
            piece_orient.form[l]=malloc(piece.sizeLC[1]*sizeof(char));
            for (int t=piece.sizeLC[1]-1;t>=0;t--){
                piece_orient.form[l][t]=piece.form[piece.sizeLC[0]-1-l][piece.sizeLC[1]-1-t];
            }
        }
        piece_orient.sizeLC[0]=piece.sizeLC[0];
        piece_orient.sizeLC[1]=piece.sizeLC[1];
	}else if (orient==4) {
	    piece_orient.form=malloc(piece.sizeLC[1]*sizeof(char*));
        for (int l=piece.sizeLC[1]-1;l>=0;l--){
            piece_orient.form[l]=malloc(piece.sizeLC[0]*sizeof(char));
            for (int t=piece.sizeLC[0]-1;t>=0;t--){
                piece_orient.form[l][t]=piece.form[t][piece.sizeLC[1]-1-l];
            }
        }
        piece_orient.sizeLC[0]=piece.sizeLC[1];
        piece_orient.sizeLC[1]=piece.sizeLC[0];
	}else{
	    piece_orient.form=piece.form;
	    piece_orient.sizeLC[0]=piece.sizeLC[0];
        piece_orient.sizeLC[1]=piece.sizeLC[1];
	}
	showPiece(piece_orient);
    for (int k=0;k<piece_orient.sizeLC[1];k++){
        for (int p=0;p<piece_orient.sizeLC[0];p++){
            if (grille[p][k+column]=='@'&& piece_orient.form[p][k]=='@'){
                for (int r=0;r<piece_orient.sizeLC[0];r++){
                    free(piece_orient.form[r]);
                }
                free(piece_orient.form);
                return 1;
            }
        }
    }
    int touche=0;
    while (i<9 && touche==0){
        for (j=0;j<piece_orient.sizeLC[1];j++){
            if (grille[i+1][j+column]=='@' && (piece_orient.form[piece_orient.sizeLC[0]-1][j]=='@' || piece_orient.form[piece_orient.sizeLC[0]-2][j]=='@')){
                touche=1;
            }
        }
        i++;
    }
    for (int m=0;m<piece_orient.sizeLC[0];m++){
        for (int n=0;n<piece_orient.sizeLC[1];n++){
            if (piece_orient.form[m][n]=='@'){
                grille[i-(piece_orient.sizeLC[0]-m-1)][column+n]='@';
            }
        }
    }
    for (int r=0;r<piece_orient.sizeLC[0];r++){
        free(piece_orient.form[r]);
    }
    free(piece_orient.form);
	return 0;
}

void game(){
//je sais pas encore quoi mettre là dedans
}



