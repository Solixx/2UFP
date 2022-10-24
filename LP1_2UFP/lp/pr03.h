//
//  pr03.h
//  lp1_ufp
//
//  Created by Christophe Soares on 28/09/2017.
//  Copyright © 2017 Rui. All rights reserved.
//

#ifndef pr03_h
#define pr03_h

#include <stdio.h>
#include <math.h>

//================== Aulas 2020 ==================

/**
* recursively raises b to the power of e
* @param b - base
* @param e - exponent
* @returns b^e
* e.g. input: (2, 5); output: 32
* e.g. input: (10, 1); output: 10
* e.g. input: (3, 0); output: 1
*/
int pow_recursive(int b, int e);

/**
* iteratively prints n parts of the hangman 
* @param level - number of members to print
* e.g. input: (6); output:
*  \O/
*   |
*  / \
*/
void print_hangman_iterative(int level);

/**
* recursively prints n parts of the hangman 
* @param level - number of members to print
* e.g. input: (6); output:
*      O
*     /|\
*     / \
*/
void print_hangman_recursive(int level);

/**
* compare two integer arrays with the same size
* @param a - array for comparison
* @param b - array for comparison
* @param size - size for both arrays
* @return 0 if (a == b) ; -1 if (a < b) ; 1 if (a > b)
* e.g. input: ([1, 2, 3, 4], [1, 2, 3, 5], 4); output: -1
* e.g. input: ([1, 3, 3, 4], [1, 2, 3, 4], 4); output: 1
* e.g. input: ([1, 2, 3, 4], [1, 2, 3, 4], 4); output: 0
*/
int int_compare(int a[], int b[], int size);

/**
* searches for the lowest index of a given integer
* @param v - array to be searched
* @param n - number to search
* @param size - array size
* @return - lowest index which contains the integer n
* e.g. input: ([1, 4, 2, 4], 4, 4); output: 1
*/
int lowest_index_number(int v[], int n, int size);

/**
* searches for the highest index of a given integer
* @param v - array to be searched
* @param n - number to search
* @param size - array size
* @return - highest index which contains the integer n
* e.g. input: ([1, 4, 2, 4], 4, 4); output: 3
*/
int highest_index_number(int v[], int n, int size);

/**
* finds the number with the highest frequency (mode) in a given array
* @param v - array to be searched
* @param size - array size
* @return mode of array
* e.g. input: ([1, 4, 2, 4], 4); output: 4
* e.g. input: ([1, 1, 1, 4], 4); output: 1
*/
int number_highest_frequency(int v[], int size);

/**
* get the lenght of the greatest sequence of repeated ints
* @param v - array to be searched
* @param size - array size
* @return - lenght of the greatest sequence
* e.g. input: ([55, 22, 22, 33, 44, 44, 44, 1, 1], 9); output: 3
*/
int size_greatest_segment_repeated_ints(int v[], int size);

/**
* count the number of clumps (a series of 2 or more adjacent equal
* elements) in a given array
* @param a - array to be searched
* @param size - array size
* @return - number of clumps
* e.g. input: ([30, 41, 41, 18, 24, 24, 4, 12], 8); output: 2
* e.g. input: ([30, 41, 42, 18, 24, 24, 24, 12], 8); output: 1
* e.g. input: ([30, 41, 42, 18, 24, 25 , 4, 12], 8); output: 0
*/
int count_clumps (int a[], int size);

int main_pr03(int argc, const char * argv[]);

#endif /* pr03_h */



