//
// Created by manue on 14/11/2022.
//

#include "tp08.h"

int main_tp08(int argc, const char * argv[]){

    struct pt pt1 = {2.0f, 3.0f};
    struct pt pt2 = {1.0f, 3.0f};
    struct pt p1;
    RECT r1;

    //printf("%d\n",  compare_pts(pt1, pt2));
    //read_pt(&pt1);
    p1 = read_pt_v2();
    r1 = read_rect_v2();
    //print_pt("Ponto P1", pt1);

    return 0;
}

int compare_pts(struct pt pt1, struct pt pt2){
    return pt1.x == pt2.x && pt1.y == pt2.y;
}

int compare_rects(RECT r1, RECT r2){
    return compare_pts(r1.downpt, r1.uppt);
}

struct pt* create_pt(struct pt p){
    struct pt *paux = (struct pt *) malloc(sizeof (struct pt));

    // 1º forma de fazer
    paux->x = p.x;
    paux->y = p.y;

    // 2º forma de fazer
    /*
    (*paux).x = p.x;
    (*paux).y = p.y;
     */

    // 3º forma de fazer
    //*(paux) = p;

    return paux;
}

struct rect* create_rect(RECT r){

    struct rect *paux = (RECT *) malloc(sizeof (RECT));

    // 1º forma de fazer - (Diferença entre a anterior é que como downpt/uppt nao são structs temos de usar o ".")
    paux->downpt.x = r.downpt.x;
    paux->downpt.y = r.downpt.y;
    paux->uppt.x = r.uppt.x;
    paux->uppt.y = r.uppt.y;

    // 2º forma de fazer
    /*
    (*paux).downpt.x = r.downpt.x;
    (*paux).downpt.y = r.downpt.y;
    (*paux).uppt.x = r.uppt.x;
    (*paux).uppt.y = r.uppt.y;
     */

    // 3º forma de fazer
    //*(paux) = r;

    return paux;
}

void read_pt(struct pt* pp){
    printf("Insira um ponto\n");
    // 1º forma
    scanf("%f%f", &pp->x, &pp->y);

    //2º forma
    //scanf("%f%f", &(*pp).x, &(*pp).y);

    /*
    printf("%f\n", pp->x);
    printf("%f\n", pp->y);
     */
}
struct pt read_pt_v2(void){
    struct pt p;
    scanf("%f%f", &p.x, &p.y);
    return p;
}

void read_rect(RECT* pr){
    printf("Insira um retangulo\n");
    // 1º forma
    read_pt(&pr->downpt);
    read_pt(&pr->uppt);

    // 2º forma
    /*
    read_pt(&(*pr).downpt);
    read_pt(&(*pr).uppt);
     */
}
RECT read_rect_v2(void){
    RECT rec;
    rec.downpt = read_pt_v2();
    rec.uppt = read_pt_v2();
    return rec;
}

void print_pt(char pt_label[], struct pt p){
    printf("%s: (%0.0f, %0.0f)\n", pt_label, p.x, p.y);
}

void print_rect_v1(char rect_label[], RECT r){
    printf("%s:\n", rect_label);
    print_pt("Down Pt", r.downpt);
    print_pt("Up Pt", r.uppt);
}

void print_rect_v2(char rect_label[], const RECT *pr){
    printf("%s:\n", rect_label);
    // 1º forma
    print_pt("Down Pt", pr->downpt);
    print_pt("Up Pt", pr->uppt);

    // 2º forma
    print_pt("Down Pt", (*pr).downpt);
    print_pt("Up Pt", (*pr).uppt);
}