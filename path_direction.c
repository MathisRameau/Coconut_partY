#include <stdio.h>
#include <stdlib.h>
#include "path_direction.h"

int choix_direction(int derniere_direction, Case case_chemin, int zone_top, int zone_bottom, int zone_left, int zone_right, int width) {
      int direction;
      int tries = 0;

      if (case_chemin.pos_x == zone_top) {
            if (case_chemin.pos_y < width / 2) {
                  direction = DROITE;
            } else {
                  direction = GAUCHE;
            }
      } else {

            do {
                  int r = rand() % 100;

                  // 0-39 = GAUCHE, 40-79 = DROITE, 80-99 = HAUT
                  if (r < 40) direction = GAUCHE;
                  else if (r < 80) direction = DROITE;
                  else direction = HAUT;

                  tries++;

                  int next_x = case_chemin.pos_x;
                  int next_y = case_chemin.pos_y;

                  if (direction == GAUCHE) next_y--;
                  else if (direction == DROITE) next_y++;
                  else if (direction == HAUT) next_x--;

                  if ((derniere_direction == DROITE && direction == GAUCHE) ||
                      (derniere_direction == GAUCHE && direction == DROITE)) continue;

                  if (next_x < zone_top || next_x > zone_bottom) continue;
                  if (next_y < zone_left || next_y > zone_right) continue;

                  break;

            } while (tries < 20);
      }

      return direction;
}