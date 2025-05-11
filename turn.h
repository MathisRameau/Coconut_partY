#ifndef TOUR_H
#define TOUR_H

#include "turn_creation.h"
#include "monkeys_creation.h"
#include "crabs_creation.h"

void turn(Box** game_board,
          Turn current_turn,
          int* nb_ccn,
          Monkey** tab_monkeys,
          int nb_monkeys[3],
          Crab** tab_crabs,
          int nb_crabs[3],
          int* tot_monkeys,
          int* tot_crabs,
          Box* path,
          int path_length,
          int height,
          int width,
          int start_x,
          int start_y,
          int zone_top,
          char* pseudo);

#endif
