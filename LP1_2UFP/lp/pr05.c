//
// Created by manue on 21/10/2022.
//

#include "pr05.h"

int main_pr05(int argc, const char * argv[]){

    double array1[] = {1,2,3,4}, mmm[] = {0};
    double value2 = 0, value1 = 0;
    double *r1 = &value1, *r2 = &value2, *pi = &array1[0];
    int array2[] = {1,2,5,4}, maxmin[2] = {0,0}, array3[] = {1,2,5,4,1,1,2,1};
    int arraymedia[] = {24,25,26,24,25,25};
    int *p2 = &array2[0], *maxminpoint = &maxmin[0];
    char *pstr = "boas meu menino meu criminoso";
    char *psubstr = "meu";

    //calc_roots(2, -14, 20, r1, r2);
    //printf("%f\n", *swap_double_array_ptr(pi, 0, 2));
    //search_minmax(p2, 4, maxminpoint);
    //printf("Max = %d Min = %d\n", maxmin[0], maxmin[1]);
    //print_array_double_with_index(pi,4);
    //print_array_double_without_index(pi,4);
    //init_and_print_alphabet();
    //printf("%d\n", mode(array3,8));
    //bubble_sort(array3, 8);
    //printf("%f\n", median(arraymedia, 6));
    //find_mode_mean_median(arraymedia, 6, mmm);
    printf("%s\n", strstr_ptr(pstr, psubstr));

    return 0;
}

/*void calc_roots(int a, int b, int c, double* r1, double* r2){

    double sqare;
    sqare = b * b - 4 * a * c;
    if (sqare > 0) {
        *r1 = (-b + sqrt(sqare)) / (2*a);
        *r2 = (-b - sqrt(sqare)) / (2*a);
        printf("root1 = %.2lf and root2 = %.2lf", *r1,*r2);
    }

    else if (sqare == 0) {
        r1 =r2 = -b / (2 * a);
        printf("root1 = root2 = %.2lf;", *r1);
    }
}
*/

double* swap_double_array_ptr(double* pi, int pos1, int pos2){

    double temp = *(pi+pos1);

    *(pi+pos1) = *(pi+pos2);
    *(pi+pos2) = temp;

    for (int i = 0; i < 4; ++i) {
        printf("%.0f ", *(pi+i));
    }
}

int* search_minmax(int *pi, int size, int *maxmin){

    *(maxmin+1) = *(pi+0);

    for (int i = 0; i < size; ++i) {
        if(*(pi+i) > *(maxmin+0)){
            *(maxmin+0) = *(pi+i);
        }
        if(*(pi+i) < *(maxmin+1)){
            *(maxmin+1) = *(pi+i);
        }
    }
    //printf("Max = %d\n", *(maxmin+0));
    //printf("Min = %d\n", *(maxmin+1));
    return maxmin;
}

void print_array_double_with_index(double *pi, int size){

    for (int i = 0; i < size; ++i) {
        printf("%d = %f\n", i, *(pi+i));
    }
}

void print_array_double_without_index(double *pi, int size){

    for (int i = 0; i < size; ++i) {
        printf("%.0f ", *pi++);
    }
}

void init_and_print_alphabet (void){

    char *s;
    int n = 97;

    s = (char *) malloc(sizeof(char)*ALPHABET_LETTERS);
    for (int i = 0; i < ALPHABET_LETTERS; ++i) {
        if(i == 26){
            *(s+i) = '\0';
        } else{
            *(s+i) = n;
            n++;
        }
    }

    printf("%s\n", s);
}

int mode (int * a, int n){

    int count = 0, max = 0, mode = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if(*(a+i) == *(a+j)){
                count++;
            }else{
                count = 0;
            }
            if(count > max){
                max = count;
                mode = *(a+i);
            }
        }
    }

    return mode;
}

int* bubble_sort (int * a, int n){

    int temp;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if(*(a+i) > *(a+j)){
                temp = *(a+j);
                *(a+j) = *(a+i);
                *(a+i) = *(a+j);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%d\n", *(a+i));
    }
}

double median (int * a, int n){

    int i = 0;
    double mediana = 0, soma = 0;

        if(n%2 == 0){
            mediana = (*(a+((n/2)-1)) + *(a+(n/2)))/2;
        } else{
            mediana = *(a+((n/2)-1));
        }

    return mediana;
}

double* find_mode_mean_median (int *pi, int size, double *mmm){

    int count = 0, max = 0;
    double soma = 0;

    for (int i = 0; i < size; ++i) {
        soma += *(pi+i);
        for (int j = i; j < size; ++j) {
            if(*(pi+i) == *(pi+j)){
                count++;
            }else{
                count = 0;
            }
            if(count > max){
                max = count;
                *(mmm+0) = *(pi+i);
            }
        }
    }

    if(size%2 == 0){
        *(mmm+2) = (*(pi+((size/2)-1)) + *(pi+(size/2)))/2;
    } else{
        *(mmm+2) = *(pi+((size/2)-1));
    }

    *(mmm+1) = soma/size;

    printf("%f\n", *(mmm+0));
    printf("%f\n", *(mmm+1));
    printf("%f\n", *(mmm+2));
}

char* strstr_ptr(char* pstr, char * psubstr){

    int j = 0;
    char *p;

    for (int i = 0; i < strlen(pstr); ++i) {
        if(*(pstr+i) == *(psubstr+j)){
            j++;
        } else{
            j = 0;
        }
        if(j == strlen(psubstr)){
            j = i-j;
            for (int k = 0; k < strlen(pstr)- strlen(psubstr); ++k) {
                *(p+k) = *(pstr+j);
                j++;
            }
            j = 0;
            break;
        }
    }

    return p;
}