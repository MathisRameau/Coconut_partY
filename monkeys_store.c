#include <stdio.h>
#include <stdlib.h>
#include "monkeys_store.h"
#include "save.h"

void monkeys_store(Monkey* tab_monkey, int* nb_monkeys, int* nb_ndc){

      if(!tab_monkey || !nb_monkeys || !nb_ndc ) return;
      if (*nb_ndc <= 0) {
            printf("Vous n'avez pas assez de noix de coco pour entrer dans le magasin de singe.\n");
            return;
      }

      int choix;
      int prix_achat[3] = {4, 10, 15};
      int prix_amelioration[3] = {3, 9, 13};

      printf("============================================================\n");
      printf("|                        COCONUT PARTY                     |\n");
      printf("|==========================================================|\n");
      printf("|  1. Acheter un singe                                     |\n");
      printf("|  2. Améliorer un singe                                   |\n");
      printf("|  3. Mettre pause                                         |\n");
      printf("============================================================\n\n");

      do{
            printf("Entrez votre choix --> ");

            if(scanf("%d", &choix) != 1 || choix < 1 || choix > 3){

                  printf("Veuillez entrer un entier correspondant à un des choix ci-dessus");
                  while (getchar() != '\n');

            }

      }while(scanf("%d", &choix) != 1 || choix < 1 || choix < 3);

      if(choix == ACHETER || choix == AMELIORER){

            printf("Vous avez actuellement %d noix de coco!\n", *nb_ndc);

      }

      if (choix == ACHETER) {

            int achat;

            printf("Quel niveau de singe voulez-vous acheter? :\n\n");

            printf("============================================================\n");
            printf("|                        COCONUT PARTY                     |\n");
            printf("|==========================================================|\n");
            printf("|  1. Niveau 1 : %d noix de coco                           |\n", prix_achat[1]);
            printf("|  2. Niveau 2 : %d noix de coco                           |\n", prix_achat[2]);
            printf("|  3. Niveau 3 : %d noix de coco                           |\n", prix_achat[3]);
            printf("============================================================\n\n");

            do{
                  printf("Entrez votre choix --> ");

                  if(scanf("%d", &achat) != 1 || achat < 1 || achat < 3){

                        printf("Veuillez entrer un entier correspondant à un des choix ci-dessus");
                        while (getchar() != '\n');

                  }

            }while(scanf("%d", &achat) != 1 || achat < 1 || achat < 3);

            if(*nb_ndc < prix_achat[achat]){

                  printf("On ne berne pas un singe ! Vous n'avez pas assez de noix de coco !\n");
                  printf("Pour la peine, le magasin de singe se ferme !\n");

            }else{

                  *nb_monkeys++;

                  *nb_ndc -= prix_achat[achat];

                  printf("Félicitations! Vous avez acheté un singe de niveau %d !\n", achat);
                  printf("Vous avez maintenant %d noix de coco !\n", *nb_ndc);

                  Monkey* temp = realloc(tab_monkey, *nb_monkeys * sizeof(Monkey));

                  if (temp == NULL) {

                        free(tab_monkey);
                        exit(6);
                  }

                  tab_monkey = temp;

            }

      }else if (choix == AMELIORER) {

            int amelioration;

            printf("Voici les prix pour les améliorations des singes en fonction de leur niveau :\n\n");

            printf("============================================================\n");
            printf("|                        COCONUT PARTY                     |\n");
            printf("|==========================================================|\n");
            printf("|  Niveau 1 : %d noix de coco                           |\n", prix_amelioration[1]);
            printf("|  Niveau 2 : %d noix de coco                           |\n", prix_amelioration[2]);
            printf("|  Niveau 3 : %d noix de coco                           |\n", prix_amelioration[3]);
            printf("============================================================\n\n");

            printf("Parmi vos singes ci-dessous, lequel voulez-vous améliorer ? :\n\n");

            for(int i = 0; i < *nb_monkeys; i++){

                  printf("Singe %d :\n", i + 1);
                  printf("   Ligne %d\n", tab_monkey[i].x);
                  printf("   Colonne %d\n", tab_monkey[i].y);
                  printf("   Niveau %d\n\n", tab_monkey[i].level);

            }

            printf("\nAttention, vous ne pouvez pas améliorer un singe s'il est déjà de niveau 3!\n\n");

            do{
                  printf("Entrez le numéro du singe --> ");

                  if(scanf("%d"), &amelioration != 1 || amelioration < 1 || amelioration < *nb_monkeys){

                        printf("Veuillez entrer un entier correspondant à un des singes ci-dessus");
                        while (getchar() != '\n');

                  }

            }while(scanf("%d"), &amelioration != 1 || amelioration < 1 || amelioration < *nb_monkeys);

            if(tab_monkey[amelioration].level == 3){

                  printf("On ne berne pas un singe! Vous ne pouvez pas améliorer un singe de niveau 3\n");
                  printf("Pour la peine, le magasin de singe se ferme!\n");

            }else if(*nb_ndc < prix_amelioration[tab_monkey[amelioration].level]){

                  printf("On ne berne pas un singe! Vous n'avez pas assez de noix de coco!\n");
                  printf("Pour la peine, le magasin de singe se ferme!\n");

            }else{

                   tab_monkey[amelioration].level++;

                   attribute_monkey(&tab_monkey[amelioration]);

                   *nb_ndc -= prix_amelioration[tab_monkey[amelioration].level];

                   printf("Félicitations! Vous avez améliorer le singe %d : niveau %d --> niveau %d\n", amelioration, tab_monkey[amelioration].level - 1, tab_monkey[amelioration].level);
                   printf("Vous avez maintenant %d noix de coco!\n", *nb_ndc);

            }

      }else if(choix == PAUSE){

            printf("Pas de soucis, nous enregistrons la partie !\n");
            save_game(crab, tab_monkey, *nb_monkeys, *nb_ndc);
      }

      printf("Merci d'être passé par le magasin de singe! Nous esperons vous revoir bientôt!\n")
}
