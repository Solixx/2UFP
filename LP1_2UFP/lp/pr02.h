//
//  pr02.h
//  lp1_ufp
//
//  Created by Christophe Soares on 28/09/2017.
//  Copyright © 2017 Rui. All rights reserved.
//

#ifndef pr02_h
#define pr02_h

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

//================== Aulas 2022 ==================
//NB: nos exercícios seguintes não se deve utilizar strings/arrays,
//apenas o buffer teclado quando aplicável.

/** 
	* Iteratively reads chars (from '0' to '9') and returns the complete decimal number
	* @return - decimal number
	* e.g. input: ('2', '1', '8', 'e') => output: 218
	* e.g. input: ('4', '3', 'e') => output: 43
 */
int read_digits_to_int(void);

/**
	* Splits a number and prints each class in ascending order
	* @param n - decimal value to be splited
	* e.g. input: (218); output => 8, 1, 2
*/
void print_numbers_classes_from_units_upper(int n);


/**
    * Splits a number and prints each class in a descending order.
    * @param n - decimal value to be splited
    * e.g. input: (218); output => 2, 1, 8
*/
void print_numbers_classes_from_higher_downward(int n);

/**
	* Splits a number and prints each class in a descending order recursivelly.
	* @param n - decimal value to be splited
	* e.g. input: (218); output => 2, 1, 8
*/
void print_numbers_classes_from_higher_downward_recursive(int n);

/**
	* Iteratively multiplies two numbers by unfolding the multiplication into sums
	* @param a - num to be multiplied
	* @param b - multiplier
	* @return - multilpication result
	* e.g. input: (2, 5) => output: 10
*/
int multiplication_as_sums (int a, int b);

/**
	* Prints the multiplication table for a given number
	* @param num - input number
	* e.g. input: (2) => output: 2x1=2\n2x2=4\n2x3=6 ...
*/
void print_multiplication_table (int num);


/**
	* prints inverted pyramid
	* @param width - pyramid's base width
	* e.g. input: (5); output:
    * 1 2 3 4 5
	*   2 3 4
	*     3
*/
void print_pyramid (int width);

/**
    * Checks if a number is triangular, i.e., the product of three consecutive int numbers.
    * @param num - number to be checked
    * @return - true (0) or false (1)
    * e.g. input: 6 = output: is triangular 6 = 1 x 2 x 3
    * e.g. input: 504 => output: is triangular 504 = 7x8x9
    * e.g. input: 1320 => output: is triangular 1320 = 10x11x12
*/
int is_number_triangular (unsigned int num);

/** Separa e imprime um número int em duas metades, e.g., 284 -> 2 e 4; 4587 -> 45 e 87.
 * @param n - int number to split in half.
 */
void splits_in_half(int n);

int main_pr02(int argc, const char * argv[]);

#endif /* pr02_h */
