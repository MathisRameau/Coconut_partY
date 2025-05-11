#ifndef CRAB_MOVEMENT_H
#define CRAB_MOVEMENT_H

#include "gameBoard_creation.h"
#include "crabs_creation.h"

void move_crab(Crab* tab_crab, Box** game_board, Box* path, int path_length, int nb_crabs);

#endif