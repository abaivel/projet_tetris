#define TAILLE 10

typedef struct {
	char** form;
	int nb_orient;
	int sizeLC[2];
}Piece;

void title();
//void showPiece(Piece piece);
void show(char** grille);
void createPiece(Piece* pieces);
Piece create_orientPiece(Piece piece, int orient);
void showPiece(Piece piece, int orient);
showPieceOrient(Piece piece);
void saveScore(int score, char pseudo[]);
void recup_Score();
char getChar();
int remove_line(char** grille);
int completeLigne(char** grille, int line[TAILLE]);
int collisions(char** grille, Piece piece, int column, int orient);
void game();
