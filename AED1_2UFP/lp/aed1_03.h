//
// Created by manue on 14/10/2022.
//

#ifndef AED_AED1_03_H
#define AED_AED1_03_H

#include <stdio.h>
#include <stdlib.h>
#include "lib_util.h"
#include "lib_stats.h"

void lsd_sort(char *a[], char *aux[], int N, int W); // *a[] -> pq é um array de strings ou **a

void print_string_list(char **a, int N, int printid_flag);

void msd_sort(char *a[], char *aux[], int lo, int hi, int d);

int charPos(char *a, int d);

void cliente1_aed03();

void cliente2_aed03();

void cliente3_aed04();

void main_pr_aed1_03();

#endif //AED_AED1_03_H
