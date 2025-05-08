#include <stdio.h>
#include "crabs_creation.h"
#include "crabs_movement.h"

void move_crab(Crab* tab_crab, Case** game_board, Case* chemin, int chemin_length, int nb_crabs) {

      for (int i = nb_crabs - 1; i >= 0; i--) {

            game_board[tab_crab[i].x][tab_crab[i].y].type = PATH;

            if (tab_crab[i].path_index >= chemin_length - 1) {
                  tab_crab[i].active = false;
                  return;
            }

            tab_crab[i].path_index++;
            tab_crab[i].x = chemin[tab_crab[i].path_index].pos_x;
            tab_crab[i].y = chemin[tab_crab[i].path_index].pos_y;
            game_board[tab_crab[i].x][tab_crab[i].y].type = CRAB;
      }
}