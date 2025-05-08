#ifndef CRAB_MOVEMENT_H
#define CRAB_MOVEMENT_H

#include "gameBoard_creation.h"
#include "crabs_creation.h"

void move_crab(Crab* tab_crab, Case** game_board, Case* chemin, int chemin_length, int nb_crabs);

#endif