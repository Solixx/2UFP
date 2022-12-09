//
// Created by manue on 09/12/2022.
//

#include "pr11.h"

int main_pr11(int argc, const char * argv[]){

    GAME_DYNARPLAYERS game;
    const char *nomes[] = {"Manuel", "Jose"};
    char player[] = "T";

    game = create_array_players(nomes, 3);

    for (int i = 0; i < game.nplayers; ++i) {
        printf("Jogador%d: %s\n", i, game.pplayer[i].pusername);
    }

    insert_player_into_dynarray(&game, player);

    for (int i = 0; i < game.nplayers; ++i) {
        printf("Jogador%d: %s\n", i, game.pplayer[i].pusername);
    }

    return 0;
}

GAME_DYNARPLAYERS create_array_players(const char *pnames[], int size){

    GAME_DYNARPLAYERS *game = (GAME_DYNARPLAYERS*) calloc(1, sizeof (GAME_DYNARPLAYERS));
    game->nplayers = size;

    game->pplayer = (PLAYER_LLCARDS*) calloc(size, sizeof (PLAYER_LLCARDS));

    for (int i = 0; i < game->nplayers; ++i) {
        game->pplayer[i].pusername = (char*) calloc(strlen(pnames[i]), sizeof (char));
        strcpy(game->pplayer[i].pusername, pnames[i]);
        game->pplayer[i].pcard = NULL;
    }
    return *game;
}

void insert_player_into_dynarray(GAME_DYNARPLAYERS *pg, char player[]){

    PLAYER_LLCARDS empty = {NULL, NULL};
    for (int i = 0; i < pg->nplayers; ++i) {
        if(pg->pplayer[i] == empty){
            pg->pplayer[i].pusername = (char*) calloc(strlen(player), sizeof (char));
            strcpy(pg->pplayer[i].pusername, player);
            break;
        }
    }
}