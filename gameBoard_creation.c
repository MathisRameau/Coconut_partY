#include <stdio.h>
#include <stdlib.h>
#include "gameBoard_creation.h"

Case** gameBoard_creation(int height, int width) {

    Case** game_board = malloc(height * sizeof(*game_board));
    if (!game_board) {
        printf("Erreur, allocation échouée!\n");
        return NULL;
    }

    for (int h = 0; h < height; h++) {
        game_board[h] = malloc(width * sizeof(Case));
        if (!game_board[h]) {
            printf("Erreur, allocation d'une ligne échouée!\n");
            for (int k = 0; k < h; k++) free(game_board[k]);
            free(game_board);
            return NULL;
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            game_board[i][j].pos_x = i;
            game_board[i][j].pos_y = j;

            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                game_board[i][j].type = SEA;
            } else {
                int randVal = rand() % 100;
                game_board[i][j].type = (randVal < PROB_LAND) ? LAND : SEA;
            }
        }
    }

    return game_board;
}