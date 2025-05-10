#include <stdio.h>
#include <stdlib.h>
#include "game_over_display_menu.h"

void game_over_display_menu(int tour, int nb_ndc, char* pseudo) {
    int choix;


    printf("\n\n========================================\n");
    printf("            GAME OVER\n");
    printf("========================================\n");
    printf("Tour: %d\n", tour);
    printf("Nombre de noix de coco gagnees : %d\n", nb_ndc);
    printf("========================================\n");
    printf("1. Nouvelle partie\n");
    printf("2. Quitter\n");
    printf("========================================\n");

    do {
        printf("Votre choix --> ");
        if(scanf("%d", &choix) != 1 || choix < 1 || choix > 2) {
            printf("Choix invalide. Veuillez entrer 1 ou 2.\n");
            while(getchar() != '\n'); // Vider le buffer
        }
    } while(choix < 1 || choix > 2);

    if(choix == 1) {
        printf("\nNouvelle partie...\n");
        // Relancer le jeu (ps: essayer de voir comment relancer le jeu)
    } else {
        printf("\nMerci d'avoir joué %s! A bientôt!\n", pseudo);
        exit(0);
    }
}
