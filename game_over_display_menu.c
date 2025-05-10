#include <stdio.h>
#include <stdlib.h>
#include "game_over_display_menu.h"

void game_over_display_menu(int tour, int coconut_number, char* pseudo) {
    int choice;


    printf("\n\n========================================\n");
    printf("            GAME OVER\n");
    printf("========================================\n");
    printf("Tour: %d\n", tour);
    printf("Nombre de noix de coco gagnees : %d\n", coconut_number);
    printf("========================================\n");
    printf("1. Nouvelle partie\n");
    printf("2. Quitter\n");
    printf("========================================\n");

    do {
        printf("Votre choix --> ");
        if(scanf("%d", &choice) != 1 || choice < 1 || choice > 2) {
            printf("Choix invalide. Veuillez entrer 1 ou 2.\n");
            while(getchar() != '\n'); // Vider le buffer
        }
    } while(choice < 1 || choice > 2);

    if(choice == 1) {
        printf("\nNouvelle partie...\n");
        // Relancer le jeu (ps: essayer de voir comment relancer le jeu)
    } else {
        printf("\nMerci d'avoir joué %s! A bientôt!\n", pseudo);
        exit(0);
    }
}
