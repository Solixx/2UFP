//
// Created by pc on 07/12/2022.
//

#include "teste2.h"

int main_teste2(int argc, const char * argv[]){

    char *fp = "../data/teste2_2019.txt";

    PT pts1[3] = {{1, 1}, {2, 2}};
    PT pts2[3] = {{1, 1}, {2, 2}, {3, 3}};
    PT pts3 = {4,4};

    POLIGONO p3 = {3, 2, pts2, NULL};
    POLIGONO p2 = {2, 2, pts2, &p3};
    POLIGONO p1 = {1, 3, pts1, &p2};

    LSTPOLIG lstp = {&p1, 2};

    inserir_pt_poligono(lstp, 1, pts3);

    POLIGONO *curr = lstp.ppolig;
    for (int i = 0; i < lstp.sizepolig; ++i) {
        printf("Poligo: %d\n", curr->id);
        for (int j = 0; j < curr->sizepts; ++j) {
            printf("X%d: %d\n", j, curr->ppts[j].x);
            printf("Y%d: %d\n", j, curr->ppts[j].y);
        }
        curr = curr->pnxt;
    }

    grava_poligonos_com_mais_pts_txt(lstp, fp);

    return 0;
}

void inserir_pt_poligono(LSTPOLIG lstpoligono, int id, PT pts){

    int bool = 0;
    POLIGONO *curr = lstpoligono.ppolig;
    while (curr == NULL){
        if(curr->id == id) break;
        curr = curr->pnxt;
    }
    if(curr == NULL){
        printf("Poligono nao existe\n");
        return;
    }

    if(curr->ppts != NULL){
        for (int i = 0; i < curr->sizepts; ++i) {
            if(curr->ppts[i].x == 0 && curr->ppts[i].y == 0){
                curr->ppts[i] = pts;
                bool = 1;
                break;
            }
        }
        if(bool == 0){
            curr->ppts = (PT*) realloc(curr->ppts, (curr->sizepts+1)*sizeof (PT));
            curr->ppts[curr->sizepts] = pts;
        }
    } else{
        curr->ppts = (PT*) calloc(curr->sizepts, sizeof (PT));
        curr->ppts[0] = pts;
    }
}

void grava_poligonos_com_mais_pts_txt(LSTPOLIG lstpoligono, char *filename){

    FILE *fp = fopen(filename, "r+");

    if(fp == NULL){
        printf("Erro no ficheiro\n");
    }

    POLIGONO *curr = lstpoligono.ppolig;
    int max = 0;
    while (curr != NULL){
        if(curr->sizepts > max){
            max = curr->sizepts;
        }
        curr = curr->pnxt;
    }

    curr = lstpoligono.ppolig;
    while (curr != NULL){
        if(curr->sizepts == max){
            fprintf(fp ,"ID: %d\n", curr->id);
            fprintf(fp ,"Sizepts: %d\n", curr->sizepts);
            for (int i = 0; i < curr->sizepts; ++i) {
                fprintf(fp, "X%d: %d\n", i, curr->ppts->x);
                fprintf(fp, "Y%d: %d\n", i, curr->ppts->y);
            }
        }
        curr = curr->pnxt;
    }

    fclose(fp);
}
