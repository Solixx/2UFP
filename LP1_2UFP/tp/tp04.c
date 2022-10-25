//
// Created by manue on 10/10/2022.
//

#include "tp04.h"

int main_tp04(int argc, const char * argv[]){

    char str[] = "boas  ad ter fwtau ter p";
    char sub[] = "ter";
    char matrixChar[][MAXCOLS100] = {};
    int matrix[][MAXCOLS100] = {{1,2},{4,5}};
    int matrix2[][MAXCOLS100] = {};

    //printf("%d", index_first_vogal(str));
    //printf("%s", replace_char_by_char(str, 'o', 'a'));
    //printf("%s", remove_blanks(str));
    //printf("%d", index_sub_left(str, sub));
    //printf("%d", index_sub_right(str, sub));
    //printf("%s", remove_sub(str, sub));
    //print_matrixNx100_ints(matrix, 2, 3);
    //read_matrixNx100_ints(matrix2, 2, 3);
    //read_matrixNx100_strings(matrixChar, 2, 3);
    //multiply_matrixNx100_line_by_scalar(matrix, 2, 3, 1, 10);
    //sum_lines_matrixesNx100(matrix, 0, 1, 2, 3);
    transposed_matrixNx100(matrix, 2);

    return 0;
}

int index_first_vogal(char str[]){

    int n = strlen(str);

    for (int i = 0; i < n; ++i) {

        if(is_vowel(str[i])){

            return i;
        }
    }

    return 0;
}

char* replace_char_by_char(char str[], char o, char r){

    int n = strlen(str);

    for (int i = 0; i < n; ++i) {

        if(str[i] == 'o'){

            str[i] = 'a';
        }
    }

    return str;
}

char* remove_blanks(char str[]){

    int n = strlen(str);

    for (int i = 0; i < n; ++i) {
        if(str[i] == ' '){
            for (int j = i; j < n; ++j) {
                str[j] = str[j+1];
            }
            n--;
            i--;
        }
    }

    return str;
}

int index_sub_left(char str[], char sub[]){

    int n = strlen(str), m = strlen(sub);
    int j = 0;

    for (int i = 0; i < n; ++i) {
        if(str[i] == sub[j]){
            j++;
        }else{
            j = 0;
        }
        if(j == m){
            return i - (m-1);
        }
    }

    return 0;
}

int index_sub_right(char str[], char sub[]){

    int n = strlen(str), m = strlen(sub);
    int j = 0, last;

    for (int i = 0; i < n; ++i) {
        if(str[i] == sub[j]){
            j++;
        }else{
            j = 0;
        }
        if(j == m){
            last = i;
        }
    }

    return last;
}

char* remove_sub(char str[], char sub[]){

    int n = strlen(str), m = strlen(sub);
    int j = 0;

    for (int i = 0; i < n; ++i) {
        if(str[i] == sub[j]){
            j++;
        }else{
            j = 0;
        }
        if(j == m){
            for (int k = i; k >= i-(m-1); k--) {
                str[k] = str[k+1];
            }
            n--;
            i--;
        }
    }

    return str;
}

void print_matrixNx100_ints(int mNx100[][MAXCOLS100], int lines, int columns){

    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("%d", mNx100[i][j]);
        }
        printf("\n");
    }
}

void read_matrixNx100_ints(int mNx100[][MAXCOLS100], int lines, int columns){

    int n = 0;

    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("Insira os valores da matrix\n");
            scanf(" %d", &n);
            mNx100[i][j] = n;
        }
    }

    /*
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("%d", mNx100[i][j]);
        }
        printf("\n");
    }
     */
}

void read_matrixNx100_strings(char mNx100[][MAXCOLS100], int lines, int columns){

    FILE *fp;
    char str[100], *c;

    fp = fopen("../data/words_matrix.txt" , "r");

    if(fp == NULL) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("Insira as frases para armazenar na matrix\n");
            c = fgets(str, 100, stdin);
            printf("%s\n", c);
            mNx100[i][j] = c[i];
            printf("%c\n", mNx100[i][j]);
        }
    }

    /*
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("%c\n", mNx100[i][j]);
        }
    }
     */
}

void multiply_matrixNx100_line_by_scalar(int mNx100[][MAXCOLS100], int lines, int columns, int line, int scalar){

    for (int i = 0; i < columns; ++i) {
        mNx100[line][i] *= scalar;
    }


    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("%d\n", mNx100[i][j]);
        }
    }

}

void sum_lines_matrixesNx100(int mNx100[][MAXCOLS100], int lin1, int lin2, int lin3, int columns){

    for (int i = 0; i < columns; ++i) {
        mNx100[lin3][i] = mNx100[lin1][i] + mNx100[lin2][i];
    }


    for (int j = 0; j < columns; ++j) {
        printf("%d\n", mNx100[lin3][j]);
    }

}

void transposed_matrixNx100(int mNx100[][MAXCOLS100], int size){

    int trans[size][size];

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            trans[j][i] = mNx100[i][j];
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d", trans[i][j]);
        }
        printf("\n");
    }
}