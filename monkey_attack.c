#include <stdio.h>
#include <stdlib.h>
#include "monkey_attack.h"

void monkeys_attack_crabs(Monkey* tab_monkeys, Crab* tab_crab, int monkey_nombre, int nb_crabs, Case** game_board){

      if(!game_board) exit(29);
      if(!tab_monkeys || !tab_crab || monkey_nombre <= 0 || nb_crabs <= 0) return;

      for (int i = 0; i < monkey_nombre; i++) {

            for (int k = 0; k < nb_crabs; k++) {

                  int dx[4] = {-1, 1, 0, 0};
                  int dy[4] = {0, 0, -1, 1};

                  for (int j = 0; j < 4; j++) {

                        int mx = tab_monkeys[i].x + dx[j];
                        int my = tab_monkeys[i].y + dy[j];

                        if (mx == tab_crab[k].x && my == tab_crab[k].y && tab_crab[k].hp > 0) {

                              tab_crab[k].hp -= 1;

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