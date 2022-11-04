//
// Created by manue on 04/11/2022.
//

#include "aed1_06.h"


void main_pr_aed1_06(){
    char t[] = {'2','2','2'};
    int k = 4;

    //printf("%d\n", bipolar_number(t));
    print_bipolar_numbers(k);
}

int bipolar_number(char *text){

    int bipolar = 0, changes = 0, exits = 0;
    int number, pow, digits = 0;
    char *str = &text[0];

    for (int i = 0; i < 3; ++i) {
        if(text[i] != text[i+1]){
            changes++;
        }
    }
    changes--;
    if(changes == 1){
        for (int i = 0; i < 3; ++i) {
            *(str+i) = text[i];
            if(text[i] == text[i+1]){
                bipolar = 1;
            }
        }
        number = atoi(str);
        return number;
    }
    else{
        return -1;
    }
}

void print_bipolar_numbers(int k){

    char n[] = {};
    char num = '1', changeNum = '0';
    int changePos = 3, j = 0;

    for (int i = 0; i < k; ++i) {
        n[i] = num;
        printf("%c", n[i]);
    }

    printf("\nt - %c \n", changePos);
    while (j != k){
        n[3] = '0';
        printf("%c", n[j]);
        j++;
    }
}