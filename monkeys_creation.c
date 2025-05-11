#include <stdio.h>
#include <stdlib.h>
#include "monkeys_creation.h"

// function that assigns the monkey's characteristics based on its level
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

// function that creates a monkey with specified characteristics and position
Monkey create_monkey(Box** game_board, Box* path, int path_length, int height, int width, int level){

      if(!game_board || !path) exit(30);

      Monkey monkey;

      // ask for the monkey's position on the game board
      ask_monkey_position(game_board, path, path_length, height, width, &monkey.x, &monkey.y);

      monkey.time_shoot = 0;

      monkey.level = level;

      attribute_monkey(&monkey); // assign the monkey's characteristics based on its level

      game_board[monkey.x][monkey.y].type = MONKEY; // place the monkey on the game board

      return monkey;
}