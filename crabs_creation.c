#include <stdio.h>
#include <stdlib.h>
#include "crabs_creation.h"

Crab create_crab(Case** game_board, Case* chemin, int height, int width, int start_x, int start_y) {

      Crab crab;

      if (game_board[start_x][start_y].type == START) {

            crab.x = chemin[1].pos_x;
            crab.y = chemin[1].pos_y;
            crab.path_index = 0;
            crab.active = true;
            crab.type = CRAB;

            game_board[crab.x][crab.y].type = CRAB;

            return crab;
      }
}