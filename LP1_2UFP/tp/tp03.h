//
//  tp03.h
//  lp1_ufp
//
//  Created by Rui on 10/10/17.
//  Copyright © 2017 Rui. All rights reserved.
//
//  Revised:
//  * 21/09/2020: add summary for the class
//  ==========================================================================
//  2. Estruturação dos programas em funções
//  2.5. Recursividade
//  Mapa de memória de um processo (stack - memória automática).
//  3. Vectores e Strings
//  3.1. Declaração e inicialização de vectores
//  3.2. Passagem de vectores por parâmetro
//  3.3. Definição de constantes e macros
//  Manipulação de vectores de caracteres e vectores de inteiros.
//  ==========================================================================

#ifndef tp03_h
#define tp03_h

#include <stdio.h>
#include "tp02.h"

/**
 * Receives an integer and recursively returns the number of digits,
 * e.g. 218 = 3 digits (2, 1, 8).
 *  @param a - int number to decompose
 *   @return number of digits of a
 */
int number_digits_recursive(int a);

/**
 * Multiplies 2 numbers using a recursive algorithm.
 * @param a - fisrt operand
 * @param b - second operand
 * @return the product of a and b
 */
double multiply_recursive(int a, int b);

/**
 * Uses a recursive algorithm to calculate the factorial of a number.
 * @param n - the number to calculate the factorial from
 * @return the factorial of the parameter
 */
double factorial_recursive(int n);

/**
 * Prints recursively the multiplaction table of a given number.
 * @param n - number to calculate and print the multiplication table
 * @param level - which level of the multiplcation table to print
 */
void print_multable_recursive(int n, int level);

/**
 * Reads vowels from stdin and stores them inside an array.
 * @param vowels - array where to store the vowels
 * @param size - max size of the array
 * @return number of vowels read
 */
int read_store_vowels(char vowels[], int size);

/**
 * Prints the vowels inside an array of chars.
 * @param vowels - array of vowels
 * @param size - max size of the array
 */
void print_vowels(char vowels[], int size);

/**
 * Search an array of ints to find the max value.
 * @param ints - the array of ints
 * @param size - the number of elements in the array
 * @return the max value inside the array
 */
int max(int ints[], int size);

/**
 * Search an array of ints to find the min value.
 * @param ints - the array of ints
 * @param size - the number of elements in the array
 * @return the min value inside the array
 */
int min(int ints[], int size);

/**
 * Calculates the mean of an array of ints.
 * @param ints - the array of ints
 * @param size - the number of elements in the array
 * @return the mean of the elements inside the array
 */
float mean(int ints[], int size);

/** Receives and array of ints and and array with a pattern of numbers to search.
 *  Searches how many segments of the pattern exists inside the array of ints
 *  e.g., v=[5,  2,  2,  3,  4,  4,  4,  4,  1,  1, 2, 2] e p=[2, 2]
 *      would return 2 segments of p exist in v.
 *  @param v - array of ints with patterns of ints
 *  @param sizev - number of elements inside the array
 *  @param r - array with pattern of ints to search
 *  @param sizer - size of the arrray of patterns
 *  @return number of segments p that exist inside the v array
 */
int count_segments_repeated_ints(int v[], int sizev, int r[], int sizer);

/**
 * Unit test funtcion for the 4th TP class.
 */
int main_tp03(int argc, const char * argv[]);


#endif /* tp03_h */
