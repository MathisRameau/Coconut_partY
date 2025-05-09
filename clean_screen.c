#include <stdio.h>
#include <stdlib.h>
#include "clean_screen.h"

void clear_screen() {
    printf("\033[H\033[J");
    fflush(stdout);
}