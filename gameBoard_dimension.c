#include <stdio.h>
#include <stdlib.h>
#include "gameBoard_dimension.h"

void game_board_dimension(int* height, int* width) {

      do {
            printf("De quelle hauteur veux-tu que le plateau soit ? --> ");
            if (scanf("%d", height) != 1 || *height <= 10) {

                  printf("Veuillez entrer un entier supérieur à 10 pour la hauteur.\n");
                  while (getchar() != '\n');
                  *height = 0;
            }
      } while (*height <= 0);

      do {
            printf("De quelle largeur veux-tu que le plateau soit ? --> ");
            if (scanf("%d", width) != 1 || *width <= 10) {

                  printf("Veuillez entrer un entier supérieur à 10 valide pour la largeur.\n");
                  while (getchar() != '\n');
                  *width = 0;
            }
      } while (*width <= 0);
}
