//
// Created by manue on 03/10/2022.
//

#include "tp03.h"

int main_tp03(int argc, const char * argv[]){

    char t[] = "boas";
    int n[] = {3,2,1,5,6,11,2};
    int v[] = {5,  2,  2,  3,  4,  4,  4,  4,  1,  1, 2, 2};
    int p[] = {2, 2};

    int ex1 = number_digits_recursive(1234);
    double ex2 = multiply_recursive(5, 2);
    double ex3 = factorial_recursive(5);
    int ex5 = read_store_vowels(t, 4);
    int ex7 =  max(n, 7);
    int ex8 =  min(n, 7);
    float ex9 = mean(n, 7);
    int ex10 = count_segments_repeated_ints(v, 12, p, 2);

    //printf("%d", ex1);
    //printf("%f", ex2);
    //printf("%0.0f", ex3);
    //print_multable_recursive(2,0);
    //printf("%d", ex5);
    //print_vowels(t,4);
    //printf("%d", ex7);
    //printf("%d", ex8);
    //printf("%f", ex9);
    printf("%d", ex10);

    return 0;
}

int number_digits_recursive(int a){

    if(a >= 0 && a <= 9){

        return 1;
    }

    return 1 + number_digits_recursive(a/10);
}

double multiply_recursive(int a, int b){

    if(a == 1){

        return b;
    } else if(b == 1){

        return a;
    }

    if(a > b){

        return a + multiply_recursive(a, b-1);
    }
    else{

        return b + multiply_recursive(a-1, b);
    }
}

double factorial_recursive(int n){

    if(n == 1){

        return 1;
    }

    return n * factorial_recursive(n-1);

    return 0;
}

void print_multable_recursive(int n, int level){

    if(level == 0){

        printf("0");
        return;
    }

    print_multable_recursive(n, level-1);
    printf("%d x %d = %d\n", n, level, n*level);
}

int read_store_vowels(char vowels[], int size){

    int count = 0;

    if(size == 0){

        return 1;
    }

    for (int i = 0; i < size; ++i) {

        if(is_vowel(vowels[i])){

            count++;
        }
    }

    return count;
}

void print_vowels(char vowels[], int size){

    if(size == 0){

        return;
    }

    for (int i = 0; i < size; ++i) {

        if(is_vowel(vowels[i])){

            printf("%c", vowels[i]);
        }
    }
}

int max(int ints[], int size){

    int max = 0;

    for (int i = 0; i < size; ++i) {

        if(ints[i] > max){
            max = ints[i];
        }
    }

    return max;
}

int min(int ints[], int size){

    int min = ints[0];

    for (int i = 0; i < size; ++i) {

        if(ints[i] < min){

            min = ints[i];
        }
    }

    return min;
}

float mean(int ints[], int size){

    float media = 0, soma = 0;

    for (int i = 0; i < size; ++i) {
        soma += ints[i];
    }

    media = soma/size;
    return media;
}

int count_segments_repeated_ints(int v[], int sizev, int r[], int sizer){

    int count = 0, j = 0;

    for (int i = 0; i < sizev; ++i) {
        if(v[i] == r[j]){
            j++;
        }else{
            j = 0;
        }
        if(j == sizer-1){
            count++;
        }
    }

    return count;
}