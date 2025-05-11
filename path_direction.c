#include <stdio.h>
#include <stdlib.h>
#include "path_direction.h"

// this function chooses the next direction in which the path should extend
int choice_direction(int last_direction, Box box_path, int zone_top, int zone_bottom, int zone_left, int zone_right, int width){

      int direction;
      int tries = 0;

      // if the current case is on the topmost row of the zone
      if (box_path.pos_x == zone_top) {

            // if the path is on the left half of the board, move right
            if (box_path.pos_y < width / 2) {

                  direction = RIGHT;

            } else {

                  direction = LEFT;
            }
      } else {

            // if the path is on the left half of the board, move right
            do {
                  int r = rand() % 100;

                  if (r < 40) direction = LEFT;
                  else if (r < 80) direction = RIGHT;
                  else direction = UP;

                  tries++;

                  // calculate the coordinates for the potential next step
                  int next_x = box_path.pos_x;
                  int next_y = box_path.pos_y;

                  if (direction == LEFT) next_y--;
                  else if (direction == RIGHT) next_y++;
                  else if (direction == UP) next_x--;

                  // prevent immediate U-turns (left-right or right-left)
                  if ((last_direction == RIGHT && direction == LEFT) ||
                      (last_direction == LEFT && direction == RIGHT)) continue;

                  // ensure the next cell stays within the allowed generation zone
                  if (next_x < zone_top || next_x > zone_bottom) continue;
                  if (next_y < zone_left || next_y > zone_right) continue;

                  // if all constraints are satisfied, exit loop
                  break;

            } while (tries < 20);
      }

      return direction;
}