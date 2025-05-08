#ifndef MONKEYS_CREATIONS_H
#define MONKEYS_CREATIONS_H

#include "gameBoard_creation.h"

#define MONKEY_NONE -1

typedef struct {
    int x;
    int y;
    Terrain type;
} Monkey;

Monkey create_monkey(Case** game_board, int height, int width);

#endif