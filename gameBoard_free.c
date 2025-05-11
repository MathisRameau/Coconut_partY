#include <stdio.h>
#include <stdlib.h>
#include "gameBoard_free.h"

// Frees all memory allocated for the game board
void free_gameBoard(Box** game_board, int height) {

      if(!game_board) exit(26);

      // Free each row
      for (int i = 0; i < height; i++) {

            free(game_board[i]);
      }

      // Free the row pointer array itself
      free(game_board);
}