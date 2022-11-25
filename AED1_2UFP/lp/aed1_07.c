//
// Created by manue on 25/11/2022.
//

#include "aed1_07.h"

void main_pr_aed1_07(){

    //client0_aed07();
    client1_aed07();
}

void client0_aed07(){
    int a1[] = {2,6,3,9,1,8};
    int N1 = 6;
    printf("Antes de Ordenar: ");
    printArray(a1, N1);
    merge_sort_base(a1, N1);
    printf("Depois de Ordenar: ");
    printArray(a1, N1);
}

void client1_aed07(){
    int N[5] = {10000, 20000, 40000, 80000, 160000};
    LARGE_INTEGER ticks1, ticks2;
    long long startTime, endTime;

    for (int i = 0; i < 5; ++i) {
        int *a = newIntArray(N[i]);
        QueryPerformanceCounter(&ticks1);

        merge_sort_base(a, N[i]);
        //printArray(a, N);
        QueryPerformanceCounter(&ticks2);
        printf("Array Size = %d, Time = %lld\n", N[i], ticks2.QuadPart-ticks1.QuadPart);
        estaordenado(a, N[i], 1) ? printf("Ordenado!\n") : printf("Desordenado\n");
        free(a);
    }
}

void merge_sort_base(int a[], int N){
    int *aux = newIntArray(N);
    //merge_sort_recursive_basic(a, aux, 0, N-1);
    merge_sort_recursive_cutoff(a, aux, 0, N-1);
}

void merge(int a[], int aux[], int lo, int mid, int hi){
    for (int k = lo; k <= hi; ++k) {
        aux[k] = a[k];
    }
    int i = lo, j = mid+1;
    for (int k = lo; k <= hi; ++k) {
        if      (i > mid)          a[k] = aux[j++];
        else if (j > hi)           a[k] = aux[i++];
        else if (aux[j] < aux[i])  a[k] = aux[j++];
        else                       a[k] = aux[i++];
    }
}

void merge_sort_recursive_basic(int a[], int aux[], int lo, int hi){

    if(hi <= lo) return;
    int mid = lo + (hi-lo)/2;
    merge_sort_recursive_basic(a, aux, lo, mid);
    //printf("lo-%d, mid-%d\t", lo, mid);
    //printArray(&a[lo], mid-lo+1);
    merge_sort_recursive_basic(a, aux, mid+1, hi);
    //printf("mid+1-%d, hi-%d\t", mid+1, hi);
    //printArray(&a[mid+1], hi-(mid+1)+1);
    merge(a, aux, lo, mid, hi);
    //printf("lo-%d, hi-%d\t", lo, hi);
    //printArray(&a[lo], hi-lo+1);
}

void merge_sort_recursive_cutoff(int a[], int aux[], int lo, int hi){

    if (hi <= lo + CUTOFF - 1)
    {
        insertionSort(&a[lo], hi-lo+1);
        return;
    }
    int mid = lo + (hi-lo)/2;
    merge_sort_recursive_basic(a, aux, lo, mid);
    //printf("lo-%d, mid-%d\t", lo, mid);
    //printArray(&a[lo], mid-lo+1);
    merge_sort_recursive_basic(a, aux, mid+1, hi);
    //printf("mid+1-%d, hi-%d\t", mid+1, hi);
    //printArray(&a[mid+1], hi-(mid+1)+1);
    merge(a, aux, lo, mid, hi);
    //printf("lo-%d, hi-%d\t", lo, hi);
    //printArray(&a[lo], hi-lo+1);
}