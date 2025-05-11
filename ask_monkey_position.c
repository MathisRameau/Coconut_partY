#include <stdio.h>
#include <stdlib.h>
#include "gameBoard_creation.h"
#include "ask_monkey_position.h"

// function to ask the user where to place a monkey on the map (must be adjacent to the path)
void ask_monkey_position(Box** game_board, Box* path, int path_length, int height, int width, int* x, int* y) {

      if(!game_board || !path || !x || !y) exit(20);

      char input[100];

      int x_chosen;
      int y_chosen;

      // struct to save valid positions where monkeys can be placed
      typedef struct {
            int x;
            int y;
      } Position;

      Position valid_positions[1000];

      int count = 0;
      int nb_column = 0;

      // display valid monkey placement positions (LAND tiles adjacent to the path)
      printf("\nVoici les cases ou tu peux placer un singe (adjacentes au chemin) :\n\n");

      int dx[4] = {-1, 1, 0, 0};
      int dy[4] = {0, 0, -1, 1};

      for (int i = 0; i < path_length; i++) {

            int cx = path[i].pos_x;
            int cy = path[i].pos_y;

            for (int j = 0; j < 4; j++) {

                  int nx = cx + dx[j];
                  int ny = cy + dy[j];

                  if (nx >= 0 && nx < height &&ny >= 0 &&ny < width && game_board[nx][ny].type == LAND) {

                        printf("(%2d,%2d)   ", nx, ny);

                        valid_positions[count].x = nx;
                        valid_positions[count].y = ny;

                        count++;
                        nb_column++;

                        if (nb_column % 5 == 0) {
                              printf("\n");
                        }
                  }
            }
      }

      int valid = 0;

      // loop until the user enters a valid position among the propositions
      do {

            printf("\n\nOu veux-tu placer ton singe ? (ligne puis colonne) --> ");

            if (fgets(input, sizeof(input), stdin) == NULL) {
                  printf("Erreur de lecture.\n");
                  continue;
            }

            if (sscanf(input, "%d %d", &x_chosen, &y_chosen) != 2) {
                  printf("Entree invalide. Veuillez entrer deux entiers separes par un espace.\n");
                  continue;
            }

            int ok = 0;

            for (int i = 0; i < count; i++) {

                  if (valid_positions[i].x == x_chosen &&
                      valid_positions[i].y == y_chosen) {

                        ok = 1;
                        *x = x_chosen;
                        *y = y_chosen;
                        break;
                  }
            }

            if (ok) {

                  game_board[x_chosen][y_chosen].type = MONKEY;
                  printf("Singe place en (%d, %d).\n", x_chosen, y_chosen);
                  valid = 1;

            } else {

                  printf("Cette position n'est pas valide. Choisis en une parmi celles proposées.\n");
            }

      } while (!valid);
}