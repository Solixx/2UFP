//
// Created by manue on 11/11/2022.
//

#include "pr07.h"

int main_pr07(int argc, const char * argv[]){

    int *pints, size = 1, newsize = 3;
    char *str = "abcd\0 0000";

    //printf("%p\n", alloc_and_setvalue_dyn_int_array(2, 1));
    //printf("%p\n", alloc_and_init_dyn_int_array(2));
    //printf("%p\n", create_or_resize_dyn_int_array(pints, size, newsize));
    printf("%s\n", create_copy_dyn_string(str));

    return 0;
}

int* alloc_and_setvalue_dyn_int_array(int n, int value){

    int *a;
    a = (int *) malloc(n*value);
    return a;
}

int* alloc_and_init_dyn_int_array(int n){

    int *a;

    a = (int *) calloc(n, sizeof (int));
    return a;
}

int* create_or_resize_dyn_int_array(int *pints, int size, int newsize){

    if(size == 0){
        pints = (int *) calloc(size, sizeof (int));
    } else{
        pints = (int *) realloc(pints, newsize * sizeof (int));
    }

    return pints;
}

char* create_copy_dyn_string(char * str){
    for (int i = 1; i <= strlen(str); ++i) {
        if(str[i] == '0'){
            str = (char *) realloc(str, i * sizeof (char));
        }
    }

    return str;
}