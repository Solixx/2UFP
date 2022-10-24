//
// Created by manue on 30/09/2022.
//

#include "pr02.h"

int main_pr02(int argc, const char* argv[]){

    //read_digits_to_int();
    //print_numbers_classes_from_units_upper(253);
    //print_numbers_classes_from_higher_downward(254);
    //print_numbers_classes_from_higher_downward_recursive(254);
    //multiplication_as_sums(2, 5);
    //print_multiplication_table(5);
    //print_pyramid(11);
    //is_number_triangular(3);
    splits_in_half(123);

    return 0;
}

int read_digits_to_int(void){
    char c=' ';
    int acumulador=0;
    int resto=0;
    printf("Insira um numero\n");
    while(!isalpha(c)){
        scanf(" %c",&c);
        if(isdigit(c)){
            resto=c-'0';
            acumulador=(acumulador*10)+resto;
        }
    }
    printf("output: %d\n",acumulador);
    return acumulador;
}

void print_numbers_classes_from_units_upper(int n){

    int digit;
    while (n != 0){

        digit = n%10;
        printf("%d,", digit);
        n /= 10;
    }
}

void print_numbers_classes_from_higher_downward(int n){

    int digit = 0, reverse = 0;

    while (n != 0){

        digit = n%10;
        reverse = reverse * 10 + digit;
        n /= 10;
    }
    while (reverse != 0){

        digit = reverse%10;
        reverse /= 10;
        printf("%d,", digit);
    }
}

void print_numbers_classes_from_higher_downward_recursive(int n){

    int r;

    if (n == 0) {
        return;
    }

    r = n % 10;

    print_numbers_classes_from_higher_downward_recursive(n / 10);

    printf("%d, ", r);
}

int multiplication_as_sums(int a, int b){

    int sum = 0;
    for (int i = 0; i < b; ++i) {

        sum = sum + a;
    }

    printf("%d", sum);
    return a;
}

void print_multiplication_table(int num){

    for (int i = 1; i <= 10; ++i) {

        printf("%d\n", num*i);
    }
}

void print_pyramid (int width){

    int pir = 0, minI = 1;

    for (int i = minI; i <= width; ++i) {
        printf("%d", i);
        if(i == width){
            printf("\n");
            width = width - 1;
            minI = minI + 1;
            i = minI-1;
        }
    }
}

int is_number_triangular (unsigned int num){

    int soma = 0, i = 0;

    for (i = 0; i < num; i++) {

        soma += i;

        if(soma == num){

            printf("%d is triangular", num);
            return 0;
        }
    }

    if(i == num){

        printf("%d is not triangular", num);
        return 1;
    }
}

void splits_in_half(int n){

    int digit = 0, reverse = 0, tempn = 0, count = 0, i = 1;

    printf("Insira o numero\n");
    scanf(" %d", &n);

    tempn = n;

    while (tempn != 0){

        tempn /= 10;
        count++;
    }

    if(count % 2 != 0){

        while (n != 0){

            digit = n%10;
            reverse = reverse * 10 + digit;
            n /= 10;
        }
        while (reverse != 0){

            digit = reverse%10;
            reverse /= 10;
            if(i != (count/2)+1){

                printf("%d", digit);
            }
            else{
                printf(" e ");
            }

            i++;
        }
    }
    else{

        while (n != 0){

            digit = n%10;
            reverse = reverse * 10 + digit;
            n /= 10;
        }
        while (reverse != 0){

            digit = reverse%10;
            reverse /= 10;

            if(i == (count/2)+1){
                printf(" e ");
            }

            printf("%d", digit);
            i++;
        }
    }

    /*
    while (n != 0){

        digit = n%10;
        reverse = reverse * 10 + digit;
        n /= 10;
    }
    while (reverse != 0){

        digit = reverse%10;
        reverse /= 10;
        printf("%d,", digit);
    }
     */
}