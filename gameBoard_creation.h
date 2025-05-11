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
} Ground;

typedef struct {
    int pos_x;
    int pos_y;
    Ground type;
} Box;

Box** gameBoard_creation(int height, int width);

#endif