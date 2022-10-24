//
// Created by manue on 07/10/2022.
//

#include "pr03.h"

int main_pr03(int argc, const char * argv[]){

    int a[] = {1,2,2,2,3,4,4}, b[] = {1,2,3,4,5};
    int size = 7, n = 4;

    //printf("%d", pow_recursive(2, 5));
    //print_hangman_iterative(6);
    //print_hangman_recursive(6);
    //printf("%d", int_compare(a,b,size));
    //printf("%d", lowest_index_number(a,n,size));
    //printf("%d", highest_index_number(a,n,size));
    //printf("%d", number_highest_frequency(a, size));
    //printf("%d", size_greatest_segment_repeated_ints(a,size));
    printf("%d", count_clumps(a, size));

    return 0;
}

int pow_recursive(int b, int e){

    if(e == 1){

        return b;
    }
    else if(e == 0){

        return 1;
    }

    return b * pow_recursive(b, e-1);
}

void print_hangman_iterative(int level){

    if(level == 0){

        return;
    }

    for (int i = 1; i <= level; ++i) {
        switch (i) {
            case 1:
                printf(" \\");
                break;
            case 2:
                printf("0");
                break;
            case 3:
                printf("/");
                break;
            case 4:
                printf("\n /");
                break;
            case 5:
                printf("\\");
                break;
            case 6:
                printf("\n/");
                break;
            default:
                break;
        }
    }
}

void print_hangman_recursive(int level){

    if(level == 0){

        return;
    }

    print_hangman_recursive(level-1);

    switch (level) {
        case 1:
            printf(" 0");
            break;
        case 2:
            printf("\n/");
            break;
        case 3:
            printf("/");
            break;
        case 4:
            printf("\\");
            break;
        case 5:
            printf("\n/ ");
            break;
        case 6:
            printf("\\");
            break;
        default:
            break;
    }
}

int int_compare(int a[], int b[], int size){

    for (int i = 0; i < size; ++i) {

        if(a[i] < b[i]){
            return -1;
        }
        else if(a[i] > b[i]){
            return 1;
        }
    }

    return 0;
}

int lowest_index_number(int v[], int n, int size){

    for (int i = 0; i < size; ++i) {

        if(v[i] == n){

            return i;
        }
    }

    return 0;
}

int highest_index_number(int v[], int n, int size){

    for (int i = size; i > 0; i--) {

        if(v[i] == n){
            return i;
        }
    }

    return 0;
}

int number_highest_frequency(int v[], int size){

    int max = 0, count = 0, number;

    for (int i = 0; i < size; ++i) {

        for (int j = i+1; j < size; ++j) {

            if(v[i] == v[j]){

                count++;
                if(count > max){

                    max = count;
                    number = v[i];
                }
            }
            else{
                count = 0;
            }
        }
    }

    return number;
}

int size_greatest_segment_repeated_ints(int v[], int size){

    int count = 0, max = 1;

    for (int i = 0; i < size; i++) {

        if(v[i] == v[i+1]){

            count++;
            if(count > max){

                max = count;
            }
        }
        else{
            count = 1;
        }
    }

    return max;
}

int count_clumps (int a[], int size){

    int count = 0, repeat = 0;

    for (int i = 0; i < size; ++i) {

        if(a[i] == a[i+1]){

            if(repeat == 0){

                count++;
                repeat = 1;
            }
        }
        else{
            repeat = 0;
        }
    }

    return count;
}
