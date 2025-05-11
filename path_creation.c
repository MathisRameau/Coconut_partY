#include <stdio.h>
#include <stdlib.h>
#include "path_creation.h"

Box* generate_path(Box** game_board, int* start_x, int* start_y, int* path_length, int zone_top, int zone_bottom, int zone_left, int zone_right, int height, int width){

      Box* path = NULL;  // pointer to hold the generated path

       // check for invalid input
      if(!game_board || !start_x || !start_y || !path_length) return path;

      *path_length = 0;
      int last_direction = 0;

      // initialize starting point of the path
      Box box_path = {
            .pos_x = *start_x,
            .pos_y = *start_y
      };

      // determine the initial direction of the path
      int direction = 0;
      if (box_path.pos_y == *start_y) {
            direction = (box_path.pos_x < *start_x) ? RIGHT : LEFT;
      } else {
            direction = UP;
      }

      // begin path generation loop
      while (1) {
            if (*path_length > 5000) {
                  printf("Trop d'itérations. Chemin interrompu.\n");
                  break;
            }

            (*path_length)++;

            // reallocate memory to store the new path cell
            Box* temp = realloc(path, (*path_length) * sizeof(Box));
            if (!temp) {
                  printf("Erreur d'allocation mémoire pour le path\n");
                  free(path);
                  return NULL;
            }
            path = temp;
            path[*path_length - 1] = box_path;

            // choose a new direction based on the previous one
            direction = choice_direction(last_direction, box_path,
                                         zone_top, zone_bottom,
                                         zone_left, zone_right, width);
            last_direction = direction;

            int next_x = box_path.pos_x;
            int next_y = box_path.pos_y;

            if (direction == LEFT) next_y--;
            else if (direction == RIGHT) next_y++;
            else if (direction == UP) next_x--;

            if (next_x < zone_top || next_x > zone_bottom ||
                next_y < zone_left || next_y > zone_right)
                  continue;

            if (next_x < 0 || next_y < 0 || next_x >= height || next_y >= width)
                  continue;

            if (game_board[next_x][next_y].type == CROWN)
                  break;

            box_path.pos_x = next_x;
            box_path.pos_y = next_y;

            if (game_board[next_x][next_y].type == LAND)
                  game_board[next_x][next_y].type = PATH;
      }

      return path;
}