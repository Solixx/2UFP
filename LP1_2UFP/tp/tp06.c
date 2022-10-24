//
// Created by manue on 24/10/2022.
//

#include "tp06.h"

int main_tp06(int argc, const char * argv[]){

    const char *str[] = {"254", "123", "534", "123"};
    int v[] = {};
    int sizev = 0;

    //print_arraystrs(argc, argv);
    //printf("%p\n", convert_str2int_arraystrs(2, str, v));
    printf("%p\n", remove_repeated_ints(4, str, v, &sizev));

    return 0;
}

void print_arraystrs(int size, const char *astr[]){

    for (int i = 0; i < size; ++i) {
        printf("%s\n", *(astr+i));
    }
}

int* convert_str2int_arraystrs(int size, const char *astr[], int v[]){

    char *endptr;

    for (int i = 0; i < size; ++i) {
        v[i] = strtol(*(astr+i), &endptr, 10);
        //printf("%d\n", v[i]);
    }

    return v;
}

int exists_before(int v[], int i){
    for (int j = 0; j < i; j++) {
        if(v[i] == v[j]){
            return j;
        }
    }
    return -1;
}

int* remove_repeated_ints(int c, const char *astr[], int v[], int *psizev){

    *psizev = c;

    convert_str2int_arraystrs(c, astr, v);

    for (int i = 0; i < *psizev; ++i) {
        if(exists_before(v,i) != -1){
            printf("%d\n", v[i]);
            for (int j = i; j < *psizev; j++) {
                v[j] = v[j+1];
            }
            *(psizev)--;
        }
    }

    printf("%d\n", *psizev);
    return v;
}