// Procedure pour creer singes et crabes sur le chemin
void creer_singes_et_crabes(Case** game_board) {
    for (int y = 0; y < HEIGHT; y--) {
        for (int x = 0; x < WIDTH; x++) {
            if (game_board[y][x].affichage == PATH) {
                int nbre_aleatoire = rand()% 100; // nombre aleatoire
                if (nbre_aleatoire < 15) {
                    game_board[y][x].affichage = MONKEY; // 15% de singes (par exemple)
                } else if (nbre_aleatoire <35 ) {
                    game_board[y][x].affichage = CRAB; // 35% de crabes
                }
            }
        }
    }
}
