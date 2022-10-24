//
// Created by manue on 19/09/2022.
//

#include "tp01.h"

int main_tp01(int argc, const char* argv[]) {

    char c = '\0';
    short n = 0;

    //printPrimitiveDataTypesSizeLimits();
    factorial_iterative_overflow(n);
    //checkIfLetter(c);
    //guessSecreteChar();

    return 0;
}

void printPrimitiveDataTypesSizeLimits(void){

    int bytes=0, bites=0;
    double limit=0.0, limit2=0.0;
    bytes=sizeof(char);
    bites=bytes*8;
    limit=pow(2,bites-1);
    printf("Signed char: bytes %d \t bites %d \t min %g \t max %g \t \n",bytes,bites,-1*limit,limit-1);
    printf("Unsigned char: bytes %d \t bites %d \t min 0 \t max %g \t \n",bytes,bites,limit*2);

    bytes = sizeof(short);
    bites=bytes*8;
    limit=pow(2,bites-1);
    printf("Sign short: bytes %d \t bites %d \t min %g \t max %g \t \n", bytes,bites,-1*limit,limit-1);
    printf("Unsign short: bytes %d \t bites %d \t min 0 \t max %d \t \n", bytes,bites, USHRT_MAX);

    bytes = sizeof(int);
    bites=bytes*8;
    limit=pow(2,bites-1);
    printf("Sign int: bytes %d \t bites %d \t min %d \t max %d \t \n", bytes,bites,INT_MIN,INT_MAX);
    printf("Unsign int: bytes %d \t bites %d \t min %d \t max %u \t \n", bytes,bites,0, UINT_MAX);

    bytes = sizeof(float);
    bites=bytes*8;
    limit=pow(2,bites-1);
    printf("Sign float: bytes %d \t bites %d \t min %g \t max %g \t \n", bytes,bites,FLT_MIN,FLT_MAX);
    //printf("Unsign float: bytes %d \t bites %d \t min %g \t max %g \t \n", bytes,bites,-FLT_MIN,-FLT_MAX);

    bytes = sizeof(double);
    bites=bytes*8;
    limit=pow(2,bites-1);
    printf("Sign double: bytes %d \t bites %d \t min %g \t max %g \t \n", bytes,bites,DBL_MIN,DBL_MAX);
    //printf("Unsign double: bytes %d \t bites %d \t min %g \t max %g \t \n", bytes,bites,0,-DBL_MAX);

    bytes = sizeof(long);
    bites=bytes*8;
    limit=pow(2,bites-1);
    printf("Sign long: bytes %d \t bites %d \t min %ld \t max %ld \t \n", bytes,bites,LONG_MIN,LONG_MAX);
    printf("Unsign long: bytes %d \t bites %d \t min 0 \t max %lu \t \n", bytes,bites,ULONG_MAX);
}

int checkIfLetter(char c){

    printf("Insira um carater\n");
    scanf(" %c", &c);

    if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'){

        return 1;
    }
    else{

        return 0;
    }
}

long factorial_iterative_overflow(short n){

    int fatorial = 0;

    printf("Insira um numero\n");
    scanf(" %hd", &n);

    fatorial = n;

    if(n != 0){

        for (int i = n-1; i > 0; --i) {

            fatorial = fatorial * i;
        }
    }
    else{

        fatorial = 1;
    }


    printf("%d", fatorial);
    return fatorial;
}

void guessSecreteChar(){

    char secretChar, choiceChar;
    int possivelChar = -1, counter = 1;

    do{

        printf("Player 1: Insira o carater secreto\n");
        scanf(" %c",&secretChar);

        if(secretChar >= 'a' && secretChar <= 'z' || secretChar >= 'A' && secretChar <= 'Z'){
            possivelChar = 0;

            do{

                printf("O carater secreto e: ");
                scanf(" %c", &choiceChar);

                if(choiceChar == secretChar){

                    printf("Acertou depois de %d tentativas", counter);
                }else{

                    counter++;
                }
            } while (choiceChar != secretChar);
        }else{

            possivelChar = -1;

            printf("Insira um carater entre a e z\n");
        }
    } while (possivelChar == -1);

}