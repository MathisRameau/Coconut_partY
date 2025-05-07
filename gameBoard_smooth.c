#include <stdio.h>
#include <stdlib.h>
#include "gameBoard_smooth.h"

void smooth_gameBoard(Case** game_board, int height, int width) {
      Case temp[height][width];
      int land_count, sea_count;

      for (int iter = 0; iter < SMOOTH_ITERATIONS; iter++) {

            for (int i = 1; i < height - 1; i++) {

                  for (int j = 1; j < width - 1; j++) {

                        land_count = 0;
                        sea_count = 0;

                        for (int di = -1; di <= 1; di++) {

                              for (int dj = -1; dj <= 1; dj++) {

                                    if (di == 0 && dj == 0) continue;
                                    Terrain voisin = game_board[i + di][j + dj].type;
                                    (voisin == LAND) ? land_count++ : sea_count++;
                              }
                        }

                        temp[i][j].type = (land_count > sea_count) ? LAND : SEA;
                  }
            }

            for (int i = 1; i < height - 1; i++) {

                  for (int j = 1; j < width - 1; j++) {

                        game_board[i][j].type = temp[i][j].type;
                  }
            }
      }
}
