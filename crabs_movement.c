#include <stdio.h>
#include <stdlib.h>
#include "crabs_creation.h"
#include "crabs_movement.h"

// Moves all active crabs one step forward along the path
void move_crab(Crab* tab_crab, Box** game_board, Box* path, int path_length, int nb_crabs) {

      if(!game_board || !path) exit(23);
      if(!tab_crab) return;

      for (int i = nb_crabs - 1; i >= 0; i--) {

            // Reset the current tile where the crab was to PATH
            game_board[tab_crab[i].x][tab_crab[i].y].type = PATH;

            // If the crab reached the end of the path, deactivate it
            if (tab_crab[i].path_index >= path_length - 1) {
                  tab_crab[i].active = false;
                  continue;
            }

            // If the crab is active move it one step forward
            if(tab_crab[i].active){

                  tab_crab[i].path_index++;
                  tab_crab[i].x = path[tab_crab[i].path_index].pos_x;
                  tab_crab[i].y = path[tab_crab[i].path_index].pos_y;

                  // Update the game board to show the crab at its new position
                  game_board[tab_crab[i].x][tab_crab[i].y].type = CRAB;

            }
      }
}