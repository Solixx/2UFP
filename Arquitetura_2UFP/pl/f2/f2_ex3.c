//
// Created by manue on 04/10/2022.
//

#include "f2_ex3.h"

int main_pr01(int argc, const char *argv[]){

    int n = 0;

    f2_ex3(n);

    return 0;
}

int f2_ex3(int n){

    int i = 0, soma = 0;

    printf("Insira o valor\n");
    scanf("%d", &n);

    while (i < n){

        i++;

        soma += i;
    }

    printf("Soma -> %d\n", soma);
    return soma;
}