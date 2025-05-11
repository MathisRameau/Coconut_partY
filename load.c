#include <stdio.h>

#include "crabs_creation.h"
#include "monkey_creation.h"

// function to load the game state from a save file
Monkey* load_game(Crab* crab, int* monkey_count, int* nb_ccn) {

      FILE* save = fopen("sauvegarde.txt", "r");

      // open the save file in read mode
      if(save == NULL) {
            printf("Aucune sauvegarde trouvee.\n");
            return NULL;
      }

      // load information about crab and Monkey
      fprintf(save, "%d %d %d %d\n", &crab->x, &crab->y, &crab->path_index, &crab->hp);
      fprintf(save, "%d %d\n", monkey_count, nb_ccn);

      // Allocate memory for the monkeys
      Monkey* monkeys = malloc(sizeof(Monkey) * (*monkey_count));

      // load each monkey's state: position, shoot delay, and range
      for(int i = 0; i < *monkey_count; i++) {
            fprintf(save, "%d %d %d %d\n", &monkeys[i].x, &monkeys[i].y, &monkeys[i].time_shoot, &monkeys[i].range);
      }

      fclose(save);
      return monkeys;
}