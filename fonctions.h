#define TAILLE 10

typedef struct {
	char** form;
	int nb_orient;
	int sizeLC[2];
	int color;
}Piece;

void title();
int emptyLine(char** grille);
void show(char** grille, int** colors);
Piece create_orientPiece(Piece piece, int orient);
void createPiece(Piece* pieces);
void saveScore(int score, char pseudo[]);
void showPiece(Piece piece, int orient);
void showPieceOrient(Piece piece);
void showPieceOrien(Piece piece, int orient);
void recup_Scores();
char getChar();
int remove_line(char** grille);
int completeLigne(char** grille, int line[TAILLE]);
int collisions(char** grille, int** colors, Piece piece, int column, int orient);
