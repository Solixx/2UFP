//
//  tp04.h
//  lp1_ufp
//
//  Created by Rui on 18/10/17.
//  Copyright © 2017 Rui. All rights reserved.
//
//  Revised:
//  * 21/09/2020: add summary for the class
//  ==========================================================================
//  3. Vectores e Strings
//  3.4. Cadeias de caracteres (Strings)
//  3.5. Funções de manipulação de Strings
//  3.6. Vectores multi-dimensionais
//  Representação de matrizes 2D e linearização de matrizes.
//  ==========================================================================

#ifndef tp04_h
#define tp04_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp03.h"

#define MAXCOLS100 100
#define NCOLUMNS 100

/**
 * Função que procura o índice da 1a vogal na string dada.
 * @param str - string a analisar.
 * @return index da primeira vogal da string
 * */
int index_first_vogal(char str[]);

/**
 * Função que substitui um char o por outro r numa string.
 * @param str - string a analisar.
 * @param o - char original a substiruir.
 * @param r - char pelo qual substituir.
 * @return endereço da string actualizada.
 */
char* replace_char_by_char(char str[], char o, char r);

/**
 * Função que remove caracteres brancos existentes na string.
 * @param str - string a analisar.
 * @return endereço da string actualizada.
 */
char* remove_blanks(char str[]);


/**
 * Função que retorna índiice mais à esquerda de sub dentro de str.
 * @param str - string a analisar.
 * @aparam sub - sub string a encontrar.
 * @return índice da sub na str.
 *
 */
int index_sub_left(char str[], char sub[]);

/**
 * Função que retorna índice mais à direita de sub dentro de str.
 * @param str - string a analisar.
 * @aparam sub - sub string a encontrar.
 * @return índice da sub na str.
 *
 */
int index_sub_right(char str[], char sub[]);

/**
 * Função que remove substring sub da string str.
 * @param str - string a analisar.
 * @param sub - substring com chars a remover.
 * @return endereço da string actualizada.
 */
char* remove_sub(char str[], char sub[]);


/**
 * Função que imprime matrizes Nx100.
 * @param mNx100 - matriz com número máximo de colunas definido por MAXCOLS100.
 * @param lines - número de linhas da matriz.
 * @param columns - número de colunas da matriz (<MAXCOLS100).
 */
void print_matrixNx100_ints(int mNx100[][MAXCOLS100], int lines, int columns);

/**
 * Função de inicialização/leitura de matriz de ints cujo número columns < MAXCOLS100.
 * @param mNx100 - matriz com número máximo de colunas definido por MAXCOLS100.
 * @param lines - número de linhas da matriz.
 * @param columns - número de colunas da matriz (<MAXCOLS100).
 */
void read_matrixNx100_ints(int mNx100[][MAXCOLS100], int lines, int columns); // Ler/armazenar ints na matriz

/**
 * Função de inicialização/leitura de matriz de strings, cujo número columns < MAXCOLS100.
 * @param mNx100 - matriz com número máximo de colunas definido por MAXCOLS100.
 * @param lines - número de linhas da matriz.
 * @param columns - número de colunas da matriz (<MAXCOLS100).
 */
void read_matrixNx100_strings(char mNx100[][MAXCOLS100], int lines, int columns); // Ler/armazenar frases com fgets()

/**
 * Função para multiplicar uma linha de uma matriz por um dado número escalar.
 * @param mNx100 - matriz com número máximo de colunas definido por MAXCOLS100.
 * @param lines - número de linhas da matriz.
 * @param columns - número de colunas da matriz (<MAXCOLS100).
 * @param line - linha a multiplicar pelo escalar.
 * @param scalar - número pelo qual multiplicar a linha.
 */
void multiply_matrixNx100_line_by_scalar(int mNx100[][MAXCOLS100], int lines, int columns, int line, int scalar);

/**
 * Função que some os elementos das linhas lin1 e lin2 de uma matriz, colocando o resultado na lin3.
 * @param mNx100 - matriz com número máximo de colunas definido por MAXCOLS100.
 * @param lin1 - 1a linha da matriz a somar.
 * @param lin2 - 2a linha da matriz a somar.
 * @param lin3 - linha onde colocar o resultado da somas das linhas lin1 e lin2.
 */
void sum_lines_matrixesNx100(int mNx100[][MAXCOLS100], int lin1, int lin2, int lin3, int columns);

/** Função que calcula a transposta de uma matriz.
 * @param mNx100 - matriz com número máximo de colunas definido por MAXCOLS100.
 * @param size - número de linhas/colunas da matriz.
 */
void transposed_matrixNx100(int mNx100[][MAXCOLS100], int size);

/**
 * Main test function for TP class 05.
 * @param argc - arg count.
 * @param argv - array os strings.
 * @return an error code (0 if no error).
 */
int main_tp04(int argc, const char * argv[]);

#endif /* tp04_h */
