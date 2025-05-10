#include <stdio.h>

#include "crabs_creation.h"
#include "monkey_creation.h"

void save_game(Crab crab, Monkey* monkeys, int monkey_count, int nb_ndc) {
    FILE* save = fopen("sauvegarde.txt", "w");
    
    if(save == NULL) {
        printf("Erreur lors de la sauvegarde.\n");
        return;
    }

    fprintf(save, "%d %d %d %d\n", crab.x, crab.y, crab.path_index, crab.hp);
    fprintf(save, "%d %d\n", monkey_count, nb_ndc);

    for(int i = 0; i < monkey_count; i++) {
        fprintf(save, "%d %d %d %d\n", monkeys[i].x, monkeys[i].y, monkeys[i].temps_tir, monkeys[i].portee);
    }
    fclose(save);
}
