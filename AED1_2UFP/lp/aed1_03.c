//
// Created by manue on 14/10/2022.
//

#include "aed1_03.h"

void main_pr_aed1_03(){
    //cliente1_aed03();
    cliente2_aed03();
}

void cliente1_aed03(){
    int N = 12, W = 3;
    char *a[] = {"dab","add","cab","fad","fee","bad","dad","bee","fed","bed","ebb","ace"};
    char *aux[12];
    printf("tabela inicial\n");
    print_string_list(a,N,1);
    printf("tabela ordenada\n");
    lsd_sort(a,aux,N,W);
    //print_string_list(a,N,1);
}

void lsd_sort(char *a[], char *aux[], int N, int W){
    int R = 256;
    for (int d = W-1; d >= 0; d--)
    {
        int *count = newIntArray(R+1);
        for (int i = 0; i < R+1; ++i) {
            count[i] = 0;
        }
        for (int i = 0; i < N; i++)
            count[a[i][d]+ 1]++;
        for (int r = 0; r < R; r++)
            count[r+1] += count[r];
        for (int i = 0; i < N; i++)
            aux[count[a[i][d]]++] = a[i];
        for (int i = 0; i < N; i++)
            a[i] = aux[i];
        freeIntArray(count);
        printf("\nCiclo (d=%d)\n",d);
        print_string_list(a,N,W);
    }
}

void print_string_list(char *a[], int N, int printid_flag){
    for (int i = 0; i < N; ++i) {
        if(printid_flag){
            printf("%d: %s\n", i, a[i]);
        } else{
            printf("%s\n", a[i]);
        }
    }
}

void cliente2_aed03(){
    int N = 14;
    char *a[] = {"she", "sells", "seashells", "by", "the", "sea",
                 "shore", "the", "shells", "she", "sells", "are", "surely", "seashells"};
    char *aux[14];

    printf("MSD sorting client\n");
    printf("Tabela Inicial\n");
    print_string_list(a,N,1);
    printf("\nTabela Ordenada\n");
    msd_sort(a,aux,0,N-1,0);
    //print_string_list(a,N,1);
}

void msd_sort(char *a[], char *aux[], int lo, int hi, int d){
    int R = 128;
    if (hi <= lo) return;
    int *count = newIntArray(R+2);
    for (int i = 0; i < R+2; ++i) {
        count[i] = 0;
    }
    for (int i = lo; i <= hi; i++)
        count[charPos(a[i], d) + 2]++;
    for (int r = 0; r < R+1; r++)
        count[r+1] += count[r];
    for (int i = lo; i <= hi; i++)
        aux[count[charPos(a[i], d) + 1]++] = a[i];
    for (int i = lo; i <= hi; i++)
        a[i] = aux[i - lo];
    printf("\nCiclo (lo=%d, hi=%d, d=%d)\n",lo, hi, d);
    print_string_list(&a[lo],hi-lo+1,1);
    for (int r = 0; r < R; r++)
        msd_sort(a, aux, lo + count[r], lo + count[r+1] - 1, d+1);
    freeIntArray(count);
}

int charPos(char *a, int d){
    if(d < strlen(a)) return a[d];
    else return -1;
}