#include <stdio.h>
#include <stdlib.h>
#include "monkeys_store.h"
#include "menu_display.h"

// constants representing the menu choices
#define BUY 1
#define IMPROVE 2
#define BREAK 3

void monkeys_store(Monkey* tab_monkey, int* nb_monkeys, int* nb_ccn, Box** game_board, Box* path, int path_length, int height, int width) {

      if (!tab_monkey || !nb_monkeys || !nb_ccn) return;

      // if the player has fewer than 3 coconuts, they can't access the store
      if (*nb_ccn < 3) {
            printf("Vous n'avez pas assez de noix de coco pour entrer dans le magasin de singe\n");
            return;
      }

      int choice;
      int purchase_price[3] = {4, 10, 15}; // prices for buying level 1, 2, and 3 monkeys
      int price_improvement[3] = {3, 9, 13}; // prices for upgrading from level 1→2 and 2→3

      printf("Bienvenue au magasin de singe!\n\n");

      printf("============================================================\n");
      printf("|                        COCONUT PARTY                     |\n");
      printf("|==========================================================|\n");
      printf("|  1. Acheter un singe                                     |\n");
      printf("|  2. Améliorer un singe                                   |\n");
      printf("|  3. Mettre pause                                         |\n");
      printf("============================================================\n\n");

      do {
            printf("Entrez un nombre entre 1 et 3 : ");
      } while (scanf("%d", &choice) != 1 || choice < 1 || choice > 3);

       // if the player chooses to buy or upgrade, show how many coconuts they have
      if (choice == BUY || choice == IMPROVE) {
            printf("Vous avez actuellement %d noix de coco!\n", *nb_ccn);
      }

      // buy a Monkey
      if (choice == BUY) {

            int purchase;

            // show available monkey levels and prices
            printf("Quel niveau de singe voulez-vous acheter? :\n\n");

            printf("============================================================\n");
            printf("|                        COCONUT PARTY                     |\n");
            printf("|==========================================================|\n");
            printf("|  1. Niveau 1 : %d noix de coco                           |\n", purchase_price[0]);
            printf("|  2. Niveau 2 : %d noix de coco                           |\n", purchase_price[1]);
            printf("|  3. Niveau 3 : %d noix de coco                           |\n", purchase_price[2]);
            printf("============================================================\n\n");

            // get the player's choice for monkey level
            do {
                  printf("Entrez votre choice --> ");
                  if (scanf("%d", &purchase) != 1 || purchase < 1 || purchase > 3) {
                        printf("Veuillez entrer un entier correspondant à un des choice ci-dessus\n");
                        while (getchar() != '\n');
                  }
            } while (purchase < 1 || purchase > 3);

            // check if player has enough coconuts
            if (*nb_ccn < purchase_price[purchase - 1]) {
                  printf("On ne berne pas un singe! Vous n'avez pas assez de noix de coco!\n");
                  printf("Pour la peine, le magasin de singe se ferme!\n");
            } else {
                  (*nb_monkeys)++;
                  *nb_ccn -= purchase_price[purchase - 1];

                  printf("Félicitations! Vous avez acheté un singe de niveau %d!\n", purchase);
                  printf("Vous avez maintenant %d noix de coco!\n", *nb_ccn);

                  Monkey* temp = realloc(tab_monkey, *nb_monkeys * sizeof(Monkey));

                  if (temp == NULL) {
                        free(tab_monkey);
                        exit(6);
                  }

                  tab_monkey = temp;

                  tab_monkey[*nb_monkeys - 1] = create_monkey(game_board, path, path_length, height, width, 1);
            }

      // upgrade a Monkey
      } else if (choice == IMPROVE) {

            int improvement;

             // show upgrade prices for each level
            printf("Voici les prix pour les améliorations des singes en fonction de leur niveau :\n\n");

            printf("============================================================\n");
            printf("|                        COCONUT PARTY                     |\n");
            printf("|==========================================================|\n");
            printf("|  Niveau 1 : %d noix de coco                           |\n", price_improvement[0]);
            printf("|  Niveau 2 : %d noix de coco                           |\n", price_improvement[1]);
            printf("|  Niveau 3 : %d noix de coco                           |\n", price_improvement[2]);
            printf("============================================================\n\n");

            printf("Parmi vos singes ci-dessous, lequel voulez-vous améliorer? :\n\n");

            for (int i = 0; i < *nb_monkeys; i++) {
                  printf("Singe %d :\n", i + 1);
                  printf("   Ligne %d\n", tab_monkey[i].x);
                  printf("   Colonne %d\n", tab_monkey[i].y);
                  printf("   Niveau %d\n\n", tab_monkey[i].level);
            }

            printf("\nAttention, vous ne pouvez pas améliorer un singe s'il est déjà de niveau 3!\n\n");

            // get which monkey to upgrade
            do {
                  printf("Entrez le numéro du singe --> ");
                  if (scanf("%d", &improvement) != 1 || improvement < 1 || improvement > *nb_monkeys) {
                        printf("Veuillez entrer un entier correspondant à un des singes ci-dessus\n");
                        while (getchar() != '\n');
                  }
            } while (improvement < 1 || improvement > *nb_monkeys);

            improvement--;

            if (tab_monkey[improvement].level == 3) {
                  printf("On ne berne pas un singe! Vous ne pouvez pas améliorer un singe de niveau 3\n");
            } else if (*nb_ccn < price_improvement[tab_monkey[improvement].level]) {
                  printf("On ne berne pas un singe! Vous n'avez pas assez de noix de coco!\n");
            } else {
                  tab_monkey[improvement].level++;
                  attribute_monkey(&tab_monkey[improvement]);

                  *nb_ccn -= price_improvement[tab_monkey[improvement].level - 1];

                  printf("Félicitations! Vous avez amélioré le singe %d : niveau %d --> niveau %d\n",
                        improvement + 1,
                        tab_monkey[improvement].level - 1,
                        tab_monkey[improvement].level);

                  printf("Vous avez maintenant %d noix de coco!\n", *nb_ccn);
            }

      // pause the Game
      } else if (choice == BREAK) {
            printf("Pas de soucis, nous enregistrons la partie!\n");
            display_menu();
      }

      printf("Merci d'être passé par le magasin de singe! Nous espérons vous revoir bientôt!\n");
}