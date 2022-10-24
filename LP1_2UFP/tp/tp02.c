//
// Created by manue on 26/09/2022.
//

#include "tp02.h"

int main_tp02(int argc, const char* argv[]){

    int n = 0;
    char c = '\0';

    //is_vowel(c);
    //is_consonant(c);
    //is_whitechar(' ');
    //read_keyspressed_printdigits();
    //prints_keytype(c);
    //read_keyspressed_print_keytype();
    count_words_stdin();
    //number_digits_iterative(n);
    //highest_even_or_odd_digits_frequency(n);
    //highest_frequency_digit(n);

    return 0;
}

int is_vowel(char c){

    //printf("Insira o carater\n");
    //scanf(" %c", &c);

    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){

        //printf("return 1");
        return 1;
    } else{

        //printf("return 0");
        return 0;
    }
}

int is_consonant(char c){

    //printf("Insira o carater\n");
    //scanf(" %c", &c);

    if(isalpha(c)){

        if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U'){

            //printf("return 1");
            return 1;
        } else{

            //printf("return 0");
            return 0;
        }
    }else{

        //printf("Nao e letra");
        return 0;
    }
}

int is_whitechar(char c){

    if(c == ' ' || c == '\t' || c == '\n' || c == '\r'){

        printf("return 1");
        return 1;
    } else{

        printf("return 0");
        return 0;
    }
}

void read_keyspressed_printdigits(void){

    char c;

    do{

        printf("Insira um carater para terminar insira um .\n");
        scanf(" %c", &c);

        if(isdigit(c)){

            printf("E digito\n");
        } else{

            printf("Nao e digito\n");
        }
    } while (c != '.');
}

void prints_keytype(char c){

    printf("Insira um carater\n");
    scanf(" %c", &c);

    if(is_vowel(c)){

        printf("Vowel");
    } else if(is_consonant(c)){

        printf("Consonant");
    } else if(isdigit(c)){

        printf("Digito");
    } else{

        printf("Especial");
    }
}

void read_keyspressed_print_keytype(void){

    char c;

    do{

        printf("Insira um carater para terminar insira um .\n");
        scanf(" %c", &c);

        if(is_vowel(c)){

            printf("Vowel\n");
        } else if(is_consonant(c)){

            printf("Consonant\n");
        } else if(isdigit(c)){

            printf("Digito\n");
        }
    } while (c != '.');
}

int count_words_stdin(void){

    int c, tempC = '\0', boll = 0;
    int words=0;
    scanf(" %c", &c);
    while (c != '\n'){

        c=getc(stdin);

        if(c == ' ' && tempC != ' '){

            words++;
        }

        if(boll == 0){

            if(isalnum(c) && tempC == ' '){

                boll = 1;
                words++;
            }
        }

        tempC = c;
    }

    if(words == 0){

        words++;
    }

    printf("Words - %d\n", words);
    return words;

    /*
    int c=getchar();
    int words=0;
    scanf("%c", words);
    while(c!='.')
    {
        if(c==' ' || c=='\n')
        {
            c=getchar();
        }
        else if(c>='a' && c<='z')
        {
            c=getchar();
            if(c==' ')
            {
                words=words+1;
                c=getchar();
            }
            else
            {
                c=getchar();
                if(c==' ')
                {
                    words=words+1;
                    c=getchar();
                }
            }
        }
    }
    printf("%d\n",words+1);
    return words+1;
     */

    /*
    char frase[100];
    int i = 0, count = 1;

    printf("Insira a sua frase\n");
    fgets(frase, sizeof frase, stdin);

    while (frase[i] != '\0'){

        if(frase[i] == ' ' && frase[i-1] != ' '){

            count++;
        }
        i++;
    }

    printf("Existem %d palavras\n", count);
    return count;
     */
}

int number_digits_iterative(int n){

    int count = 0, t[100];

    printf("Insira uma numero\n");
    scanf(" %d", &n);

    while (n != 0){

        count++;
        t[count] = n%10;
        n /= 10;
    }

    for (int i = count; i > 0; i--) {
        if(i==1){

            printf("%d", t[i]);
        } else{

            printf("%d,", t[i]);
        }
    }

    printf("\nO numero de digitos e %d\n", count);

    /*
    do{

        printf("%d", n%10);
        n /= 10;
        count++;

    } while (n != 0);


    printf("O numero de digitos e %d\n", count);
     */
    return count;
}

short highest_even_or_odd_digits_frequency(int n){

    int odd = 0, even = 0;

    printf("Insira um numero\n");
    scanf(" %d", &n);

    do {

        if(n%2 == 0){

            even++;
        } else{

            odd++;
        }

        n /= 10;

    } while (n != 0);

    if(even > odd){

        printf("Numero de pares e %d\n", even);
        return even;
    } else{

        printf("Numero de impares e %d\n", odd);
        return odd;
    }
}

short highest_frequency_digit(int n){

    int tempNum = 0, digit[100], count = 1, max = 0, i = 0;
    short freqDigit = 0;

    printf("Insira um numero\n");
    scanf(" %d", &n);

    while (n != 0){

        //printf("%d\n", n % 10);
        digit[i] = n % 10;
        n /= 10;
        i++;
    }

    for (int j = 0; j < i; ++j) {
        for (int k = j+1; k < i; ++k) {

            if(digit[j] == digit[k]){

                count++;
            }else{

                count = 1;
            }
            if(count > max){

                max = count;
                freqDigit = digit[j];
            }
        }
    }

    printf("O digito que se repete mais e o %d e repetio %d\n", freqDigit, max);
    return freqDigit;

    /*
    do {

        tempNum = n;
        n /= 10;
        digit[i] = tempNum - (n * 10);

    } while (n != 0);

    for (int j = 0; j < sizeof digit; ++j) {
        for (int k = j + 1; k < sizeof digit; ++k) {

            if(digit[j] == digit[k]){

                count++;
            }
            if(count > max){

                max = count;
                freqDigit = digit[j];
            }
        }
    }

    printf("O digito que se repete mais e %d e repetiu %d vezes\n", freqDigit, max);
    return freqDigit;

     */
}