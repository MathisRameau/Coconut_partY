#ifndef CRABS_CREATION_H
#define CRABS_CREATION_H

#include "gameBoard_creation.h"
#include <stdbool.h>

typedef struct {
    int x;
    int y;
    int path_index;
    int hp;
    int level;
    bool active;
    Ground type;
} Crab;

void attribute_crab(Crab* crab);
Crab create_crab(Box** game_board, Box* path, int height, int width, int start_x, int start_y);

#endif
