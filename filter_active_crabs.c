#include <stdlib.h>
#include "filter_active_crabs.h"

Crab* filter_active_crabs(Crab* tab_crab, int* nb_crabs) {

      int count = 0;

      for (int i = 0; i < *nb_crabs; i++) {

            if (tab_crab[i].active) {

                  count++;
            }
      }
      Crab* filtered = malloc(count * sizeof(Crab));

      if (filtered == NULL) {

            *nb_crabs = 0;
            return NULL;
      }

      int j = 0;

      for (int i = 0; i < *nb_crabs; i++) {

            if (tab_crab[i].active) {

                  filtered[j++] = tab_crab[i];
            }
      }

      *nb_crabs = count;

      return filtered;
}