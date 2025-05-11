#include <stdio.h>
#include <stdlib.h>
#include "clean_screen.h"

// function to clear the terminal screen
void clear_screen() {

      // ANSI escape code to move cursor to top-left and clear the screen
      printf("\033[H\033[J");

      // ensure the output is flushed immediately
      fflush(stdout);

}