//
// Created by manue on 28/11/2022.
//

#include "tp10.h"

int main_tp10(int argc, const char * argv[]){

    CLASSSTUDENTS_DYNARR csda1 = {"LP1", NULL, 0, 0};

    create_dynarray_classstudents(&csda1, 10);
    insert_student_dynarray_classstudents(&csda1, "Joao", 1111, 11.1f);
    find_student_dynarray_classstudents(csda1, "Joao");

    return 0;
}

void create_dynarray_classstudents(CLASSSTUDENTS_DYNARR *pcs, int initsize){

    pcs->pstudents = (STUDENT *) calloc(initsize, sizeof (STUDENT));

    pcs->size_students = initsize;
    pcs->current_student = 0;
}

void insert_student_dynarray_classstudents(CLASSSTUDENTS_DYNARR *pcs, char name[], int number, float grade){

    STUDENT *ps = pcs->pstudents;
    if(ps == NULL){
        exit(1);
    }
    int oldSize = pcs->size_students, newSize = oldSize*10;
    if(pcs->current_student == pcs->size_students){

        pcs->pstudents = realloc(pcs->pstudents, newSize * sizeof (STUDENT));
        pcs->size_students = newSize;
        ps = pcs->pstudents;
        for (int i = oldSize; i < newSize; ++i) {
            STUDENT s0 = {NULL, 0, 0.0f};
            *(ps+i) = s0;
        }
    }
    (ps+pcs->current_student)->pname = (char *) malloc((strlen(name)+1) * sizeof (char));
    strcpy((ps+pcs->current_student)->pname, name);
    (ps+pcs->current_student)->number = number;
    (ps+pcs->current_student)->grade = grade;
    pcs->current_student++; //-.- (: ;-; -_-
}

STUDENT* find_student_dynarray_classstudents(CLASSSTUDENTS_DYNARR cs, char name[]){

    STUDENT *ps = cs.pstudents;

    if(ps == NULL){
        exit(2);
    }

    for (int i = 0; i < cs.current_student; ++i) {
        if(strcmp(name, ps->pname) == 0){
            return ps;
        }
        ps++;
    }
    return NULL; // ._.
}

STUDENT remove_student_dynarray_classstudents(CLASSSTUDENTS_DYNARR *pcs, char name[]){

    STUDENT *ps = find_student_dynarray_classstudents(*pcs, name);
    STUDENT st = {NULL, 0, 0.0f};

    if(ps == NULL){
        return st;
    }
    st = *ps;
    while (ps < pcs->pstudents+pcs->current_student){
        *ps = *(ps+1);
        ps++;
    }
    STUDENT s0 = {NULL, 0, 0.0f};
    *ps = s0;
    return st;
}