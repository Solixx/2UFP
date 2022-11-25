//
// Created by manue on 25/11/2022.
//

#ifndef AED1_06_C_AED1_07_H
#define AED1_06_C_AED1_07_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "lib_util.h"
#include "lib_stats.h"
#include "aed1_06.h"

#define CUTOFF 10

void main_pr_aed1_07();

void client0_aed07();
void client1_aed07();

void merge_sort_base(int a[], int N);
void merge(int a[], int aux[], int lo, int mid, int hi);
void merge_sort_recursive_basic(int a[], int aux[], int lo, int hi);
void merge_sort_recursive_cutoff(int a[], int aux[], int lo, int hi);

#endif //AED1_06_C_AED1_07_H
