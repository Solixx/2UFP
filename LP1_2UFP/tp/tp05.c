//
// Created by manue on 17/10/2022.
//

#include "tp05.h"

int main_tp05(int argc, const char * argv[]){

    int a[] = {1,2,3,4,5};
    int x = 2;
    int *p = &x;
    int *pi = a;
    char str[] = "boas meu puto meu";
    char sub[] = "meu";
    char frase1[] = "fjna kkms";
    char frase2[] = "bhwkabhfk";
    char *t = str;
    char *r = sub;

    //double_x(2);
    //double_px(p);
    //printf("%p\n", double_array_ints_ptr(pi, 5));
    //print_array_ints_ptr(pi,5);
    //printf("%s", del_substr(t, r));
    //printf("%s", del_allsubstr(t, r));
    printf("%s", strcat_ptr1(frase1, frase2));

    return 0;
}

void double_x(int x){

    x *= 2;
    printf("%d\n", x);
}

void double_px(int *px){

    *px *= 2;
    printf("%d\n", *px);
}

int* double_array_ints_ptr(int* pi, int size){

    for (int i = 0; i < size; ++i) {
        printf("*(pi+i) = %d -> ", *(pi+i));
        *(pi+i) *= 2;
        printf("%d\n", *(pi+i));
    }

    return pi;
}

void print_array_ints_ptr(int* pi, int size){

    for (int i = 0; i < size; ++i) {
        printf("%d\n", *(pi++));
    }
}

char* del_substr(char *pstr, char *psub){

    int j=0;
    int n = strlen(pstr), m = strlen(psub);

    for (int i = 0; i < n; ++i) {
        if(*(pstr+i) == *(psub+j)){
            j++;
        } else{
            j=0;
        }
        if(j == m){

            //i -= j-1;
            for (int k = i; k >= i-(m-1); k--) {
                *(pstr+k) = *((pstr+k)+1);
            }
            i--;
            n--;
            return pstr;
        }
    }
}

char* del_allsubstr(char *pstr, char *psub){

    int j=0;
    int n = strlen(pstr), m = strlen(psub);

    for (int i = 0; i < n; ++i) {
        if(*(pstr+i) == *(psub+j)){
            j++;
        } else{
            j=0;
        }
        if(j == m){
            for (int k = i; k >= i-(m-1); k--) {
                *(pstr+k) = *((pstr+k)+1);
            }
            i--;
        }
    }

    return pstr;
}

char* strcat_ptr1(char *pdest, char *porg){

    int i=0, size = strlen(pdest);

    while (*(pdest+i) != '\0'){

        *(pdest+size+i) = *(porg+i);

        i++;
    }

    *(pdest+size+i) = '\0';

    return pdest;
}

char* strcat_ptr2(char *pdest, char *porg){

    int i=0, size = strlen(pdest);

    for (i = 0; i < size; ++i) {

        *(pdest+size+i) = *(porg+i);
    }

    *(pdest+size+i) = '\0';

    return pdest;
}