#ifndef MONKEYS_CREATIONS_H
#define MONKEYS_CREATIONS_H

#include "gameBoard_creation.h"

typedef struct {
    int x;
    int y;
    int temps_tir;
    Terrain type;

} Monkey;

Monkey monkeys_creation(Case** game_board, int height, int width);

#endif