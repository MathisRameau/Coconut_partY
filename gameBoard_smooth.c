#include <stdio.h>
#include <stdlib.h>
#include "gameBoard_smooth.h"

// Applies smoothing to the terrain to make it more natural
void smooth_gameBoard(Box** game_board, int height, int width) {

      if(!game_board) exit(28);

      Box temp[height][width];
      int land_count, sea_count;

      for (int iter = 0; iter < SMOOTH_ITERATIONS; iter++) {

            // Loop through all internal cells (ignoring edges)
            for (int i = 1; i < height - 1; i++) {

                  for (int j = 1; j < width - 1; j++) {

                        land_count = 0;
                        sea_count = 0;

                        // Count surrounding LAND and SEA tiles in a 3x3 area
                        for (int di = -1; di <= 1; di++) {

                              for (int dj = -1; dj <= 1; dj++) {

                                    if (di == 0 && dj == 0) continue;
                                    Ground neighbor = game_board[i + di][j + dj].type;
                                    (neighbor == LAND) ? land_count++ : sea_count++;
                              }
                        }

                        // If more neighbors are LAND, make this cell LAND, else SEA
                        temp[i][j].type = (land_count > sea_count) ? LAND : SEA;
                  }
            }

            // Apply changes from the temp board to the real one
            for (int i = 1; i < height - 1; i++) {

                  for (int j = 1; j < width - 1; j++) {

                        game_board[i][j].type = temp[i][j].type;
                  }
            }
      }
}