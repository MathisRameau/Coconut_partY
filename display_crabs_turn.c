#include <stdio.h>
#include <stdlib.h>
#include "display_crabs_turn.h"
#include "countdown.h"

// Function to display how many crabs are invading and at what levels
void display_crabs_turn(int nb_crabs[3], int tot_crabs){

      printf("Vous allez devoir arrêter %d crabes :\n\n", tot_crabs);

      // Loop through the 3 crab levels and display the amount for each
      for(int i = 0; i < 3; i++){

            printf("         - %d crabes de niveau %d\n", nb_crabs[i], i + 1);

      }

      // Countdown before the crab invasion starts
      printf("\nBon courage! Envahissement des crabes dans :\n\n");

      countdown();

}