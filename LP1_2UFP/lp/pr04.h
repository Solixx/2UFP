//
//  pr04.h
//  lp1_ufp
//
//  Created by Christophe Soares on 28/09/2017.
//  Copyright © 2017 Rui. All rights reserved.
//

#ifndef pr04_h
#define pr04_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXCOLS100 100


//================== Strings ==================

/**
* Capitalize first letter of each word in string
* @param str - string
* @return str - string after capitalization
* e.g. input: "ola Meu mundo" output: "Ola Meu Mundo"
*/
char* capitalize_string(char str[]);

/**
* delete repteades characters in a given string
* @param s - string
* @return trimmed string
* e.g. input: ("abcadbf"); output: "abcdf"
* e.g. input: ("aa   bb"); output: "a b"
*/
char* delete_repeated_chars(char s[]); // e.g. "abcadbf" -> "abcdf"

/**
* shift all the characters in a given string
* @param s - string
* @param n - number of shifts. if n<0 shift left; if n>0 shift right
* @return shifted string
* e.g. input: ("hello",  2); output: "lohel"
* e.g. input: ("hello", -1); output: "elloh"
*/
char* shift_n(char s[], int n); // e.g. "hello" 2 -> "lohel"  | "hello" 2 -> "elloh"

/**
* replace all the ocurrences of a given substring in a given string
* @param str - main string
* @param sub - substring to be replaced
* @param rep - replacement substring
* @return str after replacement
* e.g. input: ("olaxxxmeuxxxmundo", "xxx", "??"); output: "ola??meu??mundo" 
*/
char* replace_sub2rep(char str[], char sub[], char rep[]); // "olaxxxmeuxxxmundo" - "xxx" - "??" -> "ola??meu??mundo"


//======================= Matrixes =======================

/**
* multiply matrix by scalar
* @param m - matrix to be multiplied
* @param lines - number of matrix lines
* @param columns - number of matrix columns
* @param scalar - multiplier
* e.g. input: ([[5, 8], [4, 3]], 3); output: [[15, 24], [12, 9]]
*/
void multiply_matrix_by_scalar (int m[][MAXCOLS100], int lines, int columns, int scalar);

/**
* Sum the integer of the diagonal elements of a matrix
* @param mNx100 - matrix
* @param lines - number of line
* @param columns - number of columns
* @return sumdiag - sum of diagonal elements.
* e.g. input: 1 2 3 output: "15"
*             4 5 6
*             7 8 9
*/
int sum_diagonal_mNx100(int mNx100[][MAXCOLS100], int lines, int columns);

/**
 * Multiply a line of matrix A by a column of matrix B and store the resulte into a cell of matrix C.
 * @param mA100 - matrix A
 * @param mB100 - matrix B
 * @param mC100 - matrix C store the result
 * @param lineA - line of matrix A
 * @param columnB - column of matrix B
 * @param colsAlinesB - number of columns of A and lines of B (which must be the same)
 */
int multiply_line_column_NxMAXCOLS100(int mA100[][MAXCOLS100], int mB100[][MAXCOLS100], int mC100[][MAXCOLS100], int lineA, int columnB, int columnsAlinesB);

/**
* Multiply two matrices A and B to produce results into matrix C.
* @param mA100 - matrix A
* @param mB100 - matrix B
* @param mC100 - matrix to store the result
* @param linesA - number of lines in matrix A
* @param columnsB - number of columns in matrix B
*/
void multiply_matrixesNxMAXCOLS100(int mA100[][MAXCOLS100], int mB100[][MAXCOLS100], int mC100[][MAXCOLS100], int linesA, int columnsB);


int main_pr04(int argc, const char * argv[]);

#endif /* pr04_h */



