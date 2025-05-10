#include <stdio.h>
#include <stdlib.h>
#include "gameBoard_creation.h"
#include "ask_monkey_position.h"

void ask_monkey_position(Case** game_board, Case* chemin, int chemin_length, int height, int width, int* x, int* y) {

      if(!game_board || !chemin || !x || !y) exit(20);

      char input[100];

      int x_choisie;
      int y_choisie;

      typedef struct {
            int x;
            int y;
      } Position;

      Position valid_positions[1000];

      int count = 0;
      int nb_colonne = 0;

      printf("\nVoici les cases ou tu peux placer un singe (adjacentes au chemin) :\n\n");

      int dx[4] = {-1, 1, 0, 0};
      int dy[4] = {0, 0, -1, 1};

      for (int i = 0; i < chemin_length; i++) {

            int cx = chemin[i].pos_x;
            int cy = chemin[i].pos_y;

            for (int j = 0; j < 4; j++) {

                  int nx = cx + dx[j];
                  int ny = cy + dy[j];

                  if (nx >= 0 && nx < height &&ny >= 0 &&ny < width && game_board[nx][ny].type == LAND) {

                        printf("(%2d,%2d)   ", nx, ny);

                        valid_positions[count].x = nx;
                        valid_positions[count].y = ny;

                        count++;
                        nb_colonne++;

                        if (nb_colonne % 5 == 0) {
                              printf("\n");
                        }
                  }
            }
      }

      int valide = 0;

      do {

            printf("\n\nOu veux-tu placer ton singe ? (ligne puis colonne) --> ");

            if (fgets(input, sizeof(input), stdin) == NULL) {
                  printf("Erreur de lecture.\n");
                  continue;
            }

            if (sscanf(input, "%d %d", &x_choisie, &y_choisie) != 2) {
                  printf("Entree invalide. Veuillez entrer deux entiers separes par un espace.\n");
                  continue;
            }

            int ok = 0;

            for (int i = 0; i < count; i++) {

                  if (valid_positions[i].x == x_choisie &&
                      valid_positions[i].y == y_choisie) {

                        ok = 1;
                        *x = x_choisie;
                        *y = y_choisie;
                        break;
                  }
            }

            if (ok) {

                  game_board[x_choisie][y_choisie].type = MONKEY;
                  printf("Singe place en (%d, %d).\n", x_choisie, y_choisie);
                  valide = 1;

            } else {

                  printf("Cette position n'est pas valide. Choisis une parmi celles proposees.\n");
            }

      } while (!valide);
}