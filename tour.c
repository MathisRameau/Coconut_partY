#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tour.h"
#include "monkeys_creation.h"
#include "crabs_creation.h"
#include "monkeys_store.h"
#include "display_crabs_tour.h"
#include "crabs_movement.h"
#include "monkey_attack.h"
#include "gameBoard_display.h"

void tour(Case** game_board,
          Tour* tab_tour,
          Tour tour_actuel,
          int* nb_ndc,
          Monkey** tab_monkeys,
          int nb_monkeys[3],
          Crab** tab_crabs,
          int nb_crabs[3],
          int* tot_monkeys,
          int* tot_crabs,
          Case* chemin,
          int chemin_length,
          int height,
          int width,
          int start_x,
          int start_y,
          int zone_top,
          char* pseudo){

      int count;
      int nb_nouveaux_crabes = 0;

      if (tour_actuel.num == 1 || tour_actuel.num == 2)
      {
            printf("Vous n'avez pas encore accès au magasin de singe\n");
            printf("Pour compenser cela, nous vous offrons un singe à placer!\n");
            nb_monkeys[0]++;
            (*tot_monkeys)++;
            Monkey* temp_monkeys =
                  realloc(*tab_monkeys,
                          (*tot_monkeys) * sizeof(Monkey));
            if (temp_monkeys == NULL)
            {
                  exit(30);
            }
            *tab_monkeys = temp_monkeys;
            (*tab_monkeys)[*tot_monkeys - 1] =
                  create_monkey(game_board,
                                chemin,
                                chemin_length,
                                height,
                                width,
                                1);
      }
      else
      {
            if (tour_actuel.num == 3)
            {
                  printf("Vous avez désormais accès au magasin de singe!\n\n");
            }
            monkeys_store(*tab_monkeys,
                          tot_monkeys,
                          nb_ndc);
      }

      if (tour_actuel.num == 1)
      {
            nb_crabs[0] = 2;
            nb_crabs[1] = 0;
            nb_crabs[2] = 0;
            nb_nouveaux_crabes = 2;
      }
      else if (tour_actuel.num == 2)
      {
            nb_crabs[0] = 1;
            nb_crabs[1] = 1;
            nb_crabs[2] = 0;
            nb_nouveaux_crabes = 2;
      }
      else if (tour_actuel.num == 3)
      {
            nb_crabs[0] = 2;
            nb_crabs[1] = 1;
            nb_crabs[2] = 0;
            nb_nouveaux_crabes = 3;
      }
      else if (tour_actuel.num < 10)
      {
            if (tour_actuel.num % 2 == 0)
            {
                  nb_crabs[0] = 1;
                  nb_crabs[1] = 2;
                  nb_crabs[2] = 0;
                  nb_nouveaux_crabes = 3;
            }
            else
            {
                  nb_crabs[0] = 2;
                  nb_crabs[1] = 2;
                  nb_crabs[2] = 0;
                  nb_nouveaux_crabes = 4;
            }
      }
      else
      {
            if (tour_actuel.num % 2 == 0)
            {
                  nb_crabs[0] = 2;
                  nb_crabs[1] = 4;
                  nb_crabs[2] = 0;
                  nb_nouveaux_crabes = 6;
            }
            else
            {
                  nb_crabs[0] = 2;
                  nb_crabs[1] = 4;
                  nb_crabs[2] = 1;
                  nb_nouveaux_crabes = 7;
            }
      }

      Crab* temp_crabs =
            realloc(*tab_crabs,
                    nb_nouveaux_crabes * sizeof(Crab));
      if (temp_crabs == NULL)
      {
            exit(2);
      }
      *tab_crabs = temp_crabs;

      for (int i = 0; i < nb_nouveaux_crabes; i++)
      {
            (*tab_crabs)[i] =
                  create_crab(game_board,
                              chemin,
                              height,
                              width,
                              start_x,
                              start_y);
      }

      *tot_crabs = nb_nouveaux_crabes;

      display_crabs_tour(nb_crabs,
                         *tot_crabs);

      while (tour_actuel.active)
      {
            if (rand() % 100 < 5)
            {
                  int i;
                  bool ok = false;
                  int tries = 0;
                  int max_tries = *tot_crabs * 2;

                  while (!ok &&
                         tries < max_tries)
                  {
                        i = rand() % (*tot_crabs);
                        if (!(*tab_crabs)[i].active &&
                            (*tab_crabs)[i].hp != 0)
                        {
                              ok = true;
                        }
                        tries++;
                  }

                  if (ok)
                  {
                        (*tab_crabs)[i].active = true;
                  }
            }

            move_crab(*tab_crabs,
                      game_board,
                      chemin,
                      chemin_length,
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
                              *nb_ndc,
                              tour_actuel.num);

            usleep(50000);

            count = 0;

            for (int k = 0; k < *tot_crabs; k++)
            {
                  if ((*tab_crabs)[k].y == zone_top &&
                      (*tab_crabs)[k].x == width / 2)
                  {
                        tour_actuel.active = false;
                        tour_actuel.success = false;
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
                        *nb_ndc += (*tab_crabs)[h].level;
                  }
                  tour_actuel.active = false;
            }
      }
}