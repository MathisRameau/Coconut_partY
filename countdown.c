#include <stdio.h>
#include <stdlib.h>
#include "countdown.h"
#include <unistd.h>

// Simple countdown from 3 to 1 with half-second delay
void countdown(){

      for(int i = 3; i > 0; i--){

            printf("%d\n\n", i);
            sleep(1);

      }

}