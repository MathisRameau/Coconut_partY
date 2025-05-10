#include <stdio.h>
#include <stdlib.h>
#include "display_crabs_tour.h"
#include "decompte.h"

void display_crabs_tour(int nb_crabs[3], int tot_crabs){

      printf("Vous allez devoir arrêter %d crabes :\n\n", tot_crabs);

      for(int i = 0; i < 3; i++){

            printf("         - %d crabes de niveau %d\n", nb_crabs[i], i + 1);

      }

      printf("\nBon courage! Envahissement des crabes dans :\n\n");

      decompte();

}