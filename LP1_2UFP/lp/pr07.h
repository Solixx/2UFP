

#ifndef pr07_h
#define pr07_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MAX100
#define MAX100 100
#endif

/**
* Allocates memory for an array of integers (with malloc) and sets memory with given value.
* @param n - number of positions to be allocated
* @return pointer to the allocated memory
*/
int* alloc_and_setvalue_dyn_int_array(int n, int value);

/**
* Allocates memory for an array of integers, initializing all elements to zero (with calloc).
* @param n - number of positions to be allocated
* @return pointer to the allocated memory
*/
int* alloc_and_init_dyn_int_array(int n);

/**
* Creates or resizes a dynamic int array (with realloc).
* if pints is NULL, create and init new dyn int array
* else returns an array with newsize, initializing the empty positions to zero
* @param pints - array to create or resize
* @param size - current array size (Filled positions)
* @param newsize - new array size
* @return array with the same content of pints, but with newsize
*/
int* create_or_resize_dyn_int_array(int *pints, int size, int newsize);

/**
* Clones and trims the content of a static str into a new dynamic array.
* @param str - static string
* @return trimed string
* i.e. input: char * with 8 elements ((a, b, c, \0, 0, 0, 0, 0)); output: char * with 4 elements (a, b, c, \0)
*/
char* create_copy_dyn_string(char * str);

/**
 * Create dynamic array of pointers to chars (i.e. array of strings).
 * @param size - size of array of strings.
 * @return endereço da nova string alocada.
 */
char** create_dyn_array_strings(int size);

/**
 * Create or resize an array of pointers to strings.
 * @param pstrings - pointer to the first positon of the array of pointers to strings.
 * @param size - size of the arrays of pointers to strings.
 * @param newsize - size of the new arraysof pointers to strings.
 * @return pointer to the first position of the new array of pointers to strings.
 */
char ** create_or_resize_dyn_array_strings(char **pstrings, int size, int newsize);

/**
* Fills an array of strings with dynamic stdin retreived strings.
* The function create_copy_dyn_string() should be used to trim the stdin read string.
* @param pstrings - array of strings
* @param size - size of array os strings
* @return pointer to the array of strings
*/
char** read_dyn_array_strings(char **pstrings, int size);

/**
* Prints a dynamic array of strings using ** notation.
* @param pstrings - static (and empty) array of strings
* @param size - size of astr
*/
void print_dyn_array_strings(char **pstrings, int size);

int main_pr07(int argc, const char * argv[]);

#endif //pr07_h
