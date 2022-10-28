//
// Created by pc on 28/10/2022.
//

#include "pr06.h"

int main_pr06(int argc, const char * argv[]){

    const char *frases[MAX100] = {"ola", " mundo", "!"};
    const char *strings[] = {"aa", "bbb", "ccc", "aa", "ccc", "aa"};
    const char strV[] = "aa";
    char str[MAX100];
    int freq[MAX100];

    printf("%d\n", calculator_command_line(argc, argv));
    //printf("%s\n", cat_strings(3, frases, str));
    //printf("%d\n", frequencies_strings(6, strings, freq));
    //printf("%d\n", sum_all_astr(argc, argv));
    //printf("%d\n", str_exists_before(strV, argv, 3));

    return 0;
}

int calculator_command_line(int argc, const char *argv[]){

    int result = 0;

    for (int i = 0; i < argc; ++i) {
        if(strcmp(argv[i], "plus") == 0){
            result = atoi(argv[1]) + atoi(argv[3]);
        } else if(strcmp(argv[i], "sub") == 0){
            result = atoi(argv[1]) - atoi(argv[3]);
        } else if(strcmp(argv[i], "mult") == 0){
            result = atoi(argv[1]) * atoi(argv[3]);
        } else if(strcmp(argv[i], "div") == 0){
            result = atoi(argv[1]) / atoi(argv[3]);
        }
    }

    return result;
}

char* cat_strings(int size, const char *astrs[], char str[]){

    for (int i = 0; i < size; ++i) {
        strcat(str, astrs[i]);
    }

    return str;
}

int frequencies_strings(int argc, const char *astr[], int freqs[]){

    int freqsCount = 0, freqsSize = 0;

    for (int i = 0; i < argc; ++i) {
        freqs[freqsCount] = 1;
        for (int j = i+1; j < argc; ++j) {
            if(astr[i] == astr[j]){
                freqs[freqsCount] += 1;
                astr[j] = astr[j+1];
            }
        }
        argc--;
        freqsCount++;
        freqsSize++;
    }

    for (int i = 0; i < freqsSize; ++i) {
        printf("%d\n", freqs[i]);
    }

    return freqsSize;
} //TODO so funciona para o exemplo 1

int sum_all_astr(int argc, const char *astr[]){

    int count = 0;

    for (int i = 0; i < argc; ++i) {
        count += atoi(astr[i]);
    }

    return count;
}

int str_exists_before(const char str[], const char *astr[], int line){

    for (int i = 0; i < line; i++) {
        if(strcmp(astr[i], str) == 0){
            return 1;
        }
    }
    return 0;
}