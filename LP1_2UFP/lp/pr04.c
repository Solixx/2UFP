//
// Created by manue on 14/10/2022.
//

#include "pr04.h"

int main_pr04(int argc, const char * argv[]){

    char str[] = "Hello";
    char sub[] = "ll";
    char rep[] = "aa";

    int mC[][MAXCOLS100] = {};
    int m[][MAXCOLS100] = {{1,7},{2,4}};
    int mB[][MAXCOLS100] = {{3,3}, {5,2}};
    //int mC[][MAXCOLS100] = {}; --> Porque razao ao eu criar a matrix aqui e zerar na funcao a matrix B tambem é zerada? E se eu criar esta mesma matrix abaixo da matrix A a matrix A e q tambem é zerada?

    //printf("%s", capitalize_string(str));
    //printf("%s", delete_repeated_chars(str));
    printf("%s", shift_n(str, 2));
    //printf("%s", replace_sub2rep(str, sub, rep));
    //multiply_matrix_by_scalar(m, 3, 2, 3);
    //printf("%d", sum_diagonal_mNx100(m, 3, 3));
    //printf("%d", multiply_line_column_NxMAXCOLS100(m,mB,mC,3,1,3));
    //multiply_matrixesNxMAXCOLS100(m, mB, mC, 2, 2);

    return 0;
}

char* capitalize_string(char str[]){

    for (int i = 0; i < strlen(str); ++i) {
        if(isalpha(str[i]) && str[i-1] == ' '){

            str[i] = toupper(str[i]);
        }
        if(isalpha(str[0])){

            str[0] = toupper(str[0]);
        }
    }

    return str;
}

char* delete_repeated_chars(char s[]){

    int n = strlen(s);

    for (int i = 0; i < n; ++i) {
        if(s[i] == s[i+1]){
            for (int j = i; j < n; ++j) {
                s[j] = s[j+1];
            }
            i--;
            n--;
        }
    }

    return s;
}

char* shift_n(char s[], int n){

    int size = strlen(s), j = n;
    char temp[size];

    if(n > 0){

        for (int i = 0; i < size; ++i) {
            temp[i] = s[i];
            if(i < n){
                s[i] = s[size-j];
                j--;
            }
        }
        j=0;
        for (int i = n; i < size; ++i) {
            s[i] = temp[j];
            j++;
        }
    }
    else if(n < 0) {

        for (int i = 0; i < size; ++i) {
            temp[i] = s[i];
        }
        for (int i = 0; i < size; ++i) {
            if (i < abs(n)) {
                s[size + j] = s[i];
                j++;
            }
        }

        j = abs(n);
        for (int i = 0; i < size+n; i++) {
            s[i] = temp[j];
            j++;
        }
    }

    return s;
}

char* replace_sub2rep(char str[], char sub[], char rep[]){

    int size = strlen(str), size_sub = strlen(sub), j = 0, repetio = 0, pos = 0;

    for (int i = 0; i < size; ++i) {
        if(str[i] == sub[j]){
            j++;
        }else{
            j = 0;
        }
        if(j == size_sub){
            repetio = 1;
        }else{
            repetio = 0;
        }
        if(repetio == 1){
            i = i-(j-1);
            for (int k = i; k < i + size_sub; ++k) {
                str[k] = rep[pos];
                pos++;
            }
        }else{
            pos = 0;
        }
    }

    return str;
}

void multiply_matrix_by_scalar (int m[][MAXCOLS100], int lines, int columns, int scalar){

    printf("[");
    for (int i = 0; i < lines; ++i) {
        printf("[");
        for (int j = 0; j < columns; ++j) {
            m[i][j] *= scalar;
            if(j == columns-1){
                printf("%d", m[i][j]);
            } else{
                printf("%d, ", m[i][j]);
            }
        }
        if(i == lines-1){
            printf("]");
        } else{
            printf("], ");
        }
    }
    printf("]");
}

int sum_diagonal_mNx100(int mNx100[][MAXCOLS100], int lines, int columns){

    int sum = 0;

    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            if(i == j){
                printf("%d\n", mNx100[i][j]);
                printf("j - %d\n", j);
                sum += mNx100[i][j];
            }
        }
    }

    return sum;
}

int multiply_line_column_NxMAXCOLS100(int mA100[][MAXCOLS100], int mB100[][MAXCOLS100], int mC100[][MAXCOLS100], int lineA, int columnB, int columnsAlinesB){

    for (int i = 0; i < columnsAlinesB; ++i) {
        mC100[0][0] += mA100[lineA-1][i] + mB100[i][columnB-1];
    }

    return mC100[0][0];
}

void multiply_matrixesNxMAXCOLS100(int mA100[][MAXCOLS100], int mB100[][MAXCOLS100], int mC100[][MAXCOLS100], int linesA, int columnsB){

    // 1 7   3 3
    // 2 4   5 2

    // (1*3 + 1*3)  (7*3 + 7*3)  (2*5 + 2*2)   (4*5 + 4*2)

    if(linesA != columnsB){
        printf("Numero de linhas de A nao combina com o numero de colunas de B\n");
        return;
    }

    for (int i = 0; i < linesA; ++i) {
        for (int j = 0; j < columnsB; ++j) {
            mC100[i][j] = 0;
        }
    }

    for (int i = 0; i < linesA; ++i) {
        for (int j = 0; j < columnsB; ++j) {
            for (int k = 0; k < columnsB; ++k) {
                mC100[i][j] += (mA100[i][j] * mB100[i][k]);
            }
        }
    }

    for (int i = 0; i < linesA; ++i) {
        for (int j = 0; j < columnsB; ++j) {
            printf("%d\t", mC100[i][j]);
        }
        printf("\n");
    }
}