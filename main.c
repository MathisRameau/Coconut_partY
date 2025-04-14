#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 50
#define SMOOTH_ITERATIONS 1
#define PROB_LAND 60

// Enumération pour les types de terrain
enum Terrain { START, LAND, SEA, CROWN, CRAB, MONKEY, PATH };

// Structure qui définie une Case
typedef struct {

    int pos_x;
    int pos_y;
    enum Terrain type;

} Case;

// Fonction qui créé un plateau de jeu
Case** gameBoard_creation(){

      Case** game_board = malloc(HEIGHT * sizeof(*game_board));

      if (game_board == NULL) {

            printf("Erreur, allocation échouée!\n");
            return NULL;

      }

      for (int h = 0; h < HEIGHT; h++) {

            game_board[h] = malloc(WIDTH * sizeof(Case));

            if (game_board[h] == NULL) {

                  printf("Erreur, allocation d'une ligne échouée!\n");

                  for (int k = 0; k < h; k++){

                        free(game_board[k]);

                  }

                  free(game_board);

                  return NULL;

            }
      }

      for (int i = 0; i < HEIGHT; i++) {

            for (int j = 0; j < WIDTH; j++) {

                  game_board[i][j].pos_x = i;
                  game_board[i][j].pos_y = j;

                  if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {

                        game_board[i][j].type = SEA;

                  }else{

                        int randVal = rand() % 100;

                        if (randVal < PROB_LAND){

                              game_board[i][j].type = LAND;  // Plaines 60%

                        }else{

                              game_board[i][j].type = SEA;  // Eau 40%

                        }

                  }
            }
      }

      return game_board;
}

// Fonction de lissage du plateau de jeu
void smooth_gameBoard(Case** game_board) {

      Case temp[HEIGHT][WIDTH];
      int land_count, sea_count;

      for (int iter = 0; iter < SMOOTH_ITERATIONS; iter++) {

            for (int i = 1; i < HEIGHT - 1; i++) {

                  for (int j = 1; j < WIDTH - 1; j++) {

                        land_count = 0;
                        sea_count = 0;

                        for (int di = -1; di <= 1; di++) {

                              for (int dj = -1; dj <= 1; dj++) {

                                    if (di == 0 && dj == 0) {

                                          continue;

                                    }

                                    enum Terrain voisin = game_board[i + di][j + dj].type;

                                    if (voisin == LAND) {

                                          land_count++;

                                    } else {

                                          sea_count++;

                                    }
                              }
                        }

                        if (land_count > sea_count) {

                              temp[i][j].type = LAND;

                        } else {

                              temp[i][j].type = SEA;
                        }
                  }
            }

            // Mise à jour du plateau après lissage
            for (int i = 1; i < HEIGHT - 1; i++) {

                  for (int j = 1; j < WIDTH - 1; j++) {

                        game_board[i][j] = temp[i][j];

                  }
            }
      }
}

void play_area(Case** game_board){

      int div = 3 * WIDTH / HEIGHT + 1;
      int dx = WIDTH / div, dy = HEIGHT / (0.6 * div);

      for(int i = 0; i < HEIGHT; i++){

            for(int j = 0; j < WIDTH; j++){

                  if(i >= dy && i <= HEIGHT - dy && j >= dx && j <= WIDTH - dx && game_board[i][j].type == SEA){

                        game_board[i][j].type = LAND;

                  }

                  if(i == dy && j == WIDTH / 2){

                        game_board[i][j].type = CROWN;

                  }

                  if(i == HEIGHT - dy && j == WIDTH / 2){

                        game_board[i][j].type = START;

                  }
            }
      }
}



// Affichage du plateau de jeu
void display_gameBoard(Case** game_board) {
      char symbol;

      for (int i = 0; i < HEIGHT; i++) {

            for (int j = 0; j < WIDTH; j++) {

                  switch (game_board[i][j].type) {

                        case LAND: symbol = ' '; break;
                        case CROWN: symbol = 'X'; break;
                        case SEA: symbol = '~'; break;
                        case START : symbol = '#'; break;
                        default: symbol = '?'; break;

                  }

                  printf("%c", symbol);
            }
            printf("\n");
      }
}

// Libération de la mémoire du plateau de jeu
void free_gameBoard(Case** game_board) {

      for (int i = 0; i < HEIGHT; i++) {

            free(game_board[i]);

      }

      free(game_board);
}

int main() {

      srand(time(NULL));

      Case** game_board = gameBoard_creation();

      if (game_board == NULL){

            return 1;

      }

      smooth_gameBoard(game_board);

      play_area(game_board);

      display_gameBoard(game_board);

      free_gameBoard(game_board);
      return 0;
}