//
//  pr11.h
//  lp1_ufp
//
//  Created by Christophe Soares on 28/09/2017.
//  Copyright © 2017 Rui. All rights reserved.
//

#ifndef pr11_h
#define pr11_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Structures used for storing a game of cards, where:
 *  - GAME_DYNARPLAYERS is a dynamic array of PLAYER_LLCARDS;
 *  - PLAYER_LLCARDS is a linked-list of CARD_NODE.
 */
 
typedef struct card {
    char cardId;
    char cardSuit;
    int cardPoints;
    struct card *pcard;
} CARD_NODE;

typedef struct player {
    char *pusername;
    CARD_NODE *pcard;
} PLAYER_LLCARDS;

typedef struct game {
    int nplayers;
    PLAYER_LLCARDS *pplayer;
} GAME_DYNARPLAYERS;

/**
 * Função que, dado um array de nomes, cria e inicializa com os valores recebidos um array dinâmico
 * com *size* jogadores. Cada jogador será inicializado com uma lista-ligada vazia de cartas.
 * @param pnames - array de strings com os nomes dos jogadores;
 * @param size - número de jogadores a inserir no jogo;
 * @return cópia do jogo de cartas criado.
 */
GAME_DYNARPLAYERS create_array_players(const char *pnames[], int size);

/**
 * Função que retorna a carta com maior valor, de um dado naipe (card Suit) e de um dado jogador.
 * @param g - copia do jogo;
 * @param suit - naipe da carta de maior valor a procurar;
 * @param pname - nome do jogador para o qual procurar;
 * @return apontador para a carta encontrada (NULL se não existir).
 */
CARD_NODE* find_highest_card_player(GAME_DYNARPLAYERS g, char suit, char pname[]);

/**
 * Função que grava num ficheiro de texto com toda a informação relativa a um jogo, inclindo todos os
 * jogadores do array dinâmico e todas as cartas da lista ligada de cada jogador.
 * @param g - cópia do jogo de cartas;
 * @param fn - path para o ficheiro de texto onde se gravará a informação do jogo de cartas.
 */
void save_existing_game_txt(GAME_DYNARPLAYERS g, char fn[]);

/**
 * Função que lê de um ficheiro de texto  toda a informação relativa a um jogo, inclindo todos os
 * jogadores do array dinâmico e todas as cartas da lista ligada de cada jogador.
 * @param pg - pointer para o jogo de cartas;
 * @param fn - path para o ficheiro de texto onde se gravará a informação do jogo de cartas.
 */
void read_existing_game_txt(GAME_DYNARPLAYERS *pg, char fn[]);

/**
 * Insert a player into the first available position of a dyn array of players.
 * @param pg - pointer to game dyn array of players;
 * @param player - name of player to inserte.
 */
void insert_player_into_dynarray(GAME_DYNARPLAYERS *pg, char player[]);

/**
 * Insert a new card into the list of cards of a given player.
 * @param pg - pointer to game dyn array of players;
 * @param player - name of player to inserte.
 * @param id - card id.
 * @param suit - card suite.
 * @param points - card points.
 */
void insert_card_into_player_list(GAME_DYNARPLAYERS *pg, char player[], char id, char suit, int points);

int main_pr11(int argc, const char * argv[]);

#endif /* pr11_h */



