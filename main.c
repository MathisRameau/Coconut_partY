#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#include <unistd.h>
#include "gameBoard_dimension.h"
#include "gameBoard_creation.h"
#include "gameBoard_smooth.h"
#include "gameBoard_playArea.h"
#include "gameBoard_display.h"
#include "gameBoard_free.h"
#include "crabs_creation.h"
#include "crabs_movement.h"
#include "ask_monkey_position.h"
#include "clean_screen.h"
#include "path_creation.h"
#include "monkeys_creation.h"

void afficher_menu() {
        printf("============================================================\n");
        printf("|                        COCONUT PARTY                     |\n");
        printf("|==========================================================|\n");
        printf("|  1. Nouvelle partie                                      |\n");
        printf("|  2. Quitter                                              |\n");
        printf("|  3. Reprendre une partie                                 |\n");
        printf("============================================================\n\n");
        printf("Bienvenue dans la jungle des crabes et des singes !\n");
        printf("Prepare-toi a defendre la couronne avec tes meilleurs tirs de coco !\n\n");
        printf("Entrez votre choix : ");
    }

int main() {
    s	rand(time(NULL));

	afficher_menu();

	int choix = 0;
	char buffer[100];

	do {
    		printf("Entrez votre choix : ");
    		if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        		printf("Erreur de lecture.\n");
        	continue;
    		}

    		if (sscanf(buffer, "%d", &choix) != 1 || choix < 1 || choix > 3) {
        		printf("Choix invalide. Veuillez entrer 1, 2 ou 3.\n");
        		choix = 0; // pour rester dans la boucle
    		}
	} while (choix < 1 || choix > 3);

	if (choix == 2) {
		printf("A bientot sur CoCoCoCoonut !\n");
		return 0;
	}
	
	if ( choix == 3) {
		FILE* save = fopen("sauvegarde.txt", "r"); 
		if ( save == NULL) {
			printf("Aucune sauvegarde trouvee : commence une nouvelle game !\n");
			return 0;
		}
		
		fclose(save);
		printf("Partie reprise (chargement...)\n");
	}

    bool running = true;

    int height, width, start_x, start_y, chemin_length, crab_index = 0;
    Case* chemin;

    game_board_dimension(&height, &width);

    Case** game_board = gameBoard_creation(height, width);
    if (game_board == NULL) return 1;

    smooth_gameBoard(game_board, height, width);
    play_area(game_board, &chemin, &chemin_length, height, width, &start_x, &start_y);

    int monkey_nombre;
    
    do {
        printf("Combien de singes veux-tu placer ?\n");
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%d", &monkey_nombre) != 1 || monkey_nombre <= 0) {
            printf("Entree invalide : veuillez entrer un nombre entier strictement positif.\n");
            monkey_nombre = 0;
        }
    } while (monkey_nombre <= 0); 

    Monkey* monkeys = malloc(sizeof(Monkey)* monkey_nombre);
    
    for (int i = 0; i < monkey_nombre; i++) {
        printf("Placement du singe %d :\n", i + 1);
        ask_monkey_position(game_board, chemin, chemin_length, height, width, &monkeys[i].x, &monkeys[i].y);
        monkeys[i].temps_tir = 0;
    }


    Crab crab = create_crab(game_board, chemin, height, width, start_x, start_y);

    while (running) {
        move_crab(&crab, game_board, chemin, chemin_length, &crab_index);

        //clear_screen();

        display_gameBoard(game_board, height, width);


        #ifdef _WIN32
        Sleep(200);
        #else 
        usleep(200000);
        #endif

        if (crab_index == chemin_length - 1) {
            running = false;
        }
    }
    printf("Un crabe a atteint la couronne !\n"); 
    free_gameBoard(game_board, height);

    return 0;
}
