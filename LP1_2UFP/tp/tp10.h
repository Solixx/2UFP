//
//  tp10.h
//  lp1_ufp
//
//  Created by Rui on 31/10/17.
//  Copyright © 2017 Rui. All rights reserved.
//

#ifndef tp10_h
#define tp10_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX200 200

/** Define structs for STUDENT and CLASSSTUDENTS_DYNARR */
typedef struct student {
    char *pname;
    int number;
    float grade;
} STUDENT;

typedef struct classstudents {
    char name[MAX200];
    STUDENT *pstudents;
    int size_students; //Size of the dynamic array
    int current_student; //Current number of students inside dynamic array
} CLASSSTUDENTS_DYNARR;

/**
 * Create a dynamic array of students with a given size.
 * @param pcs - pointer to dynamic array (CLASSSTUDENTS_DYNARR).
 * @param initsize - initial size of array.
 */
void create_dynarray_classstudents(CLASSSTUDENTS_DYNARR *pcs, int initsize);

/**
 * Insert a new student into the first available position of CLASSSTUDENTS_DYNARR.
 * @param pcs - pointer to CLASSSTUDENTS_DYNARR
 * @param name - student name.
 * @param number - student number.
 * @param grade - student grade.
 */
void insert_student_dynarray_classstudents(CLASSSTUDENTS_DYNARR *pcs, char name[], int number, float grade);

/**
 * Search student inside dynamic array CLASSSTUDENTS_DYNARR
 * @param cs - copy of CLASSSTUDENTS_DYNARR
 * @param name - name of student to search for.
 * @return pointer to found student (NULLif not found).
 */
STUDENT* find_student_dynarray_classstudents(CLASSSTUDENTS_DYNARR cs, char name[]);

/**
 * Print all students inside dynamic array CLASSSTUDENTS_DYNARR.
 * @param cs - copy of CLASSSTUDENTS_DYNARR
 */
void print_dynarray_classstudents(CLASSSTUDENTS_DYNARR cs);

/**
 * Remove a student from dynamic array CLASSSTUDENTS_DYNARR
 * @param pcs - pointer to CLASSSTUDENTS_DYNARR
 * @param name - name of student to remove
 * @return copy of removed student
 */
STUDENT remove_student_dynarray_classstudents(CLASSSTUDENTS_DYNARR *pcs, char name[]);

/**
 * Free all memory of dynaimc array CLASSSTUDENTS_DYNARR.
 */
void free_dynarray_classstudents(CLASSSTUDENTS_DYNARR *pcs);

int main_tp10(int argc, const char * argv[]);


#endif /* tp10_h */
