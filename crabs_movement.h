#ifndef CRAB_MOVEMENT_H
#define CRAB_MOVEMENT_H

#include "gameBoard_creation.h"
#include "crabs_creation.h"

void move_crab(Crab* crab, Case** game_board, Case* chemin, int chemin_length, int* crab_index);

#endif