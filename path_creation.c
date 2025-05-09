#include <stdio.h>
#include <stdlib.h>
#include "path_creation.h"

Case* generate_path(Case** game_board, int* start_x, int* start_y, int* taille_chemin,
                    int zone_top, int zone_bottom, int zone_left, int zone_right,
                    int height, int width) {
    Case* chemin = NULL;
    *taille_chemin = 0;
    int derniere_direction = -1;

    Case case_chemin = {
        .pos_x = *start_x,
        .pos_y = *start_y
    };

    int direction = HAUT;

    /*if (case_chemin.pos_y == *start_y) {
        if (case_chemin.pos_x < *start_x) direction = DROITE;
        else direction = GAUCHE;
    } else {
        direction = HAUT;
    } 

    game_board[*start_x][*start_y].type = START; */

    while (1) {
        if (*taille_chemin > 5000) {
            printf("Trop d'itérations. Chemin interrompu.\n");
            break;
        }

        (*taille_chemin)++; // D'abord on augmente la taille

        chemin = realloc(chemin, (*taille_chemin + 1) * sizeof(Case));
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

        if (game_board[next_x][next_y].type == CROWN) {
            case_chemin.pos_x = next_x;
            case_chemin.pos_y = next_y;

            chemin = realloc(chemin, (*taille_chemin + 1) * sizeof(Case));
            if(chemin == NULL) return NULL;

            chemin[*taille_chemin] = case_chemin;
            (*taille_chemin)++;

            break;
        }

        if (game_board[next_x][next_y].type != LAND) continue;

        game_board[next_x][next_y].type = PATH;
        case_chemin.pos_x = next_x;
        case_chemin.pos_y = next_y;

        game_board[case_chemin.pos_x][width / 2].type = CROWN;
        case_chemin.pos_y = width / 2;
        chemin[*taille_chemin] = case_chemin;
        (*taille_chemin)++;
    }

    return chemin;
}