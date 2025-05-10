#include <stdio.h>
#include <stdlib.h>
#include "clean_screen.h"
#include "menu_display.h"

void display_menu() {

      clear_screen();

      int choix = 0;

      printf("============================================================\n");
      printf("|                        COCONUT PARTY                     |\n");
      printf("|==========================================================|\n");
      printf("|  1. Nouvelle partie                                      |\n");
      printf("|  2. Quitter                                              |\n");
      printf("|  3. Reprendre une partie                                 |\n");
      printf("============================================================\n\n");
      printf("Bienvenue dans la jungle des crabes et des singes !\n");
      printf("Prepare-toi a defendre la couronne avec tes meilleurs tirs de coco !\n\n");

      do {
            printf("Entrez votre choix --> ");
            scanf("%d", &choix);
            getchar();

            if (choix == 2) {
                  printf("A BIENTOT SUR COCOCOCONUTTTT ! \n");
                  exit(3);
            }

            if (choix == 3) {

                  FILE *save = fopen("sauvegarde.txt", "r");

                  if (save == NULL) {

                        printf("Aucune sauvegarde trouvee. On t'invite sur prochaine game !\n");
                        exit(4);

                  } else {

                        printf("Reprise de la partie en cours...\n");
                        fclose(save);
                  }
            }

      } while (choix != 1);
}