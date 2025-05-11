#ifndef TOUR_CREATION_H
#define TOUR_CREATION_H

#include <stdbool.h>
#include "crabs_creation.h"
#include "monkeys_creation.h"

typedef struct {

    int num;
    bool active;
    bool success;


}Turn;

Turn turn_creation(int num);

#endif
