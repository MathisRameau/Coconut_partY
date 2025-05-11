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
#include "turn_creation.h"
#include "turn.h"

int main(){

      srand(time(NULL));

      // display the game menu to the player
      display_menu();

      // declare game-related variables
      int height, width, start_x, start_y, path_length, tot_monkeys = 0, zone_top, num_tour_current = 0, count = 0, tot_crabs = 0, nb_ccn = 0;
      int nb_monkeys[3] = {0, 0, 0}, nb_crabs[3] = {0, 0, 0};
      bool running = true;
      char buffer[100];
      char* pseudo = ask_players_name(); // ask the player for their name (pseudo)
      Box* path = NULL;

      game_board_dimension(&height, &width); // get the game board dimensions from the player

      // initialize dynamic arrays for crabs, monkeys, and turns
      Box** game_board = gameBoard_creation(height, width);
      if (game_board == NULL) exit(1);

      Crab* tab_crab = NULL;
      Monkey* tab_monkey = NULL;
      Turn* tab_turn = NULL;

      smooth_gameBoard(game_board, height, width); // smooth the terrain for better gameplay
      play_area(game_board, &path, &path_length, height, width, &start_x, &start_y, &zone_top);

      // main game loop: each iteration represents one tour
      while (running){

            num_tour_current++;

            Turn current_turn = turn_creation(num_tour_current);

            // run the current turn: place monkeys, spawn crabs
            turn(
                  game_board,
                  current_turn,
                  &nb_ccn,
                  &tab_monkey,
                  nb_monkeys,
                  &tab_crab,
                  nb_crabs,
                  &tot_monkeys,
                  &tot_crabs,
                  path,
                  path_length,
                  height,
                  width,
                  start_x,
                  start_y,
                  zone_top,
                  pseudo
            );



            if(!current_turn.success){

                  running = false;

            }

      }

      // free all dynamically allocated memory before exiting
      free_gameBoard(game_board, height);
      free(tab_crab);
      free(path);
      free(tab_monkey);
      free(tab_turn);

      return 0;
}
