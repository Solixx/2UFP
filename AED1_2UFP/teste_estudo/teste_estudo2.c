//
// Created by pc on 06/11/2022.
//

#include "teste_estudo.h"

void main_pr_aed1_teste2(){

    int id[10];
    int N = 10;
    int sz[10];
    char a[] = {'d','a','c','b','a'};
    char *str[] = {"dab", "add","cab","fad","fee"};
    int aN = 5;
    int strN = 5;
    int W = 3;

    /*
    QuickFind(id, N);
    unionQF(id, 3, 1, N);
    unionQF(id, 2, 3, N);
    printArrayUnion(id, N);
    */

    /*
    QuickUnion(id, N);
    unionQU(id, 2, 9, N);
    unionQU(id, 3, 4, N);
    unionQU(id, 4, 9, N);
    printArrayUnion(id, N);
    */

    /*
    WeightedQuickUnion(id, N, sz);
    unionWQU(id, 2, 1, N, sz);
    unionWQU(id, 2, 3, N, sz);
    printArrayUnion(id, N);
     */

    /*
    PathCompression(id, N, sz);
    unionPC(id, 6, 9, N, sz);
    unionPC(id, 3, 6, N, sz);
    unionPC(id, 1, 3, N, sz);
    unionPC(id, 0, 1, N, sz);
    printArrayUnion(id, N);
     */

    /*
    keyIndexed(a, aN);
    printArrayStringChar(a, aN);
     */

    /*
    LSD(str, W, strN);
    printArrayStringArray(str, strN);
     */

    MSD(str, 0, strN-1, 0);
    printArrayStringArray(str, strN);

}

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
    int qid = findQF(id, q);
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
    int pid = findQU(id, p);
    int qid = findQU(id, q);
    id[p] = qid;
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
}
void unionWQU(int id[], int p, int q, int N, int sz[]){
    int pid = findWQU(id, p);
    int qid = findWQU(id, q);
    if(sz[p] < sz[q]){
        id[p] = qid;
        sz[q] += sz[p];
    } else{
        id[q] = pid;
        sz[p] += sz[q];
    }
}

void PathCompression(int id[], int N, int sz[]){
    for (int i = 0; i < N; ++i) {
        id[i] = i;
        sz[i] = 1;
    }
}
int findPC(int id[], int p){
    while (id[p] != p){
        id[p] = id[id[p]];
        p = id[p];
    }
    return p;
}
void unionPC(int id[], int p, int q, int N, int sz[]){
    int pid = findPC(id, N);
    int qid = findPC(id, N);
    if(sz[p] < sz[q]){
        id[p] = qid;
        sz[q] += sz[p];
    } else{
        id[q] = pid;
        sz[p] += sz[q];
    }
}

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

    for (int i = 0; i < R; ++i) {
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
        for (int j = 0; j < R; ++j) {
            count[j] = 0;
        }
        for (int j = 0; j < N; ++j) {
            count[a[j][d]+1]++;
        }
        for (int r = 0; r < R; ++r) {
            count[r+1] += count[r];
        }
        for (int j = 0; j < N; ++j) {
            aux[count[a[j][d]]++] = a[j];
        }
        for (int j = 0; j < N; ++j) {
            a[j] = aux[j];
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
    for (int r = 0; r < R+1; ++r) {
        MSD(a,lo+count[r],lo+count[r+1]-1, d+1);
    }
}