//
// Created by pc on 28/10/2022.
//

#include "pr06.h"

int main_pr06(int argc, const char * argv[]){

    const char *frases[MAX100] = {"ola", " mundo", "!"};
    const char *strings[] = {"aa", "bbb", "ccc", "aa", "ccc", "aa"};
    char str[MAX100];
    int freq[MAX100];

    //printf("%s\n", cat_strings(3, frases, str));
    printf("%d\n", frequencies_strings(6, strings, freq));

    return 0;
}

int calculator_command_line(int argc, const char *argv[]){ return 0;} //TODO

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
}