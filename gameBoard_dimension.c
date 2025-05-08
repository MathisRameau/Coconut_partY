#include <stdio.h>
#include <stdlib.h>
#include "gameBoard_dimension.h"

void game_board_dimension(int* height, int* width) {

      do {
            printf("De quelle taille veux-tu que le plateau soit ? --> ");
            if (scanf("%d", height) != 1 || *height <= 20 || *height >= 70) {

                  printf("\nVeuillez entrer un entier superieur à 20 et inferieur à 70 pour la hauteur.\n\n");
                  while (getchar() != '\n');
                  *height = 0;
            }
      } while (*height <= 0);

      *width = *height * 2;
}
