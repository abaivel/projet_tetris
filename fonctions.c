#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonctions.h"
#define TAILLE 10
#define NB_PIECES 7

void title(){
    printf("  _______   _        _     \n |__   __| | |      (_)    \n    | | ___| |_ _ __ _ ___ \n    | |/ _ \\ __| '__| / __|\n    | |  __/ |_| |  | \\__ \\ \n    |_|\\___|\\__|_|  |_|___/\n");
}

void showPiece(Piece piece){
}

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
	int** sizes = malloc(NB_PIECES*sizeof(int*));//Va stocker les tailles des pièces
	for (int i=0;i<NB_PIECES;i++){
        sizes[i]=malloc(2*sizeof(int));
	}
	if (sizes==NULL){
        exit(1);
	}
	sizes[0][0]=1;
	sizes[0][1]=4;
	sizes[1][0]=2;
	sizes[1][1]=2;
	for (int i=2;i<7;i++){
		sizes[i][0]=2;
		sizes[i][1]=3;
	}
	for (int i=0;i<NB_PIECES;i++){
        //allouer la mémoire pour form
		pieces[i].sizeLC[0]=sizes[i][0];
		pieces[i].sizeLC[1]=sizes[i][1];
		pieces[i].form=malloc(sizes[i][0]*sizeof(char*));
		if (pieces[i].form==NULL){
            exit(1);
        }
		for (int j=0;j<sizes[i][0];j++){
			pieces[i].form[j]=malloc(sizes[i][1]*sizeof(int));
            if (sizes==NULL){
                exit(1);
            }
		}
	}
	for (int i=0;i<4;i++){
		pieces[0].form[0][i]='@'; //piece 1, la barre
	}
	for (int i=0;i<2;i++){
		for (int j=0;j<2;j++){
			pieces[1].form[i][j]='@';//piece 2, le cube 2x2
		}
	}
	for (int i=0;i<3;i++){
		pieces[2].form[0][i]='@';//piece T
		pieces[3].form[0][i]='@';//piece L
		pieces[4].form[0][i]='@';//piece J
        //Ces trois pièces ont une ligne complete
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
		//Remplissage des cases sans @ par des " "
	}
	for (int i=0;i<2;i++){
		for (int j=0;j<3;j++){
			if (i==0 && j==2){
				pieces[5].form[i][j]=' ';//piece Z
			}else if (i==1 && j==0){
				pieces[5].form[i][j]=' ';
			}else{
				pieces[5].form[i][j]='@';
			}
			if (i==0 && j==0){
				pieces[6].form[i][j]=' ';//piece S
			}else if (i==1 && j==2){
				pieces[6].form[i][j]=' ';
			}else{
				pieces[6].form[i][j]='@';
			}
			//Tous ces if servent à faire les pieces Z et S
		}
	}
	pieces[0].nb_orient=2;
	pieces[1].nb_orient=1;
	pieces[2].nb_orient=4;
	pieces[3].nb_orient=4;
	pieces[4].nb_orient=4;
	pieces[5].nb_orient=2;
	pieces[6].nb_orient=2;
	//nb d'orientation de chaque pièce
}
void ShowPiece(Piece piece){
	int i,j; 
	for (i=0;i<=piece.sizeLC[0];i++)
		for(j=0;j<=piece.sizeLC[1];i++)
			printf("%c", piece.form)
		}
	}









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
            grille[line[y]][p]=' ';//vidage de la ligne
        }
        for (t=line[y]-1;t>=0;t--){
            //échange des lignes
            char* temp=grille[t+1];
            grille[t+1]=grille[t];
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
	int i,j=0;
	Piece piece_orient; //nouvelle pièce pour prendre en compte l'orientation choisie de la pièce
	switch (orient)
	{
	    case 1: //forme de base
	        piece_orient.form=malloc(piece.sizeLC[0]*sizeof(char*));
            if (piece_orient.form==NULL){
                exit(1);
            }
            for (int l=0;l<piece.sizeLC[0];l++){
                piece_orient.form[l]=malloc(piece.sizeLC[1]*sizeof(char));
                if (piece_orient.form[l]==NULL){
                    exit(1);
                }
                for (int t=0;t<piece.sizeLC[1];t++){
                    piece_orient.form[l][t]=piece.form[l][t];
                }
            }
            piece_orient.sizeLC[0]=piece.sizeLC[0];
            piece_orient.sizeLC[1]=piece.sizeLC[1];
            //piece_orient=piece vu que la pièce n'est pas tourné
            break;
	    case 2://forme tourné vers la droite de 90°
            piece_orient.form=malloc(piece.sizeLC[1]*sizeof(char*));
            if (piece_orient.form==NULL){
                exit(1);
            }
            for (int l=0;l<piece.sizeLC[1];l++){
                piece_orient.form[l]=malloc(piece.sizeLC[0]*sizeof(char));
                if (piece_orient.form[l]==NULL){
                    exit(1);
                }
                for (int t=piece.sizeLC[0]-1;t>=0;t--){
                    printf("l=%d et t=%d\n",l,t);
                    piece_orient.form[l][piece.sizeLC[0]-1-t]=piece.form[t][l];
                }
            }
            piece_orient.sizeLC[0]=piece.sizeLC[1];
            piece_orient.sizeLC[1]=piece.sizeLC[0];
            break;
        case 3://forme tourné vers la droite de 180°
            piece_orient.form=malloc(piece.sizeLC[0]*sizeof(char*));
            if (piece_orient.form==NULL){
                exit(1);
            }
            for (int l=piece.sizeLC[0]-1;l>=0;l--){
                piece_orient.form[l]=malloc(piece.sizeLC[1]*sizeof(char));
                if (piece_orient.form[l]==NULL){
                    exit(1);
                }
            }
            for (int l=piece.sizeLC[0]-1;l>=0;l--){
                for (int t=piece.sizeLC[1]-1;t>=0;t--){
                    piece_orient.form[piece.sizeLC[0]-1-l][piece.sizeLC[1]-1-t]=piece.form[l][t];
                }
            }
            piece_orient.sizeLC[0]=piece.sizeLC[0];
            piece_orient.sizeLC[1]=piece.sizeLC[1];
            break;
        case 4://forme tourné vers la gauche de 90°
            piece_orient.form=malloc(piece.sizeLC[1]*sizeof(char*));
            for (int l=piece.sizeLC[1]-1;l>=0;l--){
                piece_orient.form[l]=malloc(piece.sizeLC[0]*sizeof(char));
            }
            for (int l=piece.sizeLC[1]-1;l>=0;l--){
                for (int t=0;t<piece.sizeLC[0];t++){
                    piece_orient.form[piece.sizeLC[1]-1-l][t]=piece.form[t][l];
                }
            }
            piece_orient.sizeLC[0]=piece.sizeLC[1];
            piece_orient.sizeLC[1]=piece.sizeLC[0];
            break;
        default:
            printf("Erreur");
            exit(1);
	}
    for (int k=0;k<piece_orient.sizeLC[1];k++){
        for (int p=0;p<piece_orient.sizeLC[0];p++){
            if (grille[p][k+column]=='@'&& piece_orient.form[p][k]=='@'){
                for (int r=0;r<piece_orient.sizeLC[0];r++){
                    free(piece_orient.form[r]);
                }
                free(piece_orient.form);
                return 1; //Si la pièce dépasse la grille par le haut
            }
        }
    }
    i=piece_orient.sizeLC[0]-1;
    int touche=0;
    while (i<TAILLE-piece_orient.sizeLC[0]+1 && touche==0){ //Tant que la pièce n'est pas arrivée en bas de la grille et qu'elle peut encore descendre
        printf("i=%d\n",i);
        for (int k=0;k<piece_orient.sizeLC[0];k++){
            for (int j=0;j<piece_orient.sizeLC[1];j++){
                if (grille[i+k][j+column]=='@' && piece_orient.form[k][j]=='@'){
                    touche=1;
                }
            }
        }
        i++;
    }
    i-=touche;
    for (int m=0;m<piece_orient.sizeLC[0];m++){
        for (int n=0;n<piece_orient.sizeLC[1];n++){
            if (piece_orient.form[m][n]=='@'){
                grille[i-(piece_orient.sizeLC[0]-m-1)][column+n]='@';//Placement de la pièce
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



