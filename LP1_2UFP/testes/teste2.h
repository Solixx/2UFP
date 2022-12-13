//
// Created by pc on 07/12/2022.
//

#ifndef LP1_2UFP_TESTE2_H
#define LP1_2UFP_TESTE2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fish{
    char *fname;
    short fyears;
    struct fish *pnxt;
}FISH;

typedef struct species{
    char *sname;
    FISH *phead;
}SPICIES;

typedef struct aquario{
    int nspecies;
    SPICIES *pspecie;
}AQUARIO;

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


typedef struct field {
    char fname[20];
    char *pfvalue;
    int weight;
    struct field *pnxt;
} FIELD;

typedef struct contact {
    char *pname;
    FIELD *pfield;
    struct contact *pnxt;
} CONTACT;

typedef struct manager {
    int ncontacts;
    CONTACT *pfirst;
} MANAGER;


typedef struct cel {
    int info;
    struct cel *pn,*ps,*pw,*pe,
            *pno,*pne,*pso,*pse;
} CEL;

typedef struct line {
    int ncols;
    CEL *pcels;
} LINE;

typedef struct matrix {
    int nlines;
    LINE *plines;
} MATRIX;

typedef struct returnList {
    int x, y;
    struct returnList *next;
} RETURNLIST;

int main_teste2(int argc, const char * argv[]);
void teste2022();
void teste2019();
void teste2016();
void teste2018();
void inserir_pt_poligono(LSTPOLIG lstpoligono, int id, PT pts);
void grava_poligonos_com_mais_pts_txt(LSTPOLIG lstpoligono, char *filename);
void add_field_contact(MANAGER mg, FIELD *newField, char *name);
CONTACT find_contact_with_field(MANAGER mg, char* name);
CONTACT find_contact_with_field2(MANAGER mg, FIELD fileSearch);
RETURNLIST find_cells_with_value(MATRIX mat, int valor);
void inserir_fish(AQUARIO *aq, char* nameS, char* nameP, short ano);
void read_txt();

#endif //LP1_2UFP_TESTE2_H
