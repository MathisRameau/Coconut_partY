#include "crabs_movement.h"

void move_crab(Crab* crab, Case** game_board, Case* chemin, int chemin_length, int* crab_index) {
    if (*crab_index >= chemin_length - 1) return;


    if(*crab_index > 0) {
        int old_x = chemin[*crab_index - 1].pos_x;
        int old_y = chemin[*crab_index - 1].pos_y;
        game_board[old_x][old_y].type = PATH;
    }

    crab->x = chemin[*crab_index].pos_x;
    crab->y = chemin[*crab_index].pos_y;
    game_board[crab->x][crab->y].type = CRAB;

    (*crab_index)++;
}
