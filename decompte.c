#include <stdio.h>
#include <stdlib.h>
#include "decompte.h"
#include <unistd.h>

void decompte(){

      for(int i = 3; i > 0; i--){

            printf("%d\n\n", i);
            usleep(500000);

      }

}