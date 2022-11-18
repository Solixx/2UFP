//
// Created by manue on 18/11/2022.
//

#include "aed1_06.h"

void main_pr_aed1_06(){

    //client0_aed06();
    //client1_aed06();
    //client2_aed06();
    client3_aed06(); //TODO knuthShuffle esta mal
}

void client0_aed06(){

    int a[5] = {1,2,4,6,2};
    int N = 5;

    selectionSort(a, N);
    printArray(a, N);
    if(estaordenado(a, N, 0) == 1){
        printf("Esta Ordenado\n");
    } else{
        printf("Nao Esta Ordenado\n");
    }
}

void client1_aed06(){

    int inversoes = 0;
    int N[4] = {10000, 20000, 40000, 80000};
    for (int i = 0; i < 4; ++i) {
        int *a = newIntArray(N[i]);
        readInts("../data/8Kints.txt", a, N[i]);

        LARGE_INTEGER ticks1, ticks2;
        long long startTime, endTime;

        QueryPerformanceCounter(&ticks1);
        insertionSort(a, N[i]);
        //printArray(a, N[i]);
        if(estaordenado(a, N[i], 1) == 1){
            printf("Esta Ordenado\n");
        } else{
            printf("Nao Esta Ordenado\n");
        }
        inversoes = contarInversoes(a, N[i]);
        printf("Inversoes - %d\n", inversoes);
        QueryPerformanceCounter(&ticks2);
        printf("Array Size = %d, Time = %lld\n", N[i], ticks2.QuadPart-ticks1.QuadPart);
    }
}

void client2_aed06(){

    int a[7] = {230, 110, 5, 54, 12, 1003, 23};
    int N = 7;

    shellSort(a, N);
    printArray(a, N);
    if(estaordenado(a, N, 1) == 1){
        printf("Esta Ordenado\n");
    } else{
        printf("Nao Esta Ordenado\n");
    }
}

void client3_aed06(){

    int N[5] = {10000, 20000, 40000, 80000, 160000};
    LARGE_INTEGER ticks1, ticks2;
    long long startTime, endTime;

    for (int i = 0; i < 5; ++i) {
        int *a = newIntArray(N[i]);
        QueryPerformanceCounter(&ticks1);

        knuthShuffle(a, N[i]); //Desordenar um array
        //printArray(a, N);
        QueryPerformanceCounter(&ticks2);
        printf("Array Size = %d, Time = %lld\n", N[i], ticks2.QuadPart-ticks1.QuadPart);
    }
}

void selectionSort(int a[], int N){

    for (int i = 0; i < N; ++i) {
        int min = i;
        for (int j = i+1; j < N; ++j) {
            if(a[j] < a[min]){ //Para ordenar descendente é mudar de "<" para ">"
                min = j;
            }
        }
        swap(a, i, min);
    }
}

void insertionSort(int a[], int N){
    for (int i = 0; i < N; ++i) {
        for (int j = i; j > 0; j--) {
            if(a[j] < a[j-1]){  //Para ordenar descendente é mudar de "<" para ">"
                swap(a, j, j-1);
            } else break;
        }
    }
}

void shellSort(int a[], int N){
    int h = 1;
    while (h < N/3){
        h = 3*h + 1;
    }
    while (h >= 1){
        for (int i = 0; i < N; ++i) {
            for (int j = i; j >= h && a[j] < a[j-h]; j -= h) {  //Para ordenar descendente é mudar de "<" para ">"
                swap(a, j, j-h);
            }
        }
        h /= 3;
    }
}

void knuthShuffle(int *a, int N){
    for (int i = 0; i < N; ++i) {
        a[i] = i+1;
    }
    knuth_shuffle(a, N);
}

int estaordenado(int a[], int N, int flag){
    // flag = 1 -> ordenado ascendente, flag = 0 -> ordenado descendente
    if(flag == 1){
        for (int i = 0; i < N-1; ++i) {
            if(a[i] > a[i+1]){
                return 0;
            }
        }
        return 1;
    } else{
        for (int i = 0; i < N-1; ++i) {
            if(a[i] < a[i+1]){
                return 0;
            }
        }
        return 1;
    }
}

void swap(int a[], int i, int min){

    int temp = a[min];
    a[min] = a[i];
    a[i] = temp;
}

int contarInversoes(int a[], int N){
    int inversoes = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            if(a[i] > a[j]){
                inversoes++;
            }
        }
    }
    return inversoes;
}