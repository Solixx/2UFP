//
// Created by manue on 21/10/2022.
//

#ifndef AED_AED1_04_H
#define AED_AED1_04_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib_util.h"
#include "lib_stats.h"

#define R 3
#define M 5
#define FIRST_ALPHABET_SYMBOL0 'A'

void main_pr_aed1_04();

void printDFA(int dfa[R][M]);

void KMP(char pat[], int dfa[R][M]);

int search_KMP(char txt[], int dfa[R][M]);

void cliente0_aed04();

void cliente1_aed04();

#endif //AED_AED1_04_H
