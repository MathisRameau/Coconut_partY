      #include <stdio.h>
      #include <stdlib.h>
      #include "game_over.h"

      // Displays the game over screen and allows the player to restart or quit
      void game_over_menu(int turn, int nb_ccn, char* pseudo) {

            int choice;

            printf("\n\n========================================\n");
            printf("            GAME OVER\n");
            printf("========================================\n");
            printf("Tour: %d\n", turn);
            printf("Nombre de noix de coco gagnees : %d\n", nb_ccn);
            printf("========================================\n");
            printf("1. Nouvelle partie\n");
            printf("2. Quitter\n");
            printf("========================================\n");

            // Get valid user input (1 or 2)
            do {
                  printf("Votre choix --> ");
                  if(scanf("%d", &choice) != 1 || choice < 1 || choice > 2) {
                        printf("Choix invalide. Veuillez entrer 1 ou 2.\n");
                        while(getchar() != '\n');
                  }
            } while(choice < 1 || choice > 2);

            // Handle user choice
            if(choice == 1) {
                  printf("\nLancement d'une nouvelle partie...\n");

            } else {
                  printf("\nMerci d'avoir joué %s! A bientôt!\n", pseudo);
                  exit(0);
            }
      }
