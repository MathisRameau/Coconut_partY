#include <stdio.h>
#include <stdlib.h>
#include "turn_creation.h"

Turn turn_creation(int num){

      Turn turn;

      turn.num = num;
      turn.active = true;
      turn.success = true;

      return turn;
}