#include <stdio.h>
#include <stdlib.h>
#include "gameBoard_dimension.h"

// Asks the user for the board height and sets the width automatically
void game_board_dimension(int* height, int* width){

      if(!height || !width) exit(24);

      char buffer[100];
      int valid = 0;

      // Loop until the user enters a valid height between 20 and 70
      while (!valid) {

            printf("\nDe quelle taille veux-tu que le plateau soit (20-70)? --> ");

            // Read user input and convert to integer
            if (fgets(buffer, sizeof(buffer), stdin) && sscanf(buffer, "%d", height) == 1 && *height > 20 && *height < 70) {

                  valid = 1;
            } else {

                  printf("\nVeuillez entrer un entier superieur à 20 et inferieur à 70 pour la hauteur.\n\n");
            }
      }

      *width = *height * 2;
}