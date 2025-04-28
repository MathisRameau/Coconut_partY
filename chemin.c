// Procédure chemin aléatoire

void creer_chemin(Case** game_board) {

    int pos_x = WIDTH / 2;
    int pos_y = HEIGHT - 2; 
    
   
    int fin_x = WIDTH / 2; 
    int fin_y = HEIGHT - 2; 
    

    game_board[pos_y][pos_x].affichage = '#';
    pos_y--; 
    game_board[pos_y][pos_x].affichage = '.';
    
    int derniere_direction = HAUT; 
    int direction;
    int nb_pas = 0;
    int max_pas = HEIGHT + WIDTH; // Limite pour éviter une boucle infinie // Tester sans pour voir 
    
  
    while ((pos_x != fin_x || pos_y != fin_y) && nb_pas < max_pas) { // Tetser sans le nombre de pas 
  
        direction = directions(derniere_direction); // faire un lien pour avoir la procedure direction
        
        int new_x = pos_x;
        int new_y = pos_y;
        
        if (direction == GAUCHE) {
            new_x--;
        } else if (direction == DROITE) {
            new_x++;
        } else if (direction == HAUT) {
            new_y--;
        }
        
        if (new_x > 0 && new_x < WIDTH - 1 && new_y > 0 && new_y < HEIGHT - 1 && game_board[new_y][new_x].affichage == ' ') { // full condition nrlm teste tous les cas possible
            pos_x = new_x;  
            pos_y = new_y;
            game_board[pos_y][pos_x].affichage = '.';
            derniere_direction = direction;
        }
        nb_pas++;
    }
    
    if (pos_x != fin_x || pos_y != fin_y) { // on "force" l'arrivée vers 'X'
        while (pos_y > fin_y) {
            pos_y--;
            if (game_board[pos_y][pos_x].affichage == ' ') {
                game_board[pos_y][pos_x].affichage = '.';
            }
        }
        while (pos_x < fin_x) {
            pos_x++;
            if (game_board[pos_y][pos_x].affichage == ' ') {
                game_board[pos_y][pos_x].affichage = '.';
            }
        }
        while (pos_x > fin_x) {
            pos_x--;
            if (game_board[pos_y][pos_x].affichage == ' ') {
                game_board[pos_y][pos_x].affichage = '.';
            }
        }
    }
    
    game_board[HEIGHT - 2][WIDTH / 2].affichage = '#'; // Vérif qu'on ait bien le début à '#' et la fin à 'X' 
    game_board[fin_y][fin_x].affichage = 'X';
}
