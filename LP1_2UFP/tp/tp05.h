//
//  tp05.h
//  lp1_ufp
//
//  Created by Rui on 24/10/17.
//  Copyright © 2017 Rui. All rights reserved.
//
//  Revised:
//  * 21/09/2020: add summary for the class
//  ==========================================================================
//  4. Apontadores
//  4.1. Declaração e inicialização de apontadores
//  4.2. Aritmética de apontadores
//  4.3. Apontadores e vectores (Arrays)
//  4.4. Passagem de vectores para funções
//  4.5. Passagem de parâmetros por referência
//  Utilização de apontadores para passagem por referência e gestão de
//  memória dinâmica.
//  ==========================================================================

#ifndef tp05_h
#define tp05_h

#include <stdio.h>
#include <string.h>

/**
 * Main test function for TP class 06.
 * @param argc - arg count.
 * @param argv - array os strings.
 * @return an error code (0 if no error).
 */
int main_tp05(int argc, const char * argv[]);


/**
 * Função simples que calculo a dobro de um parâmetro passado por valor.
 * @param x - valor que se pretende mudar para o dobro.
 */
void double_x(int x);
/**
 * Função simples que calculo a dobro de um parâmetro passado por referência.
 * @param px - apontador para uma variável que se pretende mudar para o dobro.
 */
void double_px(int *px);

/**
 * Função que calcula o dobro de cada elemento de um array.
 * Ao percorrer o array demosntrar a utilização da notação *(pd+i).
 * @param pi - apontador para o 1º elemento do array.
 * @param size - número de elementos do array.
 * @return endereço do 1º elemento do array.
 * */
int* double_array_ints_ptr(int* pi, int size); //Usar *(pd + i)

/**
 * Função que imprime o valor de cada elemento de um array.
 * Ao percorrer o array demosntrar a utilização da notação de *(p++)
 * @param pi - apontador para o 1º elemento do array.
 * @param size - número de elementos do array.
 * */
void print_array_ints_ptr(int* pi, int size);

/**
 * Função que recebe uma str e uma sub, para eliminar a primeira
 * ocorrência da sub dentro de str (mas usando apontadores).
 * @param pstr - endereço do char inicial da string.
 * @param psub - endereço do char inicial da sub-string.
 * @return endereço da string modificada.
 */
char* del_substr(char *pstr, char *psub);

/**
 * Função que recebe uma str e uma sub, para eliminar todas as
 * ocorrências de sub dentro de str (mas usando apontadores).
 * @param pstr - endereço do char inicial da string.
 * @param psub - endereço do char inicial da sub-string.
 * @return endereço da string modificada.
 */
char* del_allsubstr(char *pstr, char *psub);

/**
 * Função que concatena uma string org a outra string dest (usando notação apontador).
 * Versão usando:
 *   char *ps1= pdest + strlen(pdest), *ps2 = porg + strlen(porg);
 *   while(*ps1!='\0') { ps1++ e ps2++; }
 * @param pdest - apontador para a string destino.
 * @param porg - apontador para a string origem.
 * @return endereço da string destino.
 */
char* strcat_ptr1(char *pdest, char *porg);

/**
 * Função que concatena uma string org a outra string dest (usando notação apontador).
 * Versão usando:
 *   int i=0, size1= strlen(pdest), size2=strlen(porg);
 *   for(i=0;i<=size2;i++) {  ...  }
 * @param pdest - apontador para a string destino.
 * @param porg - apontador para a string origem.
 * @return endereço da string destino.
 */
char* strcat_ptr2(char *pdest, char *porg);


#endif /* tp05_h */
