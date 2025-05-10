#include <stdio.h>
#include <stdlib.h>
#include "clean_screen.h"
#include "menu_display.h"
#include "load.h"

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
                  
                  Crab crab;
                  int monkey_count, nb_ndc;
                  Monkey* monkeys = load_game(&crab, &monkey_count, &nb_ndc); 
                  FILE *save = fopen("sauvegarde.txt", "r");

                  if (monkeys == NULL) {

                        printf("Erreur lors du chargement.\n");
                        exit(1);

                    } 
            
                    printf("Reprise de la partie en cours...\n");
            }

      } while (choix != 1);
}
