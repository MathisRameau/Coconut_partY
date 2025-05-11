#include <stdio.h>
#include <stdlib.h>
#include "gameBoard_playArea.h"
#include "path_creation.h"

// This function defines the central playable area on the board and generates the crab path
void play_area(Box** game_board, Box** path, int* path_length, int height, int width, int* start_x, int* start_y, int* zone_top){

      if(!game_board || !path || !path_length || !start_x || !start_y) exit(27);

      // Calculate dimensions of the play zone dynamically based on board size
      int div = 3 * width / height + 1;

      int dx = width / div;
      int dy = height / (0.6 * div);

      *zone_top = dy;
      int zone_bottom = height - dy;
      int zone_left = dx;
      int zone_right = width - dx;

      *start_x = height - dy;
      *start_y = width / 2;

      // Mark and convert SEA into LAND inside the defined play zone
      for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {

                  if (i >= *zone_top && i <= zone_bottom && j >= zone_left && j <= zone_right && game_board[i][j].type == SEA) {
                        game_board[i][j].type = LAND;
                  }

                  // Place the CROWN at the top center of the zone
                  if (i == *zone_top && j == width / 2) {
                        game_board[i][j].type = CROWN;
                  }

                  // Place the START at the bottom center of the zone
                  if (i == *start_x && j == *start_y) {
                        game_board[i][j].type = START;
                  }
            }
      }

      // Generate a path from START to CROWN
      *path = generate_path(game_board, start_x, start_y, path_length, *zone_top, zone_bottom, zone_left, zone_right, height, width);
}