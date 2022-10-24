//
// Created by manue on 19/09/2022.
//


#include "pr01.h"

int main_pr01(int argc, const char* argv[]) {

    int a = 0, b = 0;

    //print_ascii_for_char('c');
    //divide_two_ints_into_float(a, b);
    //read_date_and_gender();
    //print_ascii_table_letters();
    //is_digit('c');
    //is_digit_v2('c');
    //read_key_print_digit_or_notdigit();
    //parse_inputstream_count_chartypes();
    //read_input_stream_count_given_char('c');
    //find_longest_sequence_repeated_chars_from_inputstream();
    find_longest_word_inputstream();

    return 0;
}

void print_ascii_for_char(char c){

    printf("Insira o carater\n");
    scanf(" %c", &c);

    printf("%d", c);
}

float divide_two_ints_into_float(int a, int b){

    float result = 0, c, d;

    printf("Insira os 2 valores\n");
    scanf(" %d %d", &a, &b);

    c= a;
    d= b;

    result = c/d;

    printf("%0.2f", result);
    return result;
}

void read_date_and_gender(void){


}

void print_ascii_table_letters(void){

    int numberChar = 65;
    char caraterChar = numberChar;

    for (int i = 0; i < 122; ++i) {

        if(caraterChar >= 'a' && caraterChar <= 'z' || caraterChar >= 'A' && caraterChar <= 'Z'){

            printf("%c \t %d\n", numberChar, numberChar);
        }

        numberChar++;
        caraterChar = numberChar;
    }
}

int is_digit(char c){

    printf("Insira o carater\n");
    scanf(" %c", &c);

    if(isdigit(c)){

        return 1;
    }
    else{

        return 0;
    }
}

int is_digit_v2(char c){

    printf("Insira o carater\n");
    scanf(" %c", &c);

    if(isdigit(c)){

        printf("Digito");
        return 1;
    }
    else{

        printf("Nao Digito");
        return 0;
    }
}

void read_key_print_digit_or_notdigit(void){

    char c;

    do{

        printf("Insira o carater\n");
        scanf(" %c", &c);

        if(isdigit(c)){

            printf("Digito\n");
        }
        else{

            printf("Nao Digito\n");
        }

    } while (c != 'e' && c != 'E');
}

void parse_inputstream_count_chartypes(void){

    char frase[100];
    int alf = 0, num = 0, esp = 0, i = 0;

    printf("Escreva a sua frase\n");
    fgets(frase, sizeof frase, stdin);

    while (frase[i] != '\0'){

        if(isalpha(frase[i])){

            alf++;
        }
        else if(isdigit(frase[i])){

            num++;
        }
        else{

            esp++;
        }

        i++;
    }

    printf("Chars = %d, Digits = %d, White spaces and Special characters = %d", alf, num, esp-1);


}

int read_input_stream_count_given_char(char charToCount){

    char frase[100];
    int count = 0;

    printf("Escreva uma frase\n");
    fgets(frase, sizeof frase, stdin);

    printf("Insira o carater para contar\n");
    scanf(" %c", &charToCount);

    for (int i = 0; i < sizeof frase; ++i) {

        if(frase[i] == charToCount){

            count++;
        }
    }

    printf("%d", count);
    return count;
}

void find_longest_sequence_repeated_chars_from_inputstream (void){

    char frase[100], repeatChar;
    int max=0, count=1, i=0;

    printf("Insira a frase\n");
    fgets(frase, sizeof frase, stdin);

    while (frase[i] != '\0'){

        printf("%c\n", frase[i]);
        if(frase[i-1] == frase[i]){

            count++;
        }
        else{

            count = 1;
        }

        if(count > max){

            repeatChar = frase[i];
            max = count;
        }

        i++;
    }

    printf("O carater %c repetio %d vezes", repeatChar, max);
}

void find_longest_word_inputstream (void){

    char frase[100];
    int count = 0, max = 0, i = 0;

    printf("Insira a frase\n");
    fgets(frase, sizeof frase, stdin);

    while (frase[i] != '\0'){

        if(frase[i] != ' '){

            printf("%c\n", frase[i]);
            count++;
        } else{

            count = 0;
        }

        if(frase[i+1] == '\0'){
            count--;
        }

        if(count > max){

            max = count;
        }

        i++;
    }

    printf("A palavra com mais caraters tem %d carateres\n", max);
}