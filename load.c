#include <stdio.h>

#include "crabs_creation.h"
#include "monkey_creation.h"

Monkey* load_game(Crab* crab, int* monkey_count, int* nb_ndc) {
    FILE* save = fopen("sauvegarde.txt", "r");
    
    if(save == NULL) {
        printf("Aucune sauvegarde trouvee.\n");
        return NULL;
    }

    fprintf(save, "%d %d %d %d\n", &crab->x, &crab->y, &crab->path_index, &crab->hp);
    fprintf(save, "%d %d\n", monkey_count, nb_ndc);

    Monkey* monkeys = malloc(sizeof(Monkey) * (*monkey_count));

    for(int i = 0; i < *monkey_count; i++) {
        fprintf(save, "%d %d %d %d\n", &monkeys[i].x, &monkeys[i].y, &monkeys[i].temps_tir, &monkeys[i].portee);
    }
    fclose(save);
    return monkeys; 
}
