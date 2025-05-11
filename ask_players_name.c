#include <stdio.h>
#include <stdlib.h>
#include "ask_players_name.h"

// function to ask the player for their name (pseudo)
// returns a dynamically allocated string containing the player's name
char* ask_players_name(){

      char* pseudo = malloc(50 * sizeof(char));

      if (pseudo == NULL){

            printf("Erreur d'allocation mémoire\n");
            exit(1);
      }

      // loop until a valid name is entered
      while (1){

            printf("\nEntrez votre pseudo : ");
            fgets(pseudo, 50, stdin);

            int i = 0;

            while (pseudo[i] != '\0'){

                  if (pseudo[i] == '\n'){

                        pseudo[i] = '\0';
                        break;
                  }
                  i++;
            }

            // check if the name is not empty
            if (pseudo[0] != '\0'){

                  printf("\nBienvenue %s !\n", pseudo);
                  break;
            }

            printf("Erreur : nom invalide, retapez votre pseudo !\n");
      }

      // return the valid player name
      return pseudo;
}