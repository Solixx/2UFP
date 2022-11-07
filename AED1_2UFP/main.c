#include <stdio.h>
#include "aed1_00.h"
#include "aed1_02.h"
#include "aed1_03.h"
#include "aed1_04.h"
#include "aed1_05.h"
#include "aed1_06.h"

#include "teste_estudo/teste_estudo.h"

void msd_sort1(char * a[], char * aux[], int lo, int hi, int d);
void msd_sort2(char * a[], char * aux[], int lo, int hi, int d);

int main() {
    //main_pr_aed1_00();
    //main_pr_aed1_02();
    //main_pr_aed1_03();
    //main_pr_aed1_04();
    //main_pr_aed1_05();
    //main_pr_aed1_06();
    //main_pr_aed1_teste1();
    //main_pr_aed1_teste2();


    // Teste 171116 - Ex 3.a
    /*
    char * a[] = {"urso", "tudo", "lua", "serrim", "sal", "luar", "serra", "turco", "luanda", "sitio"};
    char * aux[10];
    int lo=0, hi= 9, d=0;

    msd_sort1(a, aux, lo, hi, d);

     // Teste 171116 - Ex 4. b
    /*
    int a[] = {4, 3, 2, 2,2,2,2,1,3,5,6,7};
    int key = 2, lo = 0, hi = 8, mid = (hi-lo)/2, temp2 = 0;

    for (int i = lo; i < hi+1; ++i) {
        for (int j = i+1; j < hi+1; ++j) {
            if(a[i] > a[j]){
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }

    while (hi > lo){
        if(a[mid] > key){
            hi = mid-1;
            mid = (hi-lo)/2;
        } else if (a[mid] < key){
            lo = mid+1;
            mid = (hi-lo)/2;
        } else{

            while (hi > lo){
                if(a[mid] > key){
                    hi = mid-1;
                    mid = (hi-lo)/2;
                } else if (a[mid] < key) {
                    lo = mid + 1;
                    mid = (hi - lo) / 2;
                } else{
                    if(a[mid] == key){
                        temp2 = mid;
                    }
                    hi = mid;
                    mid = (hi-lo)/2;
                }
            }
            printf("%d\n", temp2);

           // printf("%d\n", mid);
            //return mid;

            hi = mid;
            mid = (hi-lo)/2;
            while (a[mid] == key){
                if(a[mid] > key){
                    hi = mid-1;
                    mid = (hi-lo)/2;
                } else if (a[mid] < key) {
                    lo = mid + 1;
                    mid = (hi-lo)/2;
                } else{
                    temp2 = mid;
                }
            }

        }
    }

    printf("%d\n", temp2);
    return temp2;
    */

    // Teste 211108 - Ex 3.a
    /*
    int N = 14;
    char *a[] = {"perna", "perro", "pele", "perca", "parto", "fico", "perto", "figo",
                 "mal", "palerma", "universidade", "algoritmo", "mel", "fogo"};
    char *aux[14];
    int d = 0, lo = 0, hi = 13;

    msd_sort2(a, aux, lo, hi, d);

    return 0;
     */
}

void msd_sort1(char * a[], char * aux[], int lo, int hi, int d) {

    int Rr = 256;
    int count[258];

    if (hi <= lo) return;
    for (int r = 0; r < Rr + 2; ++r) {
        count[r] = 0;
    }
    for (int i = lo; i <= hi; ++i) {
        count[a[i][d] + 2]++;
    }
    for (int r = 0; r < Rr + 1; ++r) {
        count[r + 1] += count[r];
    }
    for (int i = lo; i <= hi; ++i) {
        aux[count[a[i][d] + 1]++] = a[i];
    }
    for (int i = lo; i <= hi; ++i) {
        a[i] = aux[i - lo];
    }
    printf("\nCiclo (lo=%d, hi=%d, d=%d)\n", lo, hi, d);
    print_string_list(&a[lo], hi - lo + 1, 1);
    for (int r = 0; r < Rr; ++r) {
        msd_sort1(a, aux, lo + count[r], lo + count[r + 1] - 1, d + 1);
    }
}

void msd_sort2(char * a[], char * aux[], int lo, int hi, int d) {

    int Rr = 256;

    int count[Rr+2];

    if(hi<=lo) return;
    for (int i = 0; i < Rr+2; ++i) {
        count[i] = 0;
    }
    for (int i = lo; i <= hi; ++i) {
        count[a[i][d]+2]++;
    }
    for (int r = 0; r < Rr; ++r) {
        count[r+1] += count[r];
    }
    for (int i = lo; i <= hi; ++i) {
        aux[count[a[i][d]+1]++] = a[i];
    }
    for (int i = lo; i <= hi; ++i) {
        a[i] = aux[i-lo];
    }
    for (int r = 0; r < Rr; ++r) {
        msd_sort2(a,aux,lo+count[r], lo+count[r+1]-1, d+1);
    }
    printf("%d, %d, %d\n", d,lo,hi);
}
