//
// Created by manue on 24/10/2022.
//

#include "tp06.h"

int main_tp06(int argc, const char * argv[]){

    const char *str[] = {"254", "123", "534", "123"};
    const char *frases[] = {"um", "quatro", "nove"};
    const char *strRep[] = {"aa", "bbb", "ccc", "aa", "ccc", "ddd"};
    char strings[][MAX128] = {""};
    char consonants[][MAX128] = {""};
    int v[MAX128] = {};
    int sizev = 0;
    int maxmin[MAX128] = {};

    //print_arraystrs(argc, argv);
    //printf("%p\n", convert_str2int_arraystrs(2, str, v));
    //printf("%p\n", remove_repeated_ints(4, str, v, &sizev));
    //printf("%p\n", get_arrayint_maxmin(4,str,maxmin));
    //count_consonants(3, frases, strings, consonants);
    print_non_repeated_strs(strRep, 6);

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

int* remove_repeated_ints(int c, const char *astr[], int v[], int *psizev){

    *psizev = c;

    convert_str2int_arraystrs(c, astr, v);

    for (int i = 0; i < *psizev; ++i) {
        if(exists_before(v,i) != -1){
            move_vector_content_oneback(v,i, psizev);
            /*
            for (int j = i; j < *psizev; j++) {
                v[j] = v[j+1];
            }
            *(psizev) -= 1;
            i--;
             */
        }
    }

    for (int i = 0; i < *psizev; ++i) {
        printf("%d\n", v[i]);
    }

    //printf("%d\n", *psizev);
    return v;
}

int* move_vector_content_oneback(int v[], int i, int *psize){
    for (int j = i; j < *psize; j++) {
        v[j] = v[j+1];
    }
    *(psize) -= 1;
    i--;
}

int exists_before(int v[], int i){
    for (int j = 0; j < i; j++) {
        if(v[i] == v[j]){
            return j;
        }
    }
    return -1;
}

int* get_arrayint_maxmin(int c, const char *astr[], int maxmin[]){

    int v[MAX128] = {};
    int vSize = c;

    convert_str2int_arraystrs(c,astr,v);

    maxmin[0] = 0;
    maxmin[1] = v[0];

    for (int i = 0; i < vSize; ++i) {
        if(v[i] > maxmin[0]){
            maxmin[0] = v[i];
        } else if (v[i] < maxmin[0]){
            maxmin[1] = v[i];
        }
    }

    for (int i = 0; i < 2; ++i) {
        printf("%d\n", maxmin[i]);
    }

    return maxmin;
}

void count_consonants(int c, const char *astr[], char strings[][MAX128], char consonants[][MAX128]){

    int j = 0;
    char count[] = {48}, t='0';

    for (int i = 0; i < c; ++i) {
        strcpy(strings[i], astr[i]);
        while (astr[i][j] != '\0'){
            if(isalpha(astr[i][j])){
                if(is_consonant(astr[i][j])){
                    printf("%c\n", count[i]);
                    t += '1';
                    count[i] = t;
                    strcpy(consonants[i], strings[i]);
                }
            }
            j++;
        }
        t='0';
        j=0;
    }

    for (int i = 0; i < c; ++i) {
        printf("%s\n", consonants[i]);
    }
}

void print_non_repeated_strs(const char *astr[], int size){

    int j = 0, find = 0;

    for (int i = 0; i < size; ++i) {
        for (int k = i+1; k < size; ++k) {
            if(astr[i] == astr[k]){
                astr[k] = astr[k+1];
                find = 1;
            }
        }
        if(find == 1){
            size--;
            i--;
            find=0;
        }
    }

    for (int i = 0; i < size+1; ++i) {
        printf("%s\n", astr[i]);
    }
}