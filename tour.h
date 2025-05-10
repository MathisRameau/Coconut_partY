#ifndef TOUR_H
#define TOUR_H

#include "tour_creation.h"
#include "monkeys_creation.h"
#include "crabs_creation.h"

void tour(Case** game_board, Tour* tab_tour, Tour tour_actuel,
          int* nb_ndc, Monkey** tab_monkeys, int nb_monkeys[3],
          Crab** tab_crabs, int nb_crabs[3], int* tot_monkeys, int* tot_crabs,
          Case* chemin, int chemin_length, int height, int width,
          int start_x, int start_y, int zone_top, char* pseudo);



#endif
