#ifndef CRABS_CREATION_H
#define CRABS_CREATION_H

#include "gameBoard_creation.h"

typedef struct {
    int x;
    int y;
    int path_index;
    Terrain type;
    int hp;
} Crab;

Crab create_crab(Case** game_board, Case* chemin, int height, int width, int start_x, int start_y);

#endif
