//
//  pr06.h
//  lp1_ufp
//
//  Created by Christophe Soares on 28/09/2017.
//  Copyright © 2017 Rui. All rights reserved.
//

#ifndef pr06_h
#define pr06_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef MAX100
#define MAX100 100
#endif


//Funcao calculadora via params consola (cf. argc, argv);
//Usar if(strcmp()==0) else if(...) OU switch com 3º char argv[2];
/**
* Computes the sum (PLUS), subtraction (MINUS), multiplication (MULT) or division (DIV) of two
* received numbers. NB: use operations: plus/sub/mult/div (because wildchar '*' does not work!!)
* @param argc - number of args
* @param argv - numbers and operation
* @return - result
* i.e. input:(4, ("./prog.exe", "12", "PLUS", "3")); output: 15
* i.e. input:(4, ("./prog.exe", "5", "MULT", "4")); output: 20
*/
int calculator_command_line(int argc, const char *argv[]);

/**
* Receives and array of strings and concatenates them into a single string.
* i.e. input:(3, ("ola", " mundo", "!"), ""); output: "ola mundo!"
* i.e. input:(4, ("four", " args", " to", " cat"), ""); output: "four args to cat"
* @param astrs - array of strings
* @param str - resulting string after concatenation
* @return - address of string after concatenation
*/
char* cat_strings(int size, const char *astrs[], char str[]);

/**
* Function that omputes the frequency of each word in the array of strings.
* i.e. input:(6, ("aa", "bbb", "ccc", "aa", "ccc", "aa"), ""); output: 3, freq[] = {3, 1, 2}
* i.e. input:(6, ("aa", "bbb", "ccc", "aaa", "ccc", "ddd"), ""); output: 5, freq[] = {1, 1, 2, 1, 1}
* @param argc - number of args
* @param astr - set of astr
* @param freqs - frequencies of each string
* @return - number of distinct strings in argv (size of freqs)
*/
int frequencies_strings(int argc, const char *astr[], int freqs[]);

/**
* sums all numbers is argv
* @param argc - number of args
* @param astr - set of args
* @return argv sum
* i.e. input: (3, ("1", "2", "3")); output: 6
* i.e. input: (5, ("1", "2", "3", "4", "1")); output: 11
*/
int sum_all_astr(int argc, const char *astr[]);

/**
 * Checks if str exists into astr before position i.
 * @param str - string to check.
 * @param astr - array of strings to be cheked against.
 * @param line - position before which to check.
 * @return 0 (false) or 1 (true).
 */
int str_exists_before(const char str[], const char *astr[], int line);

/**
* Concatenates an array of strings into a single string, but without repeating strings.
* i.e. input:(4, ("ola", " mundo", "mundo", "!"), ""); output: "ola mundo!"
* i.e. input:(5, ("four", " args", " to", " four", " cat"), ""); output: "four args to cat"
* @param pstrs - array of strings
* @param str - resulting string after concatenation
* @return - resulting string after concatenation
*/
char* cat_distinct_strings(int argc, const char *pstrs[], char str[]);

/**
* Splits a string by a set of user-defined delimiters. The result is stored
* in a given array of strings.
* @param string - input string
* @param matStrs - matrix where each line is a substring of parsed string splitted by a delimiter.
* @param delimiter - delimiters string
*/
void explode_string (char * string, char matStrs[][MAX100], char * delimiter);

int main_pr06(int argc, const char * argv[]);

#endif /* pr06_h */



