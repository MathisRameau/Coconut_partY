#ifndef PATH_DIRECTION_H
#define PATH_DIRECTION_H

#include "gameBoard_creation.h"

#define LEFT 1
#define UP 2
#define RIGHT 3

int choice_direction(int derniere_direction, Box box_chemin, int zone_top, int zone_bottom, int zone_left, int zone_right, int width);

#endif //PATH_DIRECTION_H
