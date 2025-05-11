#ifndef PATH_CREATION_H
#define PATH_CREATION_H

#include "gameBoard_creation.h"
#include "path_direction.h"

typedef struct Chemin {
    int x, y;
    struct Chemin* suivant;
} Chemin;

Box* generate_path(Box** game_board, int* start_x, int* start_y, int* path_length, int zone_top, int zone_bottom, int zone_left, int zone_right, int height, int width);

#endif
