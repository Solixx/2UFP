//
// Created by manue on 23/09/2022.
//

#include "aed1_00.h"
#include "lib_util.h"
#include "lib_stats.h"

void main_pr_aed1_00(){

    //client1_aula00();
    //client2_aula00();
    //client3_aula00();
    //client4_2_aula00();
    //client4_aula00();
    //client5_aula00();
    //f1ex_3_1();
    f1_ex14();

}

void client1_aula00(){

    int n = 20, minVal=10, maxVal=50;

    int *a = newIntArray(n); //reseta o espaço para array com n = 20
    uniformArray(a, n, minVal, maxVal);
    printArray(a, n);
    freeIntArray(a);
}

void client2_aula00(){

    int n=10;

    int *a = newIntArray(n);
    for (int i = 0; i < n; ++i) {

        a[i] = 0;
    }

    printArray(a, n);
    freeIntArray(a);
}

void client3_aula00(){

    int n=1000, maxVal, minVal;

    int *a = newIntArray(n);
    readInts("../data/1Kints.txt", a, n);

    maxVal = max_int(a,n);
    minVal = min_int(a,n);

    printArray(a, n);

    printf("Max = %d\n", maxVal);
    printf("Min = %d\n", minVal);

    freeIntArray(a);
}

void client4_2_aula00(){

    int n = 1;

    do{

        int *a = newIntArray(n);

        readInts("../data/1Kints.txt", a, n);

        sortIntArray(a, n);

        printArray(a,n);

        freeIntArray(a);

        printf("\n");

        n = n*2;
    }while(n < 1000);
}

void client4_aula00(){

    LARGE_INTEGER ticks1, ticks2;

    long long startTime, endTime;
    int minVal=-100, maxVal=100;
    int n[] = {20, 40, 80, 160};

    for (int i = 0; i < 4; ++i) {

        QueryPerformanceCounter(&ticks1);
        int *a = newIntArray(n[i]);
        uniformArray(a, n[i], minVal, maxVal);
        sortIntArray(a,n[i]);
        QueryPerformanceCounter(&ticks2);
        //printArray(a, n[i]);
        printf("Array Size = %d, Time = %lld\n", n[i], ticks2.QuadPart-ticks1.QuadPart);
        freeIntArray(a);
    }
}

void client5_aula00(){

    int n = 10;
    int *a = newIntArray(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i+1;
    }
    printArray(a,n);
    knuth_shuffle(a,n);
    printArray(a,n);
    freeIntArray(a);

}

void f1_ex3_1(){

    LARGE_INTEGER ticks1, ticks2;
    int n[] = {250, 500, 1000, 2000, 4000, 8000};
    int soma = 0;

    for (int i = 0; i < 6; ++i) {

        int *a = newIntArray(n[i]);
        readInts("../data/8Kints.txt", a, n[i]);

        QueryPerformanceCounter(&ticks1);

        //ThreeSum(a, n[i]);
        ThreeSumFast(a, n[i]);

        QueryPerformanceCounter(&ticks2);
        printf("Array Size = %d, Time = %lld\n", n[i], ticks2.QuadPart-ticks1.QuadPart);
        freeIntArray(a);
    }
}

void f1_ex14(){

    LARGE_INTEGER ticks1, ticks2;
    int n[] = {250, 500, 1000, 2000, 4000, 8000};
    int soma = 0;

    printf("Array Size\t Time\n");
    for (int i = 0; i < 6; ++i) {

        int *a = newIntArray(n[i]);
        readInts("../data/8Kints.txt", a, n[i]);

        QueryPerformanceCounter(&ticks1);

        //quadratica(a, n[i]);
        //linear(a, n [i]);
        //logaritmica(a, n[i]);
        linearitmico(a, n[i]);

        QueryPerformanceCounter(&ticks2);
        printf("%d\t\t %lld\n", n[i], ticks2.QuadPart-ticks1.QuadPart);
        freeIntArray(a);
    }
}

int ThreeSum(int a[], int n){
    int soma = 0;
    int count = 0;
    for (int j = 0; j < n; ++j) {
        for (int k = j+1; k < n; ++k) {
            for (int l = k+1; l < n; ++l) {
                soma = a[j] + a [k] + a[l];
                if(soma == 0){
                    count++;
                }
            }
        }
    }

    return count;
}

int ThreeSumFast(int a[], int n){
    int soma = 0;
    int count = 0, l = 0;

    sortIntArray(a, n);

    for (int j = 0; j < n; ++j) {
        for (int k = j+1; k < n; ++k) {
            l = binarySearch(a, n, -a[j]-a[k]);
            if(l >= 0){
                count++;
            }
        }
    }

    return count;
}

int quadratica(int a[], int n){

    int s = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            s++;
        }
    }

    return s;
}

int linear(int a[], int n){

    int s = 0;

    for (int i = 0; i < n; ++i) {
        s++;
    }
}

int logaritmica(int a[], int n){

    int s = 0;

    for (int i = 1; i < n; i *= 2) {
        s++;
    }

    return s;
}

int linearitmico(int a[], int n){

    int s = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j *= 2) {
            s++;
        }
    }

    return s;
}