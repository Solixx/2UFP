//
// Created by manue on 21/10/2022.
//

#include "aed1_04.h"

void main_pr_aed1_04(){
    //cliente0_aed04();
    cliente1_aed04();
}

void printDFA(int dfa[R][M]){

    printf("\nDFA[%d][%d]\n", R, M);
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("%2d", dfa[i][j]);
        }
        printf("\n");
    }
}

void KMP(char pat[], int dfa[R][M]){

    int j,i;

    dfa[pat[0] - FIRST_ALPHABET_SYMBOL0][0] = 1;

    printf("(X,J) = ");
    for (int X = 0, j = 1; j < M; j++)
    {
        printf("(%d, %d)", X,j);
        for (int c = 0; c < R; c++)
            dfa[c][j] = dfa[c][X];
        dfa[pat[j] - FIRST_ALPHABET_SYMBOL0][j] = j+1;
        X = dfa[pat[j] - FIRST_ALPHABET_SYMBOL0][X];
    }
}

int search_KMP(char txt[], int dfa[R][M]){

    int N = strlen(txt), i, j;

    printf("(txt[i],state) = ");
    for (i = 0, j = 0; i < N && j < M; ++i) {
        j = dfa[txt[i] - FIRST_ALPHABET_SYMBOL0][j];
        printf("(%c,%d)",txt[i],j);
    }
    printf("\n");
    if(j == M) return i - M;
    else       return N;
}

void cliente0_aed04(){

    char s[] = "AABACABBAC";
    char path[] = "AAABC";
    int N = strlen(s);
    int MM = strlen((path));
    int j = 0;

    for (int i = 0; i < N; ++i) {
        if(s[i] == path[j]){
            j++;
        } else{
            j = 0;
        }
        if(j == MM){
            printf("Ocorrencia\n");
        }
    }
}

void cliente1_aed04(){
    char *txt = "AAAAABBAABCAAABCCC";
    char * pat = "AAABC";
    int dfa[R][M] = {0};
    KMP(pat, dfa);
    printDFA(dfa);
    search_KMP(txt, dfa);
}