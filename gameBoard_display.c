#include <stdio.h>
#include <stdlib.h>
#include "gameBoard_display.h"

void display_gameBoard(Case** game_board, int height, int width) {
      for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                  char symbol;

                  switch (game_board[i][j].type) {
                        case LAND: symbol = ' '; break;
                        case SEA: symbol = '~'; break;
                        case CROWN: symbol = 'X'; break;
                        case START: symbol = '#'; break;
                        case PATH: symbol = '.'; break;
                        case MONKEY: symbol = '@'; break;
                        case CRAB: symbol = '*'; break;
                  }
                  printf("%c", symbol);
            }
            printf("\n");
      }

      printf("\n");
}