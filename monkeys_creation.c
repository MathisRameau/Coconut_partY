#include <stdio.h>
#include <stdlib.h>
#include "monkeys_creation.h"

Monkey create_monkey(Case** game_board, int height, int width) {

      Monkey monkey;

    int path_positions[height * width][2];
    int path_count = 0;

    for (int i = 1; i < height - 1; i++) {

        for (int j = 1; j < width - 1; j++) {

            if (game_board[i][j].type == PATH) {

                path_positions[path_count][0] = i;
                path_positions[path_count][1] = j;
                path_count++;
            }
        }
    }

    if (path_count == 0) {
    printf("Aucune case PATH trouvée pour placer un singe.\n");
    monkey.x = MONKEY_NONE;
    monkey.y = MONKEY_NONE;
    monkey.type = MONKEY_NONE;
    return monkey;
}


    int random_index = rand() % path_count;
    int i = path_positions[random_index][0];
    int j = path_positions[random_index][1];

    monkey.x = i;
    monkey.y = j;
    monkey.type = MONKEY;

    if (game_board[i][j].type == PATH) {

        if (game_board[i][j - 1].type == LAND) {
            game_board[i][j - 1].type = MONKEY;
            monkey.x = i;
            monkey.y = j - 1;
        }

        else if (game_board[i][j + 1].type == LAND) {
            game_board[i][j + 1].type = MONKEY;
            monkey.x = i;
            monkey.y = j + 1;
        }

        else if (game_board[i - 1][j].type == LAND) {
            game_board[i - 1][j].type = MONKEY;
            monkey.x = i - 1;
            monkey.y = j;
        }
    }

    return monkey;
}
