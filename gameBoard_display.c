#include <stdio.h>
#include <stdlib.h>
#include "gameBoard_display.h"

void display_gameBoard(Case** game_board, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char* color;

            switch (game_board[i][j].type) {
                case LAND:    color = "\033[0;32m"; break;
                case SEA:     color = "\033[0;34m"; break;
                case CROWN:   color = "\033[0;33m"; break;
                case START:   color = "\033[1;30m"; break;
                case PATH:    color = "\033[0;37m"; break;
                case MONKEY:  color = "\033[0;35m"; break;
                case CRAB:    color = "\033[0;31m"; break;
                default:      color = "\033[0m";    break;
            }

            printf("%s█\033[0m", color);
        }
        printf("\n");
    }
    printf("\n");
}
