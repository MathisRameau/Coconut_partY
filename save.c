#include <stdio.h>
#include "crabs_creation.h"
#include "monkey_creation.h"

// function to save the current state of the game to a file
void save_game(Crab crab, Monkey* monkeys, int monkey_count, int nb_ccn) {

      // open the save file in write mode
      FILE* save = fopen("sauvegarde.txt", "w");

      // if file couldn't be opened, print an error and return
      if(save == NULL) {

            printf("Erreur lors de la sauvegarde.\n");
            return;
      }

      // save information about crabs and Monkey
      fprintf(save, "%d %d %d %d\n", crab.x, crab.y, crab.path_index, crab.hp);
      fprintf(save, "%d %d\n", monkey_count, nb_ccn);

      // loop through each monkey and save their position, shoot delay (temps_tir), and range
      for(int i = 0; i < monkey_count; i++) {

            fprintf(save, "%d %d %d %d\n", monkeys[i].x, monkeys[i].y, monkeys[i].time_shoot, monkeys[i].range);
      }
      fclose(save);
}