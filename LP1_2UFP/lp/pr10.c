//
// Created by manue on 02/12/2022.
//

#include "pr10.h"

int main_pr10(int argc, const char * argv[]){
    CLASSSTUDENTS_QUEUE pcs = {"LP", NULL, 10};

    insert_student_ordered(&pcs, "Manuel", 3, 43);
    printf("%d\n", pcs.nstudents);
    printf("%p\n", pcs.pstudents);

    STUDENT_NODE *curr = pcs.pstudents;
    while (curr != NULL) {
        printf("%p\n", curr);
        printf("Nome: %s\n", curr->student_info.pname);
        printf("Number: %d\n", curr->student_info.number);
        printf("Nome: %f\n", curr->student_info.grade);
        printf("%p\n", curr->pnext);
        curr = curr->pnext;
    }
    insert_student_ordered(&pcs, "Joao", 3, 43);
    curr = pcs.pstudents;
    while (curr != NULL) {
        printf("Nome: %s\n", curr->student_info.pname);
        printf("Number: %d\n", curr->student_info.number);
        printf("Nome: %f\n", curr->student_info.grade);
        curr = curr->pnext;
    }
    insert_student_ordered(&pcs, "t", 3, 43);
    curr = pcs.pstudents;
    while (curr != NULL) {
        printf("Nome: %s\n", curr->student_info.pname);
        printf("Number: %d\n", curr->student_info.number);
        printf("Nome: %f\n", curr->student_info.grade);
        curr = curr->pnext;
    }

    return 0;
}

void insert_student_ordered(CLASSSTUDENTS_QUEUE *pcs, char name[], float grade, int number){

    STUDENT_NODE *pStudent = (STUDENT_NODE *) calloc(1, sizeof(STUDENT_NODE));
    pStudent->student_info.pname = malloc(strlen(name) * sizeof (char));
    strcpy(pStudent->student_info.pname, name);
    pStudent->student_info.grade = grade;
    pStudent->student_info.number = number;
    pStudent->pnext = NULL;

    if(pcs->pstudents == NULL){

        pcs->pstudents = pStudent;
        return;
    }

    STUDENT_NODE *curr = pcs->pstudents;
    while (curr->pnext != NULL){
        curr = curr->pnext;
    }
    curr->pnext = pStudent;
}