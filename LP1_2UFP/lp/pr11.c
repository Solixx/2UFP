//
// Created by manue on 09/12/2022.
//

#include "pr11.h"

int main_pr11(int argc, const char * argv[]){

    GAME_DYNARPLAYERS game;
    CARD_NODE *cardReturn = NULL;
    const char *nomes[3] = {"Manuel", "Jose", "Manuel"};
    char *player[] = {"Manuel", "Jose"};
    char *fileName = "../data/cardGame.txt";

    game = create_array_players(nomes, 3);

    for (int i = 0; i < game.nplayers; ++i) {
        printf("Jogador%d: %s\n", i, game.pplayer[i].pusername);
    }

    //insert_player_into_dynarray(&game, player);

    for (int i = 0; i < game.nplayers; ++i) {
        printf("Jogador%d: %s\n", i, game.pplayer[i].pusername);
    }

    insert_card_into_player_list(&game, player[0], '5', 'a', 5);
    insert_card_into_player_list(&game, player[0], '3', 'a', 3);
    insert_card_into_player_list(&game, player[1], '2', '5', 2);

    for (int i = 0; i < game.nplayers; ++i) {
        printf("Player %s\n", game.pplayer[i].pusername);
        CARD_NODE *curr = game.pplayer[i].pcard;
        while (curr != NULL){
            printf("Carta Id %c\n", curr->cardId);
            printf("Carta Suit %c\n", curr->cardSuit);
            printf("Carta Points %d\n", curr->cardPoints);
            curr = curr->pcard;
        }
    }

    cardReturn = find_highest_card_player(game, 'a', "Manuel");

    printf("Maior Carta ID: %c\n", cardReturn->cardId);
    printf("Maior Carta Suit: %c\n", cardReturn->cardSuit);
    printf("Maior Carta Points: %d\n", cardReturn->cardPoints);

    //save_existing_game_txt(game, fileName);

    read_existing_game_txt(&game, fileName);

    for (int i = 0; i < game.nplayers; ++i) {
        printf("Player %s\n", game.pplayer[i].pusername);
        CARD_NODE *curr = game.pplayer[i].pcard;
        while (curr != NULL){
            printf("Carta Id %c\n", curr->cardId);
            printf("Carta Suit %c\n", curr->cardSuit);
            printf("Carta Points %d\n", curr->cardPoints);
            curr = curr->pcard;
        }
    }

    return 0;
}

GAME_DYNARPLAYERS create_array_players(const char *pnames[], int size){

    GAME_DYNARPLAYERS *game = (GAME_DYNARPLAYERS*) calloc(1, sizeof (GAME_DYNARPLAYERS));
    game->nplayers = size;

    game->pplayer = (PLAYER_LLCARDS*) calloc(size, sizeof (PLAYER_LLCARDS));

    for (int i = 0; i < game->nplayers; ++i) {
        if(pnames[i] != NULL){
            game->pplayer[i].pusername = (char*) calloc(strlen(pnames[i]), sizeof (char));
            strcpy(game->pplayer[i].pusername, pnames[i]);
            game->pplayer[i].pcard = NULL;
        }
    }
    return *game;
}

void insert_player_into_dynarray(GAME_DYNARPLAYERS *pg, char player[]){

    int newsize = pg->nplayers*2;
    for (int i = 0; i < pg->nplayers; ++i) {
        if(pg->pplayer[i].pusername == NULL){
            pg->pplayer[i].pusername = (char*) calloc(strlen(player), sizeof (char));
            strcpy(pg->pplayer[i].pusername, player);
            pg->pplayer[i].pcard = NULL;
            break;
        }
        if(i == pg->nplayers-1){
            pg->pplayer = (PLAYER_LLCARDS*) realloc(pg->pplayer, newsize * sizeof (PLAYER_LLCARDS));
            for (int j = pg->nplayers; j < newsize; ++j) {
                PLAYER_LLCARDS emptyP = {NULL, NULL};
                pg->pplayer[j] = emptyP;
            }
            pg->pplayer[pg->nplayers].pusername = (char*) calloc(strlen(player), sizeof (char));
            strcpy(pg->pplayer[pg->nplayers].pusername, player);
            pg->pplayer[i].pcard = NULL;
            pg->nplayers = newsize;
            break;
        }
    }
}

void insert_card_into_player_list(GAME_DYNARPLAYERS *pg, char player[], char id, char suit, int points){

    for (int i = 0; i < pg->nplayers; ++i) {
        CARD_NODE *card = (CARD_NODE*) calloc(1, sizeof (CARD_NODE));
        card->cardId = id;
        card->cardSuit = suit;
        card->cardPoints = points;
        card->pcard = NULL;
        if(strcmp(pg->pplayer[i].pusername, player) == 0){
            if(pg->pplayer[i].pcard == NULL){
                pg->pplayer[i].pcard = (CARD_NODE*) calloc(1, sizeof (CARD_NODE));
                pg->pplayer[i].pcard = card;
            } else{
                CARD_NODE *curr = pg->pplayer[i].pcard;
                while (curr->pcard != NULL){
                    curr = curr->pcard;
                }
                curr->pcard = card;
            }
        }
    }
}

CARD_NODE* find_highest_card_player(GAME_DYNARPLAYERS g, char suit, char pname[]){

    int max = 0;
    CARD_NODE *cardReturn = NULL;
    for (int i = 0; i < g.nplayers; ++i) {
        if(strcmp(g.pplayer[i].pusername, pname) == 0){
            CARD_NODE *curr = g.pplayer[i].pcard;
            while (curr != NULL){
                if(curr->cardSuit == suit){
                    if(curr->cardPoints > max){
                        max = curr->cardPoints;
                        cardReturn = curr;
                    }
                }
                curr = curr->pcard;
            }
            return cardReturn;
        }
    }
    return 0;
}

void save_existing_game_txt(GAME_DYNARPLAYERS g, char fn[]){

    FILE *fp = fopen(fn, "w");

    if(fp == NULL){
        printf("Erro no Ficheiro\n");
        return;
    }

    //fprintf(fp, "Jogo\n");
    fprintf(fp, "%d\n", g.nplayers);
    for (int i = 0; i < g.nplayers; ++i) {
        fprintf(fp, "%s\n", g.pplayer[i].pusername);
        //fprintf(fp, "%p\n", g.pplayer[i].pcard);
        CARD_NODE *curr = g.pplayer[i].pcard;
        while (curr != NULL){
            fprintf(fp, "%c\n", curr->cardId);
            fprintf(fp, "%c\n", curr->cardSuit);
            fprintf(fp, "%d\n", curr->cardPoints);
            //fprintf(fp, "%p\n", curr->pcard);
            curr =  curr->pcard;
        }
    }
    fclose(fp);
}

void read_existing_game_txt(GAME_DYNARPLAYERS *pg, char fn[]){

    FILE *fp = fopen(fn, "r");
    char t;
    int j = 0;
    fscanf(fp, "%d", &pg->nplayers);
    while (!feof(fp)){
        for (int i = 0; i < pg->nplayers; ++i) {
            if (fscanf(fp, "\n")){
                continue;
            }
            //fgets(pg->pplayer[i].pusername, 100, fp);
            fscanf(fp, "%s", pg->pplayer[i].pusername);
            fscanf(fp, "\n");
            CARD_NODE *curr = pg->pplayer[i].pcard;
            while (curr != NULL){
                if(j == 0){
                    curr->cardId = fgetc(fp);
                } else{
                    curr->cardId = t;
                }
                //fscanf(fp, "%c", &curr->cardId);
                fscanf(fp, "\n");
                curr->cardSuit = fgetc(fp);
                //fscanf(fp, "%c", &curr->cardSuit);
                fscanf(fp, "\n");
                //curr->cardPoints = fgetc(fp);
                fscanf(fp, "%d", &curr->cardPoints);
                fscanf(fp, "\n");
                t = fgetc(fp);
                //fscanf(fp, "%s", t);
                /*t = fgetc(fp);
                if (t == '\n'){
                    break;
                }*/
                if(isalpha(t)){
                    fseek(fp, -1, SEEK_CUR);
                    break;
                }
                j++;
                curr = curr->pcard;
            }
            j = 0;
        }
    }

    fclose(fp);
}