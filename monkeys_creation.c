#include <stdio.h>
#include "monkeys_creation.h"
#include "gameBoard_playArea.h" 

#define MAX_ADJACENT_CASES 1000

typedef struct {
    int x;
    int y;
} Position;

int is_adjacent_to_path(Case** game_board, int x, int y, int height, int width) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx >= 0 && ny >= 0 && nx < height && ny < width) {
            if (game_board[nx][ny].type == PATH) {
                return 1;
            }
        }
    }
    return 0;
}

