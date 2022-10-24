//
//  pr05.h
//  lp1_ufp
//
//  Created by Christophe Soares on 28/09/2017.
//  Copyright © 2017 Rui. All rights reserved.
//

#ifndef pr05_h
#define pr05_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ALPHABET_LETTERS 27


/**
* Calc the roots of a 2º grade polinomial ax^2 + bx + c
* @param a - retreived from ax^2
* @param b - retreived from bx
* @param c - retreived from c
* @param r1 - first root
* @param r2 - second root
* i.e. input: (2, -14, 20, &r1, &r2); output: r1=5.00, r2=2.00
*/
void calc_roots(int a, int b, int c, double* r1, double* r2); // 2x^2-14x+20    r1=5.00    r2=2.00

/**
* Swap two positions of a given double array, using pointer notation
* @param pi - pointer to the first position of the double array
* @param pos1 - position 1
* @param pos2 - position 2
* @return array after swap
* i.e. input: ((1, 2, 3, 4), 0, 2); output: (3, 2, 1, 4)
*/
double* swap_double_array_ptr(double* pi, int pos1, int pos2);  // pi[]={1,2,3,4} -> swap 0 e 2 -> {3,2,1,4}

/**
* Find the highest and lowest numbers in a given array
* @param pi - pointer to the first position of the given array
* @param size - array size
* @param maxmin - pointer to the first position of the maxmin array
* @return maxmin array
* i.e. input: (11, 23, -1, 7); output: (-1, 23)
*/
int* search_minmax(int *pi, int size, int *maxmin); // arrInts[]={11,23,-1,7} -> min-> -1    max-> 23

/**
* Prints all the elements in a given double array
* @param pi - pointer to the first position of the given array
* @param size - array size
*/
void print_array_double_with_index(double *pi, int size);

/**
* Prints all the elements in a given double array, without using an index var to iterate the array
* @param pi - pointer to the first position of the given array
* @param size - array size
*/
void print_array_double_without_index(double *pi, int size);

/**
* Stores the 26 characters of the alphabet in a string and prints them using pointer notation.
*/
void init_and_print_alphabet (void);


/**
 * Calculates the mode of an array of ints.
 * @param a - addr on an array of ints
 * @param n - size of the array of ints
 * @return mode of the array of ints.
 */
int mode (int * a, int n);

/**
 * Orders an array of ints upward.
 * @param a - an array of ints
 * @param n - size of the array of ints
 * @return addr of ordered array of ints.
 */
int* bubble_sort (int * a, int n);

/**
 * Calculates the median of an array of ints.
 * @param a - addr on an array of ints
 * @param n - size of the array of ints
 * @return median of the array of ints.
 */
double median (int * a, int n);

/**
* Find the mode, mean and median of a given integer array
* @param pi - pointer to the first position of the given array
* @param size - array size
* @param mmm - pointer to the first position of the array containing the results
* @return mmm (mode, mean and median) of the given array
* i.e. input: ((11, 23, -1, 7, 11, -10, 5, 1), 8); output: (11, 5.88, 5)
*/
double* find_mode_mean_median (int *pi, int size, double *mmm);

/**
* Implement the traditional  strstr() function, using pointer notation.
* Checks/returns the first occurrence of a substring inside a given string.
* @param pstr - pointer to the first position of the given string
* @param psubstr - pointer to the first position of the given substring
* @return pointer to the first occurrence of substr inside str or NULL if not present.
*/
char* strstr_ptr(char* pstr, char * psubstr);

int main_pr05(int argc, const char * argv[]);

#endif /* pr05_h */



