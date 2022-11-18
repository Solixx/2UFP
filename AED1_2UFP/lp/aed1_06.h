//
// Created by manue on 18/11/2022.
//

#ifndef AED1_06_C_AED1_06_H
#define AED1_06_C_AED1_06_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "lib_util.h"
#include "lib_stats.h"

void main_pr_aed1_06();

void client0_aed06();
void client1_aed06();
void client2_aed06();
void client3_aed06();

void selectionSort(int a[], int N);

void insertionSort(int a[], int N);

void shellSort(int a[], int N);

void knuthShuffle(int *a, int N);

void swap(int a[], int i, int min);
int estaordenado(int a[], int N, int flag);

int contarInversoes(int a[], int N);

#endif //AED1_06_C_AED1_06_H
