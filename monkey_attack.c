#include <stdio.h>
#include <stdlib.h>
#include "monkey_attack.h"


void monkeys_attack_crabs(Monkey* monkeys, int monkey_nombre, Crab* crab, Case** game_board) {
    for (int i = 0; i < monkey_nombre; i++) {
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int j = 0; j < 4; j++) {
            int mx = monkeys[i].x + dx[j];
            int my = monkeys[i].y + dy[j];
            if (mx == crab->x && my == crab->y && crab->hp > 0) {
                crab->hp -= 1;
                printf("Singe %d attaque le crabe ! PV restants : %d\n", i + 1, crab->hp);
                break;
            }
        }
    }
}
