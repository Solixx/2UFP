//
//  tp02.h
//  lp1_ufp
//
//  Created by Rui on 10/10/17.
//  Copyright © 2017 Rui. All rights reserved.
//

//  Revised:
//  * 21/09/2020: add summary for the class
//  ==========================================================================
//  1. Introdução à programação em C
//  1.4. Estruturas de controle básicas
//  1.4.1. Execução condicional (if-else; switch)
//  1.4.2. Ciclos (for, while, do-while)
//  1.4.3. Controlo da execução (break, continue)
//  2. Estruturação dos programas em funções
//  2.1. Definição de funções
//  2.2. Passagem de parâmetros por valor
//  2.3. Variáveis locais
//  2.4. Valores de retorno
//  Exercícios introdutórios de I/O e manipulação de dados.
//  ==========================================================================


#ifndef tp02_h
#define tp02_h

#include <stdio.h>
#include <ctype.h>


/**
 * This function checks if a char is a vowel.
 * @param c - the char to be checked.
 * @return 1 (if is vowel: 'a' 'e' | 'i' | 'o' | 'u'); 0 otherwise.
 */
int is_vowel(char c);

/**
 * This function checks if a char is a consonante.
 * @param c - the char to be checked.
 * @return 1  (if is consonant); 0 otherwise.
 */
int is_consonant(char c);

/**
 * This function checks if a char is a white/invisible.
 * @param c - the char to be checked.
 * @return 1 (if is white char: ' ' '\t' | '\n' | '\r'); 0 otherwise.
 */
int is_whitechar(char c);

/**
 * Ler em ciclo uma tecla seguida por \n (Terminar com '.') e para cada tecla
 * imprime %c - is digit | not digit.
 */
void read_keyspressed_printdigits(void);

/**
 * This function prints a char type: digit, vowel, consonant, special.
 * @param c - the char to be checked.
 */
void prints_keytype(char c);

/**
 * Esta função deverá ler em ciclo uma tecla seguida por \n (Terminar com '.')
 * e para cada tecla imprimir o tipo de caracter, i.e.
 * digito =  %d", "vogal = %c", "consoante = %c", "outro = %c".
 */
void read_keyspressed_print_keytype(void);

/**
 * This function read characters from stdin (WITHOUT using strings) managing only input from
 * the keyboard buffer and counting the number of words (set of chars separated by whitespaces, i.e.
 * {' ', '\t', '\n', '\r'}.
 * @return number of words inserted through keyboard buffer.
 */
int count_words_stdin(void);

/**
 * This function receives an integer and iteratively returns the number of digits,
 * e.g. 218 = 3 digits (2, 1, 8).
 *  @param n - an int value to be sperated in digits.
 *  @return the number of digits found on the submitted int value.
 */
int number_digits_iterative(int n);

/**
* Receives an integer and iteratively counts the frequency of odd and even digits
* e.g. 218 2 = returns frequency of even digits = 3 (because > frequency of odd).
* @param n - integer number;
* @return even or odd digits highest frequency.
*/
short highest_even_or_odd_digits_frequency(int n);
    
/**
 * Receives an integer and iteratively returns the highest frequency of digit,
 * e.g. 218 2 = returns digit 2 which has highest frequency.
 * @param n - integer number;
 * @return digit with highest frequency.
 */
short highest_frequency_digit(int n);

/// Test funtcion for class tp03
int main_tp02(int argc, const char * argv[]);

#endif /* tp03_h */
