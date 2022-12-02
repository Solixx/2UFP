//
// Created by manue on 02/12/2022.
//

#ifndef AED1_06_C_AED1_08_H
#define AED1_06_C_AED1_08_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "lib_util.h"
#include "lib_stats.h"
#include "aed1_06.h"
#include "aed1_07.h"

void main_pr_aed1_08();

void client0_aed08();

void client1_aed08();

void client2_aed08();

int quickSort_partition(int a[], int lo, int hi);

void quickSort_base(int a[], int N);

void quickSort_sort(int a[], int lo, int hi);

void quickSort_base_CUTOFF(int a[], int N);

void quickSort_sort_CUTOFF(int a[], int lo, int hi);

void quickSort_base_media(int a[], int N);

void quickSort_sort_media(int a[], int lo, int hi);

int media(int a[], int lo, int mid, int hi);

#endif //AED1_06_C_AED1_08_H
