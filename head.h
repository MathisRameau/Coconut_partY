#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 50
#define SMOOTH_ITERATIONS 1
#define PROB_LAND 60

// Enumération pour les types de terrain
enum Terrain { START, LAND, SEA, CROWN, CRAB, MONKEY, PATH };

// Structure qui définie une Case
typedef struct {

    int pos_x;
    int pos_y;
    enum Terrain type;

} Case;

// Fonction qui créé un plateau de jeu
Case** gameBoard_creation();
void smooth_gameBoard(Case** game_board);
void play_area(Case** game_board);
void display_gameBoard(Case** game_board);
void free_gameBoard(Case** game_board);
