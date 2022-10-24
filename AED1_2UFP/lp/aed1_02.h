//
// Created by manue on 07/10/2022.
//

#ifndef AED_AED1_02_H
#define AED_AED1_02_H

#include <stdio.h>
#include <stdlib.h>
#include "lib_util.h"
#include "lib_stats.h"

//union-find QU impl
void client1_aed02();

void init_UF_QU(int id[], int n);

int find_QU(int p, int id[], int n);

void union_QU(int p, int q, int id[], int n);

int connected_QU(int p, int q, int id[], int n);

//Union-find WQU impl
void client2_aed02();

void init_UF_WQU(int id[], int sz[], int n);

int find_WQU(int p, int id[], int sz[], int n);

void union_WQU(int p, int q, int id[], int sz[], int n);

int connected_WQU(int p, int q, int id[], int sz[], int n);

void main_pr_aed1_02();

#endif //AED_AED1_02_H
