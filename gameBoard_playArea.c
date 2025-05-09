#include <stdio.h>
#include <stdlib.h>
#include "gameBoard_playArea.h"
#include "path_creation.h"


void reset_board_paths(Case** game_board, int height, int width) {
    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if(game_board[i][j].type == PATH || game_board[i][j].type == START || game_board[i][j].type == CROWN) {
                game_board[i][j].type == LAND;
            }
        }
    }
}

void play_area(Case** game_board, Case** chemin, int* taille_chemin, int height, int width, int* start_x, int* start_y) {

    reset_board_paths(game_board, height, width);
    
    int div = 3 + width / height;
    int dx = width / div, dy = height / (0.6 * div);

    int zone_top = dy;
    int zone_bottom = height - dy;
    int zone_left = dx;
    int zone_right = width - dx;

    *start_x = height - dy;
    *start_y = width / 2;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            if (i >= zone_top && i <= zone_bottom && j >= zone_left && j <= zone_right && game_board[i][j].type == SEA) {
                game_board[i][j].type = LAND;
            }

            if (i == zone_top && j == *start_y) {
                game_board[i][j].type = CROWN;
            }

            if (i == *start_x && j == *start_y) {
                game_board[i][j].type = START;
            }
        }
    }

    *chemin = generate_path(game_board, start_x, start_y, taille_chemin, zone_top, zone_bottom, zone_left, zone_right, height, width);
}
