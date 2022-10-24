//
//  pr01.h
//  lp1_ufp
//
//  Created by Rui on 22/09/17.
//  Copyright © 2017 Rui. All rights reserved.
//

#ifndef pr01_h
#define pr01_h

#include <stdio.h>
#include<ctype.h>

/**
* print the ascii value of a given character
* output -> readCharPrintAscii('a') : 97
* @param c - char to be converted 
*/
void print_ascii_for_char(char c);

/**
* Divide two integer values, e.g. 10 / 3 = 3.33
* @param a - dividend
* @param b - divisor
* @return - (float) a / b
*/
float divide_two_ints_into_float(int a, int b);

/**
* Read formatted ints and char: %2d %2d %4d %c
*/
void read_date_and_gender(void);

/**
* Print ascii table letters from 'a' to 'z' and from 'A' to 'Z'
* output:  |       A       |       65      ||      a       |       97      |
       |       B       |       66      ||      b       |       98      |
*/
void print_ascii_table_letters(void);

/**
 * This function checks if a char is a digit or not.
 * @param c - char to be checked.
 * @return 1 (if is digit); 0 otherwise.
 */
int is_digit(char c);

/**
 * Verifica se um char é digito:
 * @param c - char
 * @return 1 se "digito" ou 0 se "nao digito".
 */
int is_digit_v2(char c);

/**
* Iteratively checks if a user input char is a digit (exists with 'e' or 'E')
* e.g.: '0' is a digit; 'a' is not a digit
*/
void read_key_print_digit_or_notdigit(void);

/**
 * Read input stream and counts chars, digits, white spaces and special characters.
 */
void parse_inputstream_count_chartypes(void);

/**
* Counts how many times a given char appears in a
* series of chars entered by the user in input stream.
* @param charToCount - char to count
* @return - number of occurrences
*/
int read_input_stream_count_given_char(char charToCount);

/**
* Finds the longest sequence of repeated chars in a series of chars entered by the user tthrough inputstream.
 e.g.
* input: "abcccdedededef"; output: "The character c appeard consecutively 3 times\n"
* input: "abcdef"; output: "The character a appeard consecutively 1 times\n"
* input: "abdddccdddefffff"; output: "The character f appeard consecutively 5 times\n"
*/
void find_longest_sequence_repeated_chars_from_inputstream (void);

/**
* Finds the logest word in a series of chars iteratively entered by the user through inputstream, e.g.
* input: "ab ccc dededede f"; output: "The longest word has 8 characters\n"
* input: "aa 123 ababa23"; output: "The longest word has 7 characters"
* input: "a b c d e"; output: "The longest word has 1 characters"
*/
void find_longest_word_inputstream (void);

int main_pr01(int argc, const char *argv[]);

#endif /* pr01.h */
