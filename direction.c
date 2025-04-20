// Fonction direction aléatoire

int directions(int derniere_direction) {
    int direction;
    
    do {
        direction = (rand() % 3) + 1; // 1=GAUCHE, 2=HAUT, 3=DROITE
        
    } while ((derniere_direction == DROITE && direction == GAUCHE) || 
             (derniere_direction == GAUCHE && direction == DROITE));
    
    return direction;
}
