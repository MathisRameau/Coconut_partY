#ifndef MONKEYS_CREATIONS_H
#define MONKEYS_CREATIONS_H

#include "gameBoard_creation.h"
#include "ask_monkey_position.h"

typedef struct {
    int x;
    int y;
    int time_shoot;
    int level;
    int range;
    int attack;
    Ground type;
} Monkey;

void attribute_monkey(Monkey* monkey);
Monkey create_monkey(Box** game_board, Box* chemin, int chemin_length, int height, int width, int level);

#endif