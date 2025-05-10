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
#include "filter_active_crabs.h"
#include "ask_monkey_position.h"
#include "monkey_attack.h"
#include "menu_display.h"
#include "ask_players_name.h"

int main(){

      srand(time(NULL));

      display_menu();

      int height, width, start_x, start_y, chemin_length, monkey_nombre, tour = 1, count = 0, tets = 0, nb_crabs = 0, nb_ndc = 5;
      bool running = true;
      char buffer[100];
      char* pseudo = ask_players_name();
      Case* chemin = NULL;

      game_board_dimension(&height, &width);

      Case** game_board = gameBoard_creation(height, width);
      if (game_board == NULL) exit(1);

      Crab* tab_crab = NULL;
      Monkey* tab_monkey = NULL;

      smooth_gameBoard(game_board, height, width);
      play_area(game_board, &chemin, &chemin_length, height, width, &start_x, &start_y);

      while (running) {

            if(tets == 0){

                  do{

                        printf("\nCombien de singes veux-tu placer (max 3 pour commencer)? --> ");
                        fgets(buffer, sizeof(buffer), stdin);

                        if (sscanf(buffer, "%d", &monkey_nombre) != 1 || monkey_nombre <= 0 || monkey_nombre > 3) {

                              printf("Entree invalide : veuillez entrer un nombre entier entre 1 et 3.\n");
                              monkey_nombre = 0;
                        }

                  }while(monkey_nombre == 0);

                  Monkey* temp = realloc(tab_monkey, monkey_nombre * sizeof(Monkey));

                  if (temp == NULL) {

                        free(tab_monkey);
                        exit(1);
                  }

                  tab_monkey = temp;

                  for(int i = 0; i < monkey_nombre; i++){

                        tab_monkey[i] = create_monkey(game_board, chemin, chemin_length, height, width, 1);

                  }
                  tets++;

            }

            if (rand() % 100 < 5) {

                  nb_crabs++;
                  Crab* temp = realloc(tab_crab, nb_crabs * sizeof(Crab));
                  if (temp == NULL) {

                        free(tab_crab);
                        exit(2);
                  }
                  tab_crab = temp;
                  tab_crab[nb_crabs - 1] = create_crab(game_board, chemin, height, width, start_x, start_y);
            }

            for(int i = 0; i < nb_crabs; i++){

                  if(tab_crab[i].active == false){

                        tab_crab = filter_active_crabs(tab_crab, &nb_crabs);
                        count++;

                  }

            }

            move_crab(tab_crab, game_board, chemin, chemin_length, nb_crabs);

            monkeys_attack_crabs( tab_monkey, tab_crab, monkey_nombre, nb_crabs, game_board);

            display_gameBoard(game_board, height, width, pseudo, nb_ndc, tour);

            usleep(70000);

            if(count >= 10){

                  running = false;

            }
      }

      free_gameBoard(game_board, height);
      free(tab_crab);

      return 0;
}