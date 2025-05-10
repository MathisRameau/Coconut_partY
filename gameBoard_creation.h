#ifndef GAMEBOARD_CREATION_H
#define GAMEBOARD_CREATION_H

#define HEIGHT 30
#define WIDTH 90
#define PROB_LAND 60

typedef enum {
    LAND,
    SEA,
    PATH,
    START,
    CROWN,
    CRAB,
    MONKEY
} Terrain;

typedef struct {
    int pos_x;
    int pos_y;
    Terrain type;
} Case;

Case** gameBoard_creation();

#endif