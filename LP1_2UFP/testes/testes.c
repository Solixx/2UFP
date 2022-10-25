//
// Created by manue on 25/10/2022.
//

#include "testes.h"

void ex1();

int main_testes(int argc, const char * argv[]){

    int a1[] = {1,2,3}, a3[4] = {1,2,3,5};
    int *p1 = &a1[0], *p2;
    char string[] = "string";

    //printf("%llu\n", sizeof string);

    ex1();

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
    char temp[] = "";

    for (int i = 0; i < strlen(str); ++i) {
        if(str[i] != ' '){
            temp[i] = str[i];
        } else{
            temp[i] = '\0';
            printf("%s\n", temp);
        }
        if(strcmp(temp, 'dois')){
            printf("jnzbdkjwabkjfdbwal\n");
        }
    }
}