#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include "gameBoard_dimension.h"
#include "gameBoard_creation.h"
#include "gameBoard_smooth.h"
#include "gameBoard_playArea.h"
#include "gameBoard_display.h"
#include "gameBoard_free.h"
#include "monkeys_creation.h"
#include "crabs_creation.h"
#include "crabs_movement.h"
#include "generate_crab.h"
#include "filter_active_crabs.h"

int main(){

      srand(time(NULL));

      int height, width, start_x, start_y, chemin_length, count = 0, nb_crabs = 0, arrived = 0;
      Case* chemin;
      bool running = true;

      game_board_dimension(&height, &width);

      Case** game_board = gameBoard_creation(height, width);
      if (game_board == NULL) exit(1);
      Crab* tab_crab = NULL;

      smooth_gameBoard(game_board, height, width);
      play_area(game_board, &chemin, &chemin_length, height, width, &start_x, &start_y);
      Monkey monkey = create_monkey(game_board, height, width);

      while (running) {

            if (rand() % 100 < 5) {

                  nb_crabs++;
                  Crab* temp = realloc(tab_crab, nb_crabs * sizeof(Crab));
                  if (temp == NULL) {

                        free(tab_crab);
                        exit(1);
                  }
                  tab_crab = temp;
                  tab_crab[nb_crabs - 1] = create_crab(game_board, chemin, height, width, start_x, start_y);
            }

            move_crab(tab_crab, game_board, chemin, chemin_length, nb_crabs);

            for(int i = 0; i < nb_crabs; i++){

                  if(tab_crab[i].active == false){

                        count++;

                  }

            }

            display_gameBoard(game_board, height, width);

            usleep(70000);

            if(count >= 10){

                  running = false;

            }

            tab_crab = filter_active_crabs(tab_crab, &nb_crabs);
      }
      free_gameBoard(game_board, height);
      free(tab_crab);
      return 0;
}