#include <stdio.h>
#include <stdlib.h>
#include "crabs_creation.h"

// Function to assign HP (health points) to a crab based on its level
void attribute_crab(Crab* crab){

      if(!crab) exit(21);

      // Assign health points based on the crab's level
      if(crab->level == 1){

            crab->hp = 1;

      }else if(crab->level == 2){

            crab->hp = 2;

      }else if(crab->level == 3){

            crab->hp = 3;

      }

}

// Function to create a crab at the start of the path on the game board
Crab create_crab(Box** game_board, Box* path, int height, int width, int start_x, int start_y) {

      if(!game_board || !path) exit(22);

      Crab crab;

      // Check if the starting position is marked as START
      if (game_board[start_x][start_y].type == START) {

            // Place the crab on the first tile of the path
            crab.x = path[1].pos_x;
            crab.y = path[1].pos_y;
            crab.path_index = 0;
            crab.active = false;
            crab.level = 1;
            attribute_crab(&crab);
            crab.type = CRAB;

            // Mark the tile on the board as occupied by a crab
            game_board[crab.x][crab.y].type = CRAB;

            return crab;
      }
}