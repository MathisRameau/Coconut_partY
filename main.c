#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

#include "gameBoard_dimension.h"
#include "gameBoard_creation.h"
#include "gameBoard_smooth.h"
#include "gameBoard_playArea.h"
#include "gameBoard_free.h"
#include "ask_players_name.h"
#include "menu_display.h"
#include "tour_creation.h"
#include "tour.h"

int main(){

      srand(time(NULL));

      display_menu();

      int height, width, start_x, start_y, chemin_length, tot_monkeys, zone_top, current_tour = 0, count = 0, tets = 0, tot_crabs = 0, nb_ndc = 0;
      int nb_monkeys[3] = {0, 0, 0}, nb_crabs[3] = {0, 0, 0};
      bool running = true;
      char buffer[100];
      char* pseudo = ask_players_name();
      Case* chemin = NULL;

      game_board_dimension(&height, &width);



      Case** game_board = gameBoard_creation(height, width);
      if (game_board == NULL) exit(1);

      Crab* tab_crab = NULL;
      Monkey* tab_monkey = NULL;
      Tour* tab_tour = NULL;

      smooth_gameBoard(game_board, height, width);
      play_area(game_board, &chemin, &chemin_length, height, width, &start_x, &start_y, &zone_top);

      while (running){

            current_tour++;

            Tour tour_actuel = tour_creation(current_tour);

            Tour* temp = realloc(tab_tour, current_tour * sizeof(Tour));

            if (temp == NULL){

                  exit(2);
            }

            tab_tour = temp;
            tab_tour[current_tour - 1] = tour_actuel;

            tour(game_board, tab_tour, tour_actuel, &nb_ndc, &tab_monkey,
                 (int*[]){ &nb_monkeys[0], &nb_monkeys[1], &nb_monkeys[2] },
                 &tab_crab, (int*[]){ &nb_crabs[0], &nb_crabs[1], &nb_crabs[2] },
                 &tot_monkeys, &tot_crabs, chemin, chemin_length, height, width,
                 start_x, start_y, zone_top, pseudo);

            if(!tour_actuel.success){

                  printf("bye bue");

                  running = false;

            }

      }

      free_gameBoard(game_board, height);
      free(tab_crab);
      free(tab_monkey);
      free(tab_tour);

      return 0;
}