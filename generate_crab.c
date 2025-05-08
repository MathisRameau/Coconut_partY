#include <stdio.h>
#include <stdlib.h>
#include "generate_crab.h"

bool generate_crab(){

      int nb = rand() % 100;

      if(nb > PROB_GEN){

            return false;

      }

      return true;

}