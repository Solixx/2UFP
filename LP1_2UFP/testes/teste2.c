//
// Created by pc on 07/12/2022.
//

#include "teste2.h"

int main_teste2(int argc, const char * argv[]){

    teste2022();
    //teste2019();
    //teste2016();
    //teste2018();

    return 0;
}

void teste2022(){

    FISH f2 = {"r", 5, NULL};
    FISH f1 = {"T", 2, &f2};
    SPICIES s[1] = {"Salmao", &f1};
    AQUARIO aq = {1, s};

    inserir_fish(&aq, "Tigre", "TR", 2);
}

void inserir_fish(AQUARIO *aq, char* nameS, char* nameP, short ano){

    int specieExist = 0;
    for (int i = 0; i < aq->nspecies; ++i) {
        if(strcmp(aq->pspecie[i].sname, nameS) == 0){
            specieExist = 1;
            if(aq->pspecie->phead == NULL){
                strcpy(aq->pspecie->phead->fname, nameP);
                aq->pspecie->phead->fyears = ano;
                aq->pspecie->phead->pnxt = NULL;
                break;
            }
            FISH *curr = aq->pspecie->phead;
            while (curr->pnxt != NULL){
                curr = curr->pnxt;
            }
            curr->pnxt = (FISH *) malloc(1 * sizeof (FISH));
            curr->pnxt->fname = (char*) malloc(strlen(nameP) * sizeof (char));
            strcpy(curr->pnxt->fname, nameP);
            curr->pnxt->fyears = ano;
            curr->pnxt->pnxt = NULL;
        }
    }
    if(specieExist == 0){
        aq->pspecie = (SPICIES *) realloc(aq->pspecie, (aq->nspecies+1) * sizeof (SPICIES));
        strcpy(aq->pspecie[aq->nspecies-1].sname, nameS);
        aq->pspecie[aq->nspecies-1].phead = (FISH*) malloc(1 * sizeof (FISH));
        strcpy(aq->pspecie[aq->nspecies-1].phead->fname, nameP);
        aq->pspecie[aq->nspecies-1].phead->fyears = ano;
        aq->pspecie[aq->nspecies-1].phead->pnxt = NULL;
    }
}

void teste2019(){

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
                fprintf(fp, "X%d: %d\n", i, curr->ppts->x); //pode ser que seja nessecario curr->ppts[i]->x
                fprintf(fp, "Y%d: %d\n", i, curr->ppts->y); //pode ser que seja nessecario curr->ppts[i]->y
            }
        }
        curr = curr->pnxt;
    }

    fclose(fp);
}

void teste2016(){

    CONTACT cont2 = {"Tio", NULL, NULL};
    CONTACT cont = {"Manuel", NULL, &cont2};
    MANAGER ms = {1, &cont};

    FIELD newField = {"Jose", "20", 20, NULL};
    FIELD newField2 = {"Ze", "20", 20, NULL};

    add_field_contact(ms, &newField, "Manuel");
    add_field_contact(ms, &newField2, "Manuel");

    CONTACT *curr = ms.pfirst;
    while (curr != NULL){
        FIELD *currF = curr->pfield;
        printf("CONTACTO: %s\n", curr->pname);
        while (currF != NULL){
            printf("Name: %s\n", currF->fname);
            printf("Value: %s\n", currF->pfvalue);
            printf("Weight: %d\n", currF->weight);
            currF = currF->pnxt;
        }
        curr = curr->pnxt;
    }

    CONTACT findContc = find_contact_with_field(ms, "Manuel");
    printf("Find Name: %s\n", findContc.pname);

    CONTACT findContc2 = find_contact_with_field2(ms, newField2);
    printf("Find Name: %s\n", findContc2.pname);
}

void add_field_contact(MANAGER mg, FIELD *newField, char *name){

    //newField = (FIELD*) malloc(1 * sizeof (FIELD));
    CONTACT *curr = mg.pfirst;
    while (curr != NULL){
        if(curr->pname == name) break;
        curr = curr->pnxt;
    }
    FIELD *currF = curr->pfield;
    if(curr->pfield == NULL){
        currF = (FIELD*) malloc(1*sizeof (FIELD));
        currF = newField;
        curr->pfield = currF;
        return;
    }
    while (currF->pnxt != NULL){
        currF = currF->pnxt;
    }
    currF->pnxt = (FIELD*) malloc(1*sizeof (FIELD));
    currF->pnxt = newField;
}

CONTACT find_contact_with_field(MANAGER mg, char* name){

    CONTACT *curr = mg.pfirst;
    while (curr != NULL){
        if(curr->pname == name) break;
        curr = curr->pnxt;
    }
    return *curr;
}

CONTACT find_contact_with_field2(MANAGER mg, FIELD fileSearch){

    CONTACT *curr = mg.pfirst;
    while (curr != NULL){
        FIELD *currF = curr->pfield;
        while (currF != NULL){
            if((strcmp(currF->fname, fileSearch.fname)==0)&& currF->weight == fileSearch.weight && (strcmp(currF->pfvalue, fileSearch.pfvalue) == 0)) return *curr;
            currF = currF->pnxt;
        }
        curr = curr->pnxt;
    }
    return *curr;
}

void teste2018(){

    CEL col45 = {8};
    CEL col44 = {9};
    CEL col43 = {3};
    CEL col42 = {4};
    CEL col41 = {2};

    CEL col35 = {12};
    CEL col34 = {44};
    CEL col33 = {8};
    CEL col32 = {5};
    CEL col31 = {9};

    CEL col25 = {4};
    CEL col24 = {9};
    CEL col23 = {0};
    CEL col22 = {3};
    CEL col21 = {2};

    CEL col15 = {44};
    CEL col14 = {8};
    CEL col13 = {7};
    CEL col12 = {4};
    CEL col11 = {1};

    CEL col111[5] = {{1},{4}, {7}, {8}, {44}};
    CEL col222[5] = {{2},{3}, {0}, {9}, {4}};
    CEL col333[5] = {{9},{5}, {8}, {44}, {12}};
    CEL col444[5] = {{2},{4}, {3}, {9}, {8}};

    LINE lin[4] = {{5, col111}, {5, col222}, {5, col333}, {5, col444}};

    MATRIX mat = {4, lin};

    RETURNLIST ret = find_cells_with_value(mat, 8);
    RETURNLIST *curr = &ret;
    while (curr->next != NULL){
        printf("Ret x: %d\n", curr->x);
        printf("Ret y: %d\n", curr->y);
        curr = curr->next;
    }
}

RETURNLIST find_cells_with_value(MATRIX mat, int valor){

    int t = 0;
    RETURNLIST *ret = NULL;
    RETURNLIST *curr;
    for (int i = 0; i < mat.nlines; ++i) {
        for (int j = 0; j < mat.plines[i].ncols; ++j) {
            if(mat.plines[i].pcels[j].info == valor){
                if(t == 0){
                    if(ret == NULL){
                        ret = (RETURNLIST*) malloc(1*sizeof (RETURNLIST));
                        ret->x = i;
                        ret->y = j;
                        ret->next = NULL;
                        t = 1;
                        curr = ret;
                        continue;
                    }
                }
                while (curr->next != NULL){
                    curr = curr->next;
                }
                curr->next = (RETURNLIST*) malloc(1*sizeof (RETURNLIST));
                curr->next->x = i;
                curr->next->y = j;
                curr->next->next = NULL;
                ret = curr->next;
            }
        }
    }
    return *curr;
}