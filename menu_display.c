#include <stdio.h>
#include <stdlib.h>
#include "clean_screen.h"
#include "menu_display.h"

// function to display the main menu of the game
void display_menu() {

      clear_screen();

      int choice = 0;

      printf("============================================================\n");
      printf("|                        COCONUT PARTY                     |\n");
      printf("|==========================================================|\n");
      printf("|  1. Nouvelle partie                                      |\n");
      printf("|  2. Quitter                                              |\n");
      printf("|  3. Reprendre une partie                                 |\n");
      printf("============================================================\n\n");
      printf("Bienvenue dans la jungle des crabes et des singes !\n");
      printf("Prepare-toi a defendre la couronne avec tes meilleurs tirs de coco !\n\n");

      // loop until the user selects a valid option
      do {
            printf("Entrez votre choix --> ");
            scanf("%d", &choice);
            getchar();

            // if the user selects "Quit", exit the game immediately
            if (choice == 2) {
                  printf("A BIENTOT SUR COCOCOCONUTTTT ! \n");
                  exit(3);
            }

            // if the user wants to resume a game
            if (choice == 3) {

                  FILE *save = fopen("sauvegarde.txt", "r");

                  if (save == NULL) {

                        printf("Aucune sauvegarde trouvee. On t'invite sur prochaine game !\n");
                        exit(4);

                  } else { // save file found, confirm resumption

                        printf("Reprise de la partie en cours...\n");
                        fclose(save);
                  }
            }

      } while (choice != 1); // continue looping until the user selects "New Game"
}