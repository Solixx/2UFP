//
// Created by pc on 06/11/2022.
//

#ifndef AED1_2UFP_TESTE_ESTUDO_H
#define AED1_2UFP_TESTE_ESTUDO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>

void main_pr_aed1_teste1();
void main_pr_aed1_teste2();

void printArrayUnion(int id[], int N);

// Quick-Find
void QuickFind(int id[], int N);
int findQF(int id[], int p);
void unionQF(int id[], int p, int q, int N);

// Quick-Union
void QuickUnion(int id[], int N);
int findQU(int id[], int p);
void unionQU(int id[], int p, int q, int N);

// Weighted QuickUnion
void WeightedQuickUnion(int id[], int N, int sz[]);
int findWQU(int id[], int p);
void unionWQU(int id[], int p, int q, int N, int sz[]);

// Path Compression
void PathCompression(int id[], int N, int sz[]);
int findPC(int id[], int p);
void unionPC(int id[], int p, int q, int N, int sz[]);


void printArrayStringChar(char a[], int N);
void printArrayStringArray(char *a[], int N);

// Key-Indexed Counting
void keyIndexed(char a[], int N);

// LSD
void LSD(char *a[], int W, int N);

// MSD
void MSD(char *a[], int lo, int hi, int d);

// Brute Force
int bruteForce(char *pat, char *txt);

#endif //AED1_2UFP_TESTE_ESTUDO_H
