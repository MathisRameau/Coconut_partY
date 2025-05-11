#ifndef MONKEYS_STORE_H
#define MONKEYS_STORE_H

#define ACHETER 1
#define AMELIORER 2
#define PAUSE 3

#include "monkeys_creation.h"

void monkeys_store(Monkey* tab_monkey, int* nb_monkeys, int* nb_ndc, Box** game_board, Box* path, int path_length, int height, int width);

#endif