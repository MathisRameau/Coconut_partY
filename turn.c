#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "turn.h"
#include "monkeys_creation.h"
#include "crabs_creation.h"
#include "clean_screen.h"
#include "monkeys_store.h"
#include "display_crabs_turn.h"
#include "crabs_movement.h"
#include "monkey_attack.h"
#include "gameBoard_display.h"

void turn(Box** game_board,
          Turn current_turn,
          int* nb_ccn,
          Monkey** tab_monkeys,
          int nb_monkeys[3],
          Crab** tab_crabs,
          int nb_crabs[3],
          int* tot_monkeys,
          int* tot_crabs,
          Box* path,
          int path_length,
          int height,
          int width,
          int start_x,
          int start_y,
          int zone_top,
          char* pseudo){

      int count, index = 0;
      int nb_new_crabes = 0;

      clear_screen();

      printf("\n\n************************** Tour %d **************************\n\n", current_turn.num);

      if (current_turn.num == 1 || current_turn.num == 2)
      {
            printf("Vous n'avez pas encore accès au magasin de singe\n");
            printf("Pour compenser cela, nous vous offrons un singe à placer!\n");
            nb_monkeys[0]++;
            (*tot_monkeys)++;

            if (*tab_monkeys == NULL) {
                *tab_monkeys = malloc(sizeof(Monkey));
            }

            Monkey* temp_monkeys = realloc(*tab_monkeys, (*tot_monkeys) * sizeof(Monkey));

            if (temp_monkeys == NULL){

                  exit(30);
            }
            *tab_monkeys = temp_monkeys;
            (*tab_monkeys)[*tot_monkeys - 1] =
                  create_monkey(game_board,
                                path,
                                path_length,
                                height,
                                width,
                                1);
      }
      else
      {
            if (current_turn.num == 3)
            {
                  printf("Vous avez désormais accès au magasin de singe!\n\n");
            }
            monkeys_store(*tab_monkeys,
                          tot_monkeys,
                          nb_ccn,
                          game_board,
                          path,
                          path_length,
                          height,
                          width);
      }

      if (current_turn.num == 1)
      {
            nb_crabs[0] = 2;
            nb_crabs[1] = 0;
            nb_crabs[2] = 0;
            nb_new_crabes = 2;
      }
      else if (current_turn.num == 2)
      {
            nb_crabs[0] = 1;
            nb_crabs[1] = 1;
            nb_crabs[2] = 0;
            nb_new_crabes = 2;
      }
      else if (current_turn.num == 3)
      {
            nb_crabs[0] = 2;
            nb_crabs[1] = 1;
            nb_crabs[2] = 0;
            nb_new_crabes = 3;
      }
      else if (current_turn.num < 10)
      {
            if (current_turn.num % 2 == 0)
            {
                  nb_crabs[0] = 1;
                  nb_crabs[1] = 2;
                  nb_crabs[2] = 0;
                  nb_new_crabes = 3;
            }
            else
            {
                  nb_crabs[0] = 2;
                  nb_crabs[1] = 2;
                  nb_crabs[2] = 0;
                  nb_new_crabes = 4;
            }
      }
      else
      {
            if (current_turn.num % 2 == 0)
            {
                  nb_crabs[0] = 2;
                  nb_crabs[1] = 4;
                  nb_crabs[2] = 0;
                  nb_new_crabes = 6;
            }
            else
            {
                  nb_crabs[0] = 2;
                  nb_crabs[1] = 4;
                  nb_crabs[2] = 1;
                  nb_new_crabes = 7;
            }
      }

      Crab* temp_crabs =
            realloc(*tab_crabs,
                    nb_new_crabes * sizeof(Crab));
      if (temp_crabs == NULL)
      {
            exit(2);
      }
      *tab_crabs = temp_crabs;

      for (int i = 0; i < nb_new_crabes; i++)
      {
            (*tab_crabs)[i] =
                  create_crab(game_board,
                              path,
                              height,
                              width,
                              start_x,
                              start_y);
      }

      *tot_crabs = nb_new_crabes;

      display_crabs_turn(nb_crabs,
                         *tot_crabs);

      while (current_turn.active)
      {
            if (rand() % 100 < 5 && index < *tot_crabs){

                  (*tab_crabs)[index++].active = 1;

            }


            move_crab(*tab_crabs,
                      game_board,
                      path,
                      path_length,
                      *tot_crabs);

            monkeys_attack_crabs(*tab_monkeys,
                                 *tab_crabs,
                                 *tot_monkeys,
                                 *tot_crabs,
                                 game_board);

            display_gameBoard(game_board,
                              height,
                              width,
                              pseudo,
                              *nb_ccn,
                              current_turn.num);

            usleep(70000);

            count = 0;

            for (int k = 0; k < *tot_crabs; k++)
            {
                  if ((*tab_crabs)[k].y == zone_top &&
                      (*tab_crabs)[k].x == width / 2)
                  {
                        current_turn.active = false;
                        current_turn.success = false;
                  }

                  if (!(*tab_crabs)[k].active &&
                      (*tab_crabs)[k].hp == 0)
                  {
                        count++;
                  }
            }

            if (count == *tot_crabs)
            {
                  for (int h = 0; h < *tot_crabs; h++)
                  {
                        *nb_ccn += (*tab_crabs)[h].level;
                  }
                  current_turn.active = false;
            }
      }
}