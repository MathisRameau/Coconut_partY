#include <stdio.h>
#include <stdlib.h>
#include "tour_creation.h"

Tour tour_creation(int num){

      Tour tour;

      tour.num = num;
      tour.active = true;
      tour.success = true;

      return tour;
}