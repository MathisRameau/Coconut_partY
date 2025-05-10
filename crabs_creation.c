#include <stdio.h>
#include <stdlib.h>
#include "crabs_creation.h"

void attribute_crab(Crab* crab){

      if(!crab) exit(21);

      if(crab->level == 1){

            crab->hp = 1;

      }else if(crab->level == 2){

            crab->hp = 2;

      }else if(crab->level == 3){

            crab->hp = 3;

      }

}

Crab create_crab(Case** game_board, Case* chemin, int height, int width, int start_x, int start_y) {

      if(!game_board || !chemin) exit(22);

      Crab crab;

      if (game_board[start_x][start_y].type == START) {

            crab.x = chemin[1].pos_x;
            crab.y = chemin[1].pos_y;
            crab.path_index = 0;
            crab.active = false;
            crab.level = 1;
            attribute_crab(&crab);
            crab.type = CRAB;

            game_board[crab.x][crab.y].type = CRAB;

            return crab;
      }
}