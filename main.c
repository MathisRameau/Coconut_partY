#include <head.h>

int main() {

    srand(time(NULL));

    Case** game_board = gameBoard_creation();

    if (game_board == NULL){

          return 1;

    }

    smooth_gameBoard(game_board);

    play_area(game_board);

    display_gameBoard(game_board);

    free_gameBoard(game_board);
    return 0;
}