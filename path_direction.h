#ifndef PATH_DIRECTION_H
#define PATH_DIRECTION_H

#include "gameBoard_creation.h"

#define GAUCHE 1
#define HAUT 2
#define DROITE 3

int choix_direction(int derniere_direction, Case case_chemin, int zone_top, int zone_bottom, int zone_left, int zone_right, int width);

#endif //PATH_DIRECTION_H
