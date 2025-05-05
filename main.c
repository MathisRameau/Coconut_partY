#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include "gameBoard_dimension.h"
#include "gameBoard_creation.h"
#include "gameBoard_smooth.h"
#include "gameBoard_playArea.h"
#include "gameBoard_display.h"
#include "gameBoard_free.h"
#include "monkeys_creation.h"
#include "crabs_creation.h"
#include "crabs_movement.h"

int main() {
    srand(time(NULL)); 

    bool running = true;
    int choice;

    while (running) {
        printf("===== MENU PRINCIPAL =====\n");
        printf("1. Nouvelle partie\n");
        printf("2. Quitter\n");
        printf("3. Reprendre une partie\n");
        printf("Choix : \n");
        scanf("%d", &choice); 
    }


    if (choice == 1) {
        int height, width, start_x, start_y, chemin_length, crab_index = 0;
        Case* chemin;

        game_board_dimension(&height, &width);

        Case** game_board = gameBoard_creation(height, width);
        if (game_board == NULL) return 1;

        smooth_gameBoard(game_board, height, width);
        play_area(game_board, &chemin, &chemin_length, height, width, &start_x, &start_y);
        Monkey monkey = create_monkey(game_board, height, width);
        Crab crab = create_crab(game_board, chemin, height, width, start_x, start_y);
        display_gameBoard(game_board, height, width);
        free_gameBoard(game_board, height);

        while (crab_index < chemin_length && crab.hp > 0) {
        move_crab(&crab, game_board, chemin, chemin_length, &crab_index);

        display_gameBoard(game_board, height, width);

        usleep(200000);

        if (crab_index >= chemin_length) {
            running = false;
        }
        sleep(1);
        }
        crab_index = 0;
        if (crab.hp > 0 && crab_index >= chemin_length) {
            printf("Un crabe a atteint la couronne !\n");
        }
    }
    else if (choice == 2) {
        running = false;
    } else {
        printf("Choix invalide.\n");
    }
    return 0;
} 
