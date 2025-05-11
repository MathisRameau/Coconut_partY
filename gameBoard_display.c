#include <stdio.h>
#include <stdlib.h>
#include "clean_screen.h"
#include "gameBoard_display.h"

// Displays the game board with colored tiles, player name, and game info
void display_gameBoard(Box** game_board, int height, int width, char* pseudo, int nb_ccn, int turn) {

      if(!game_board || !pseudo) exit(25);

      clear_screen(); // Clears the console screen before drawing the board

      printf("============================================================\n");
      printf("|                        COCONUT PARTY\n");
      printf("|===========================================================\n");
      printf("| Pseudo : %s\n", pseudo);
      printf("| Nombre de noix de coco : %d\n", nb_ccn);
      printf("| Tour : %d\n", turn);
      printf("============================================================\n\n");
      printf("\n\n");

      // Display each tile in the board with appropriate color
      for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                  char* color;

                  // Assign color based on tile type
                  switch (game_board[i][j].type) {
                        case LAND:    color = "\033[0;32m"; break;
                        case SEA:     color = "\033[0;34m"; break;
                        case CROWN:   color = "\033[0;33m"; break;
                        case START:   color = "\033[1;30m"; break;
                        case PATH:    color = "\033[0;37m"; break;
                        case MONKEY:  color = "\033[0;35m"; break;
                        case CRAB:    color = "\033[0;31m"; break;
                        default:      color = "\033[0m";    break;
                  }

                  printf("%s█\033[0m", color); // Print colored block
            }
            printf("\n");
      }
}