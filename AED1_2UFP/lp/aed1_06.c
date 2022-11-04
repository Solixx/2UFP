//
// Created by manue on 04/11/2022.
//

#include "aed1_06.h"


void main_pr_aed1_06(){
    char t[] = {'2','a','2','1'};
    int k = 4;

    //printf("%d\n", bipolar_number(t));
    print_bipolar_numbers(k);
}

int bipolar_number(char *text){

    int bipolar = 0, changes = 0, exits = 0;
    int number, pow, digits = 0;
    char *str = &text[0];

    for (int i = 0; i < 3; ++i) {
        if(isalpha(text[i])){
            printf("Nao pode ter letras\n");
            return -1;
        }
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

    int n[100] = {};
    int num = 1, rightNum = 0, leftNum = 1;
    int j = 0, changePos = k-1;

    /*
    for (int i = 0; i < k; ++i) {
        n[i] = leftNum;
        printf("%d", n[i]);
    }
    */

    while (n[0] != 9){
        if(changePos == 0){
            changePos = k-1;
            rightNum++;
        }
        if(leftNum == rightNum){
            rightNum++;
        }
        if(rightNum == 9 && changePos == 0){
            rightNum = 0;
            leftNum++;
        }
        if(j >= changePos){
            n[j] = rightNum;
        } else{
            n[j] = leftNum;
        }
        if(j == k){
            printf("\t");
            changePos--;
            j = 0;
        } else{
            printf("%d", n[j]);
            j++;
        }
    }
}