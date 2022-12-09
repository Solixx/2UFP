//
// Created by pc on 07/12/2022.
//

#ifndef LP1_2UFP_TESTE2_H
#define LP1_2UFP_TESTE2_H

#include <stdio.h>
#include <stdlib.h>

typedef struct pt {
    int x, y;
} PT;

typedef struct poligono {
    int id, sizepts;
    PT *ppts;
    struct poligono *pnxt;
} POLIGONO;

typedef struct lstpolig {
    POLIGONO *ppolig;
    int sizepolig;
} LSTPOLIG;

int main_teste2(int argc, const char * argv[]);
void inserir_pt_poligono(LSTPOLIG lstpoligono, int id, PT pts);
void grava_poligonos_com_mais_pts_txt(LSTPOLIG lstpoligono, char *filename);

#endif //LP1_2UFP_TESTE2_H
