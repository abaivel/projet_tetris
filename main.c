#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "fonctions.h"
#define NB_PIECES 7
#define TAILLE 10
#define TIME_MAX 10


int main(){
	srand(time(NULL));
	//printf("\033[40m");
	Piece* pieces=malloc(NB_PIECES*sizeof(Piece));
	if (pieces==NULL){
		printf("Erreur");
		exit(1);
	}
	createPiece(pieces);
	char** grille=malloc(TAILLE*sizeof(char*));
	if (grille==NULL){
		printf("Erreur");
		exit(1);
	}
	int** colors=malloc(TAILLE*sizeof(char*));
	if (colors==NULL){
		printf("Erreur");
		exit(1);
	}
	for (int i=0;i<TAILLE;i++){
		grille[i]=malloc(TAILLE*sizeof(char));
		if (grille[i]==NULL){
			printf("Erreur");
			exit(1);
		}
		colors[i]=malloc(TAILLE*sizeof(int));
		if (colors[i]==NULL){
			printf("Erreur");
			exit(1);
		}
		for (int j=0;j<TAILLE;j++){
			grille[i][j]=' ';
			colors[i][j]=37;
		}
	}
	title();
	int orient;
	char column;
	int fin=0;
	int num_piece;
	double inter;
	int score=0;
	int max_time;
	do{
		int max_time=emptyLine(grille);
		printf("Voici votre grille :\n");
		show(grille,colors);
		num_piece=rand()%NB_PIECES;
		Piece chosen_piece=pieces[num_piece];
		time_t tv = time( NULL );
		if (num_piece != 1){//si la piece n'est pas le cube
			printf("Orientation possible de la piece :\n");
			showPieceOrient(chosen_piece);
			//time_t tv = time( NULL );
			do{
				printf("Choisir l'orientation de la piece :\n");
				scanf("%d",&orient);
			}while(orient<1 || orient>chosen_piece.nb_orient);
		}else{//La piece étant le cube, il n'y a qu'une seule orientation possible
			printf("Voici la piece a placer :\n");
			showPiece(chosen_piece,1);
		}
		do{
			printf("Choisir la colonne (c'est la partie gauche de la piece qui sera sur cette colonne) :\n");
			column=getChar();
		}while(column<'A'||(orient%2==0 && column+chosen_piece.sizeLC[0]-1>'J')||(orient%2==1 && column+chosen_piece.sizeLC[1]-1>'J'));
		time_t tv2 = time( NULL );
		inter=difftime(tv2,tv);
		if (inter>max_time){
			printf("Tu as pris trop de temps\n");
			orient=rand()%4 + 1;
			column='A'+rand()%(TAILLE-chosen_piece.sizeLC[orient%2]);
			sleep(2);
		}
		fin = collisions(grille,colors,chosen_piece,column-'A', orient);
		if (fin==0){
			show(grille, colors);
			score+=remove_line(grille);
		}
	}while(fin==0);
	char nom[20];
	printf("FIN\nEntrez votre nom :\n");
	scanf("%s",nom);
	saveScore(score,nom);
	recup_Scores();
	for (int i=0;i<NB_PIECES;i++){
		for(int j=0;j<pieces[i].sizeLC[0];j++){
			free(pieces[i].form[j]);
		}
		free(pieces[i].form);
	}
	for (int i=0;i<TAILLE;i++){
		free(grille[i]);
		free(colors[i]);
	}
	free(pieces);
	free(grille);
	free(colors);
	return 0;
}
