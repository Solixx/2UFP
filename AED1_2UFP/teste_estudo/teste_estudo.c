//
// Created by pc on 06/11/2022.
//

#include "teste_estudo.h"

void main_pr_aed1_teste1(){
    int N = 10;
    int id[N];
    int sz[N];
    char a[] = {'d', 'a', 'c', 'f', 'f', 'b', 'd', 'b', 'f', 'b', 'e', 'a'};
    char *str[] = {"dba", "add", "cab", "fad", "fee", "bad", "dad", "bee", "fed", "bed", "ebb", "ace"};
    char *pat = "ABCABBCC";
    char *txt = "ABC";
    int aN = 12;
    int W = 3;
    int strN = 12;

    // QuickFind
    /*
    QuickFind(id, N);
    unionQF(id, 2, 3, N);
    printArrayUnion(id, N);
     */

    // QuickUnion
    /*
    QuickUnion(id, N);
    unionQU(id, 2, 3, N);
    printArrayUnion(id, N);
     */

    // Weighted QuickUnion
    /*
    WeightedQuickUnion(id, N, sz);
    unionWQU(id, 2, 3, N, sz);
    unionWQU(id, 5, 8, N, sz);
    unionWQU(id, 2, 5, N, sz);
    printArrayUnion(id, N);
     */

    // Path Compression
    /*
    PathCompression(id, N, sz);
    unionPC(id,2,3, N, sz);
    printArrayUnion(id, N);
     */

    // Key-Indexed Counting
    /*
    keyIndexed(a, aN);
    printArrayStringChar(a, aN);
     */

    // LSD
    /*
    LSD(str, W, strN);
    printArrayStringArray(str, strN);
     */

    // MSD
    /*
    MSD(str, 0, strN-1, 0);
    printArrayStringArray(str, strN);
     */

    // Brute Force
    printf("%d\n", bruteForce(pat, txt));
}

// Funcoes Unions
/*
void printArrayUnion(int id[], int N){
    for (int i = 0; i < N; ++i) {
        printf("%d ", id[i]);
    }
}

void QuickFind(int id[], int N){
    for (int i = 0; i < N; ++i) {
        id[i] = i;
    }
}

int findQF(int id[], int p){
    return id[p];
}

void unionQF(int id[], int p, int q, int N){
    int pid = findQF(id, p);
    int qid = findQF(id,q);
    for (int i = 0; i < N; ++i) {
        if(id[i] == pid){
            id[i] = qid;
        }
    }
}

void QuickUnion(int id[], int N){
    for (int i = 0; i < N; ++i) {
        id[i] = i;
    }
}

int findQU(int id[], int p){
    while (p != id[p]){
        p = id[p];
    }
    return p;
}

void unionQU(int id[], int p, int q, int N){
    int i = findQU(id, p);
    int j = findQU(id, q);
    id[i] = j;
}

void WeightedQuickUnion(int id[], int N, int sz[]){
    for (int i = 0; i < N; ++i) {
        id[i] = i;
        sz[i] = 1;
    }
}

int findWQU(int id[], int p){
    while (p != id[p]){
        p = id[p];
    }
    return p;
}

void unionWQU(int id[], int p, int q, int N, int sz[]){
    int i = findWQU(id, p);
    int j = findWQU(id, q);
    if(i == j) return;
    if(sz[i] < sz[j]){
        id[i] = j;
        sz[j] += sz[i];
    } else{
        id[j] = i;
        sz[i] += sz[j];
    }
}

void PathCompression(int id[], int N, int sz[]){
    for (int i = 0; i < N; ++i) {
        id[i] = i;
        sz[i] = 1;
    }
}

int findPC(int id[], int p){
    while (p != id[p]){
        id[p] = id[id[p]];
        p = id[p];
    }
    return p;
}

void unionPC(int id[], int p, int q, int N, int sz[]){
    int i = findPC(id, p);
    int j = findPC(id, q);
    if(i == j) return;
    if(sz[i] < sz[j]){
        id[i] = j;
        sz[j] += sz[i];
    } else{
        id[j] = i;
        sz[i] += sz[j];
    }
}
*/

// Funcoes Strings
/*
void printArrayStringChar(char a[], int N){
    for (int i = 0; i < N; ++i) {
        printf("%c ", a[i]);
    }
}

void printArrayStringArray(char *a[], int N){
    for (int i = 0; i < N; ++i) {
        printf("%s ", a[i]);
    }
}

void keyIndexed(char a[], int N){

    int R = 256;
    int count[R+1];
    char aux[N];

    for (int i = 0; i < R+1; ++i) {
        count[i] = 0;
    }
    for (int i = 0; i < N; ++i) {
        count[a[i]+1]++;
    }
    for (int r = 0; r < R; ++r) {
        count[r+1] += count[r];
    }
    for (int i = 0; i < N; ++i) {
        aux[count[a[i]]++] = a[i];
    }
    for (int i = 0; i < N; ++i) {
        a[i] = aux[i];
    }
}

void LSD(char *a[], int W, int N){

    int R = 256;
    int count[R+1];
    char *aux[N];

    for (int d = W-1; d >= 0; d--) {
        for (int i = 0; i < R+1; ++i) {
            count[i] = 0;
        }
        for (int i = 0; i < N; ++i) {
            count[a[i][d]+1]++;
        }
        for (int r = 0; r < R; ++r) {
            count[r+1] += count[r];
        }
        for (int i = 0; i < N; ++i) {
            aux[count[a[i][d]]++] = a[i];
        }
        for (int i = 0; i < N; ++i) {
            a[i] = aux[i];
        }
    }
}

void MSD(char *a[], int lo, int hi, int d){

    int R = 256;
    int count[R+2];
    char *aux[hi+1];

    if(hi <= lo) return;
    for (int i = 0; i < R+2; ++i) {
        count[i] = 0;
    }
    for (int i = lo; i <= hi; ++i) {
        count[a[i][d]+2]++;
    }
    for (int r = 0; r < R+1; ++r) {
        count[r+1] += count[r];
    }
    for (int i = lo; i <= hi; ++i) {
        aux[count[a[i][d]+1]++] = a[i];
    }
    for (int i = lo; i <= hi; ++i) {
        a[i] = aux[i-lo];
    }
    for (int r = 0; r < R; ++r) {
        MSD(a, lo + count[r], lo + count[r+1] - 1, d+1);
    }
}
*/

// Funcoes StringSearch

int bruteForce(char *pat, char *txt){
    int M = strlen(pat);
    int N = strlen(txt);
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++) {
            if(txt[i+j] != pat[j]){
                break;
            }
        }
        if(j == M) return i;
    }
    return N;
}