#include <stdio.h>
#include <stdlib.h>
#include "monkey_attack.h"

// function that handles the monkeys attacking the crabs
void monkeys_attack_crabs(Monkey* tab_monkeys, Crab* tab_crab, int nb_monkeys, int nb_crabs, Box** game_board){

      // check pointers to avoid segmentation errors
      if(!game_board) exit(29);

      if(!tab_monkeys || !tab_crab || nb_monkeys <= 0 || nb_crabs <= 0) return;

      // loops through all crabs and monkeys
      for (int i = 0; i < nb_monkeys; i++) {

            for (int k = 0; k < nb_crabs; k++) {

                  int dx[4] = {-1, 1, 0, 0};
                  int dy[4] = {0, 0, -1, 1};

                  for (int j = 0; j < 4; j++) {

                        int mx = tab_monkeys[i].x + dx[j];
                        int my = tab_monkeys[i].y + dy[j];

                        // if a crab is at an adjacent position to the monkey and is still alive
                        if (mx == tab_crab[k].x && my == tab_crab[k].y && tab_crab[k].hp > 0) {

                              tab_crab[k].hp -= 1;

                              // if a crab is at an adjacent position to the monkey and is still alive
                              if (tab_crab[k].hp <= 0) {
                                    tab_crab[k].active = false;
                                    game_board[tab_crab[k].x][tab_crab[k].y].type = PATH;
                              }

                              break;
                        }
                  }
            }
      }
}