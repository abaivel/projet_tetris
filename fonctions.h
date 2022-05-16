typedef struct {
	char** form;
	int nb_orient;
	int size[2];
}Piece;

void show(char** grille);
void createPiece(Piece* pieces);
void saveScore(int score, char pseudo[]);
void recup_Score();
char getChar();
void game();

