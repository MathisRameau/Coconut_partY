#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include "gameBoard_dimension.h"
#include "gameBoard_creation.h"
#include "gameBoard_smooth.h"
#include "gameBoard_playArea.h"
#include "gameBoard_display.h"
#include "gameBoard_free.h"
#include "monkeys_creation.h"
#include "crabs_creation.h"
#include "crabs_movement.h"
#include "clean_screen.h"

int main() {
    srand(time(NULL));

    bool running = true;

    int height, width, start_x, start_y, chemin_length, crab_index = 0;
    Case* chemin;

    game_board_dimension(&height, &width);

    Case** game_board = gameBoard_creation(height, width);
    if (game_board == NULL) return 1;

    smooth_gameBoard(game_board, height, width);
    play_area(game_board, &chemin, &chemin_length, height, width, &start_x, &start_y);
    Monkey monkey = create_monkey(game_board, height, width);
    Crab crab = create_crab(game_board, chemin, height, width, start_x, start_y);

    while (running) {
        move_crab(&crab, game_board, chemin, chemin_length, &crab_index);

        clear_screen();

        display_gameBoard(game_board, height, width);

        usleep(150000);

        if (crab_index == chemin_length - 1) {
            running = false;
        }
    }

    free_gameBoard(game_board, height);

    return 0;
}
