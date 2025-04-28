int verif(Case case_crab, Case case_verif, int dernier_deplacement){
    
    if((dernier_deplacement == GAUCHE && case_crab.pos_x == case_verif.pos_x + 1) || dernier_deplacement == DROITE && case_crab.pos_x == case_verif.pos_x - 1){
        
        return FALSE;
        
    }
    
    return TRUE;
    
}

void deplacement_crabes(Case** game_board, Case* case_crab, Case* nv_case_crab){
    
    if(case_crab.type == CRAB){
                
        for(int dx = -1; dx <= 1; dx++){
            
            for(int dy = 0; dy <= 1; dy++){
                
                if((dy == 1 && dx == -1) || (dy == 1 && dx == 1)){
                    
                    continue;
                    
                }
                
                if(game_board[dx][dy].type == CRAB){
                    
                    if(verif(case_crab, game_board[dx][dy], dernier_deplacement)){
                        
                        *case_crab.type = PATH;
                        *nv_case_crab.pos_x = dx;
                        *nv_case_crab.pos_y = dy;
                        *nv_case_crab.type = CRAB;
                        
                        return;
                    }
                    
                }
                
            }
            
        }
        
    }

    return 0;
}
