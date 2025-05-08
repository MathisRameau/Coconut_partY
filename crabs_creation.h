#ifndef CRABS_CREATION_H
#define CRABS_CREATION_H

#include "gameBoard_creation.h"
#include <stdbool.h>

typedef struct {
    int x;
    int y;
    int path_index;
    bool active;
    Terrain type;
} Crab;

Crab create_crab(Case** game_board, Case* chemin, int height, int width, int start_x, int start_y);

#endif
