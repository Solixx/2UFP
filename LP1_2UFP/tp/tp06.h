//
//  tp06.h
//  lp1_ufp
//
//  Created by Rui on 31/10/17.
//  Copyright © 2017 Rui. All rights reserved.
//
//  Revised:
//  * 15/10/2021: add summary for the class
//  ==========================================================================
//  4. Apontadores
//  4.3. Apontadores e vectores (Arrays)
//  4.4. Passagem de vectores para funções
//  4.5. Passagem de parâmetros por referência
//  Manipulação de strings e arrays de strings;
//  Passagem de parâmetros para o processo via argc/argv.
//  ==========================================================================

#ifndef tp06_h
#define tp06_h


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tp03.h"
#define MAX128 128


/**
 * Desenvolver uma função para imprimir valores/conteúdo de argc e argv
 * @param size - tamanho do array de strings
 * @param astr - array de apontadores para strings
 */
void print_arraystrs(int size, const char *astr[]);

/**
 * Desenvolver função que recebe strings de ints via argv e converte para array ints:
 *  e.g. {"18", "222", "929"} -> {18, 222, 929}
 * @param size - tamanho do array de strings
 * @param astr - array de apontadores para strings
 * @param v - array onde colocar os ints convertidos das strings
 * @return endereço do array de ints
 */
int* convert_str2int_arraystrs(int size, const char *astr[], int v[]);

/**
 *  Desenvolver função que recebe array strings com ints, converte-os para array ints e depois
 *  elimina ints repetidos e retorna array:
 *  e.g. {"18", "222", "929", "222", "929", "222"} -> {18, 222, 929}
 *  @param c - numero de strings passadas em astr
 *  @param astr - array de strings contendo dgitos de ints
 *  @param v - array onde colocar os ints convertidos do array de strings astr
 *  @param psizev - tamanho do array ints v
 *  @return endereço do array de ints recebido em v
 */
int* remove_repeated_ints(int c, const char *astr[], int v[], int *psizev);

/**
 *  Desenvolver função que recebe array ints e apaga o elemento na posição i, movendo todos os
 *  elementos, a partir de i, uma posiçã para trás.
 *  e.g. Dado {18, 222, 929, 222, 929, 222}, remover elemento posição 3 => {18, 222, 929, 929, 222}
 *  @param v - endereço de um array de ints
 *  @param i - posição do elemento que queremos eliminar
 *  @return endereço do array de ints recebido em v
 */
int* move_vector_content_oneback(int v[], int i, int *psize);

/**
 *  Desenvolver função que recebe array ints e verifica se o elemento na posição i já existe em algumas
 *  das posições anteriores a i. Devolve a posição onde esse elemento existe repetido ou -1 se não existir.
 *  e.g. Dado {18, 222, 929, 222, 929, 222} e i=3 => devolve 1 (o elemento 3 existe reetido na posição 1)
 *  @param v - endereço de um array de ints
 *  @param i - posição do elemento que queremos verificar se existe repetido antes da posição i
 *  @return posição do elemento repetido ou -1 se não existir repetido.
 */
int exists_before(int v[], int i);

/**
 * Desenvolver função que recebe array de strings contendo numeros inteiros e
 * retorna um vector com o maior e menor:
 *  e.g. {"18", "222", "929", "222", "929", "222"} -> {929, 18}
 *  @param c - numero de strings passadas em astr
 *  @param astr - array de strings contendo dgitos de ints
 *  @param maxmin - array onde colocar o max e min dos elementos recbidos em astr
 *  @return endereço do array de ints recebido em v
 */
int* get_arrayint_maxmin(int c, const char *astr[], int maxmin[]);

/**
 * Desenvolver  função que recebe um array de strings astr e invoca várias funções para:
 * i) Usar 2 matrizes 2D de chars, a primeira para armazenar uma copia de todas as strings astr e
 * a segunda para armazenar apenas as consoantes dessas strings;
 * ii) ordenar de forma crescente as strings e respectivas consoantes, em função
 * do número de consoantes;
 * iii) imprimir as strings e respectivo numero de consoantes.
 * e.g. {"um", "quatro", "nove"} => um (1 consoante), nove (2 consoantes), quatro (3 consoantes)
 *  @param c - numero de strings passadas em astr
 *  @param astr - array de strings contendo palavras
 *  @param strings - matriz contendo cópia das strings de astr
 *  @param consonants - matriz contendo uma cópia das strings de astr mas só com as consoantes dessas strings
 */
void count_consonants(int c, const char *astr[], char strings[][MAX128], char consonants[][MAX128]);

/**
 * Desenvolver uma função que recebe um array de strings e imprime apenas as
 * que não se repetem, e.g., dadas as strings abaixo
 * char *mstrs[] = { ""aa"", ""bbb"", ""ccc"", ""aa"", ""ccc"", ""ddd"" }; 
 * imprime apenas "bbb" e "ddd"
 *  @param astr - array de strings contendo palavras
 *  @param size - tamanho do array de strings astr
 */
 void print_non_repeated_strs(const char *astr[], int size);


int main_tp06(int argc, const char * argv[]);


#endif /* tp06_h */
