#ifndef MONKEYS_CREATIONS_H
#define MONKEYS_CREATIONS_H

#include "gameBoard_creation.h"
#include "ask_monkey_position.h"

typedef struct {
    int x;
    int y;
    int temps_tir;
    int level;
    int range;
    int attack;
    Terrain type;
} Monkey;

void attribute_monkey(Monkey* monkey);
Monkey create_monkey(Case** game_board, Case* chemin, int chemin_length, int height, int width, int level);

#endif