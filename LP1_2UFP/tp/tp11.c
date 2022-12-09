//
// Created by manue on 05/12/2022.
//

#include "tp11.h"

int main_tp11(int argc, const char * argv[]){

    DYNARRAYRECTS dar1 = {NULL, 0};

    create_dyn_array_rects(&dar1, 10);
    for (int i = 0; i < dar1.size; ++i) {
        RECT r = {{0.0f + i, 0.0f + i}, {1.0f + i, 1.0f + i}};
        insert_rect_dyn_array_rects(&dar1, r);
    }

    save_dyn_array_rects_txt(dar1, "../data/rects.txt");
    return 0;
}

void create_dyn_array_rects(DYNARRAYRECTS *pdar, int numberOfRectangles){

    RECT *pr = (RECT*) calloc(numberOfRectangles, sizeof (RECT));
    pdar->prects = pr;
    pdar->size = numberOfRectangles;
}

void insert_rect_dyn_array_rects(DYNARRAYRECTS *pdar, RECT rect){

    RECT *pr = pdar->prects;
    for (int i = 0; i < pdar->size; ++i) {
        RECT r0 = {{0.0f, 0.0f}, {0.0f, 0.0f}};
        if(compare_rects(r0, *pr) == 1){
            *pr = rect;
            break;
        }
        pr++;
    }
}

void save_dyn_array_rects_txt(DYNARRAYRECTS dar, char filename[]){

    FILE *fp = NULL;
    RECT *pr = dar.prects;

    if((fp = fopen(filename, "w")) == NULL){
        fprintf(stdout, "Erro a abrir o ficheiro %s\n", filename);
        return;
    }
    fprintf(fp, "Rectangles: %d\n", dar.size);
    for (int i = 0; i < dar.size; ++i) {
        fprintf(fp, "RECT %d: %0.1f %0.1f %0.1f %0.1f\n", i, pr->downpt.x, pr->downpt.y, pr->uppt.x, pr->uppt.y);
        pr++;
    }
    fclose(fp);
}