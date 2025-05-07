#include <stdio.h>
#include <stdlib.h>
#include "crabs_movement.h"

void move_crab(Crab* crab, Case** game_board, Case* chemin, int chemin_length, int* crab_index) {
    if (*crab_index >= chemin_length - 1) return;

    game_board[crab->x][crab->y].type = PATH;

    (*crab_index)++;
    crab->x = chemin[*crab_index].pos_x;
    crab->y = chemin[*crab_index].pos_y;

    game_board[crab->x][crab->y].type = CRAB;
}
