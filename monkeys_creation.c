#include <stdio.h>
#include <stdlib.h>
#include "monkeys_creation.h"

void attribute_monkey(Monkey* monkey){

      if(!monkey) return;

      if(monkey->level == 1){

            monkey->attack = 1;
            monkey->range = 1;

      }else if(monkey->level == 2){

            monkey->attack = 2;
            monkey->range = 1;

      }else if(monkey->level == 3){

            monkey->attack = 2;
            monkey->range = 2;

      }

}

Monkey create_monkey(Case** game_board, Case* chemin, int chemin_length, int height, int width, int level){

      if(!game_board || !chemin) exit(30);

      Monkey monkey;

      ask_monkey_position(game_board, chemin, chemin_length, height, width, &monkey.x, &monkey.y);

      monkey.temps_tir = 0;

      monkey.level = level;

      attribute_monkey(&monkey);

      game_board[monkey.x][monkey.y].type = MONKEY;

      return monkey;
}