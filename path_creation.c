#include <stdio.h>
#include <stdlib.h>
#include "path_creation.h"

Case* generate_path(Case** game_board, int* start_x, int* start_y, int* taille_chemin,
                    int zone_top, int zone_bottom, int zone_left, int zone_right,
                    int height, int width) {
    Case* chemin = NULL;
    *taille_chemin = 0;
    int derniere_direction = 0;

    Case case_chemin = {
        .pos_x = *start_x,
        .pos_y = *start_y
    };

    int direction = 0;
    if (case_chemin.pos_y == *start_y) {
        if (case_chemin.pos_x < *start_x) direction = DROITE;
        else direction = GAUCHE;
    } else {
        direction = HAUT;
    }

    while (1) {
        if (*taille_chemin > 5000) {
            printf("Trop d'itérations. Chemin interrompu.\n");
            break;
        }

        (*taille_chemin)++; // D'abord on augmente la taille

        chemin = realloc(chemin, (*taille_chemin) * sizeof(Case));
        if (chemin == NULL) {
            printf("Erreur d'allocation mémoire pour le chemin\n");
            return NULL;
        }

        chemin[*taille_chemin - 1] = case_chemin;

        direction = choix_direction(derniere_direction, case_chemin, zone_top, zone_bottom, zone_left, zone_right);
        derniere_direction = direction;

        int next_x = case_chemin.pos_x;
        int next_y = case_chemin.pos_y;

        if (direction == GAUCHE) next_y--;
        else if (direction == DROITE) next_y++;
        else if (direction == HAUT) next_x--;

        if (next_x < zone_top || next_x > zone_bottom || next_y < zone_left || next_y > zone_right)
            continue;

        if (next_x < 0 || next_y < 0 || next_x >= height || next_y >= width)
            continue;

        if (game_board[next_x][next_y].type == CROWN)
            break;

        case_chemin.pos_x = next_x;
        case_chemin.pos_y = next_y;

        if (game_board[next_x][next_y].type == LAND)
            game_board[next_x][next_y].type = PATH;
    }

    return chemin;
}