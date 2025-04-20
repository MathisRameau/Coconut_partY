#include <head.h>
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
