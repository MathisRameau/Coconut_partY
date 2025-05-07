#include <stdio.h>
#include <stdlib.h>
#include "gameBoard_free.h"

void free_gameBoard(Case** game_board, int height) {

      for (int i = 0; i < height; i++) {
            free(game_board[i]);
      }

      free(game_board);
}
