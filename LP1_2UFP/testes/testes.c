//
// Created by manue on 25/10/2022.
//

#include "testes.h"

void ex1();
int ex2();

int main_testes(int argc, const char * argv[]){

    int a1[] = {1,2,3}, a3[4] = {1,2,3,5};
    int *p1 = &a1[0], *p2;

    char string[] = "string";
    char lin3[] = "141\n";
    int vi[] = {1,0};
    int mx[4][5];

    //ex1();
    printf("%d\n", ex2(vi, lin3+1));

    /*
    p2=p1;
    printf("%p\n", p2);
    printf("%p\n", p1);
     */

    /*
    p1=a1;
    printf("%p\n", p1);
    p1=&a1[0];
    printf("%p\n", p1);
     */

    return 0;
}

void ex1(){

    char str[] = "dois dois cinco zero sete um tres zero";
    char output[] = "\0";
    int size = strlen(str), i = 0;
    char *temp = strtok(str, " ");

    while (temp != NULL){
        if(strcmp(temp, "zero") == 0){
            output[i] = '0';
        }
        else if(strcmp(temp, "um") == 0){
            output[i] = '1';
        }
        else if(strcmp(temp, "dois") == 0){
            output[i] = '2';
        }
        else if(strcmp(temp, "tres") == 0){
            output[i] = '3';
        }
        else if(strcmp(temp, "quatro") == 0){
            output[i] = '4';
        }
        else if(strcmp(temp, "cinco") == 0){
            output[i] = '5';
        }
        else if(strcmp(temp, "seis") == 0){
            output[i] = '6';
        }
        else if(strcmp(temp, "sete") == 0){
            output[i] = '7';
        }
        else if(strcmp(temp, "oito") == 0){
            output[i] = '8';
        }
        else if(strcmp(temp, "nove") == 0){
            output[i] = '9';
        }
        temp = strtok(NULL, " ");
        i++;
    }

    if(i%2 == 0){
        for (int j = 0; j < i; ++j) {
            printf("%c", output[j]);
            if(j%2 != 0){
                printf(" ");
            }
        }
    } else{
        printf("Insira um numero de numeros par\n");
    }
}

int ex2(int vi[], char lin3[]){
    lin3[1] += 2;

    printf("foo(): %i\n", vi[0]++);
    //printf("%s\n", lin3);

    return ++vi[0];
}