//
// Created by manue on 02/12/2022.
//

#include "aed1_08.h"

void main_pr_aed1_08(){

    //client0_aed08();
    //client1_aed08();
    //client2_aed08();
    client3_aed08();
}

void client0_aed08(){
    int a1[] = {2,6,3,9,1,8};
    int N1 = 6;
    printf("Antes de Ordenar: ");
    printArray(a1, N1);
    quickSort_base(a1, N1);
    printf("Depois de Ordenar: ");
    printArray(a1, N1);
}

void client1_aed08(){
    int a1[] = {2,6,3,9,1,8};
    int N1 = 6;
    printf("Antes de Ordenar: ");
    printArray(a1, N1);
    quickSort_base_CUTOFF(a1, N1);
    printf("Depois de Ordenar: ");
    printArray(a1, N1);
}

void client2_aed08(){
    int a1[] = {7,3,8,1,4,6, 9, 10};
    int N1 = 8;
    printf("Antes de Ordenar: ");
    printArray(a1, N1);
    quickSort_base_media(a1, N1);
    printf("Depois de Ordenar: ");
    printArray(a1, N1);
}

void client3_aed08(){
    int a1[] = {7,3,8,1,4,6, 9, 10};
    int N1 = 8;
    int k = 4;
    int val = 0;
    printf("Antes de Ordenar: ");
    printArray(a1, N1);
    quickSort_base_CUTOFF(a1, N1);
    val = quickSelection(a1, k, N1);
    printf("Depois de Ordenar: ");
    printArray(a1, N1);
    printf("O val e: %d\n", val);
}

int quickSort_partition(int a[], int lo, int hi){
    int i = lo, j = hi+1;
    while (1){
        while (a[++i] < a[lo]){
            if(i == hi) break;
        }
        while (a[lo] < a[--j]){
            if(j == lo) break;
        }
        if(i >= j) break;
        swap(a, i, j);
    }
    swap(a, lo, j);
    return j;
}

void quickSort_base(int a[], int N){
    knuth_shuffle(a, N);
    quickSort_sort(a, 0, N-1);
}

void quickSort_sort(int a[], int lo, int hi){
    if(hi <= lo) return;
    int j = quickSort_partition(a, lo, hi);
    quickSort_sort(a, lo, j-1);
    quickSort_sort(a, j+1, hi);
}

void quickSort_base_CUTOFF(int a[], int N){
    knuth_shuffle(a, N);
    quickSort_sort_CUTOFF(a, 0, N-1);
}

void quickSort_sort_CUTOFF(int a[], int lo, int hi){
    if (hi <= lo + CUTOFF - 1)
    {
        insertionSort(&a[lo], hi-lo+1);
        return;
    }
    int j = quickSort_partition(a, lo, hi);
    quickSort_sort(a, lo, j-1);
    quickSort_sort(a, j+1, hi);
}

void quickSort_base_media(int a[], int N){
    knuth_shuffle(a, N);
    quickSort_sort_media(a, 0, N-1);
}

void quickSort_sort_media(int a[], int lo, int hi){
    if(hi <= lo) return;
    int mediaval = media(a, lo, lo+(hi-lo)/2, hi);
    swap(a, lo, mediaval);
    int j = quickSort_partition(a, lo, hi);
    quickSort_sort(a, lo, j-1);
    quickSort_sort(a, j+1, hi);
}

int media(int a[], int lo, int mid, int hi){
    int mediaVal = 0;
    if(((hi-lo)+1)%2 == 0){
        mediaVal = (a[mid]+a[mid+1])/2;
    } else{
        mediaVal = a[mid+1];
    }
    return mediaVal;
}

int quickSelection(int a[], int k, int N){

    knuth_shuffle(a, N);
    int lo = 0, hi = N-1;

    while (hi > lo){
        int j = quickSort_partition(a, lo, hi);
        if (j < k) lo = j+1;
        else if(j > k) hi = j-1;
        else return a[k];
    }
    return a[k];
}