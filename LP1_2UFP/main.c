#include <stdio.h>

#include "tp/tp01.h"
#include "tp/tp02.h"
#include "lp/pr01.h"
#include "lp/pr02.h"
#include "tp/tp03.h"
#include "lp/pr03.h"
#include "tp/tp04.h"
#include "lp/pr04.h"
#include "tp/tp05.h"
#include "lp/pr05.h"
#include "tp/tp06.h"
#include "lp/pr06.h"

#include "testes/testes.h"

int func();

int main(int argc, const char* argv[]) {
    //main_tp01(argc, argv);
    //main_tp02(argc, argv);
    //main_tp03(argc, argv);
    //main_tp04(argc, argv);
    //main_tp05(argc, argv);
    //main_tp06(argc, argv);
    //main_pr01(argc, argv);
    //main_pr02(argc, argv);
    //main_pr03(argc, argv);
    //main_pr04(argc, argv);
    //main_pr05(argc, argv);
    //main_pr06(argc, argv);

    main_testes(argc, argv);

    /*
    for (int i = 0; i < size2; ++i) { //h
        for (int j = 0; j < size; ++j) { //y / 2 / a / 4 / h / 1 / 2 / 3 / b
            if(format[j-1] == msg[i]){
                if(isalpha(format[j-1])){
                    pos = formar[j]; // 1
                }
                exit = 1;
            }
            else{
                if(isdigit(atoi(format[j]) && isdigit(atoi(format[j])){
                    pow = pos * 10; // 0 / 1 * 10 = 10 / 12 * 10 = 120
                    pos = pow + atoi(format[j]); // 0 / 10 + 2 = 12 / 120 + 3 = 123
                    if(!isdigit(format[i+1])){
                        break;
                    }
                }
                else {
                    exit = 0;
                }
            }
        }

        // 1
        if(exit == 0){
            printf("%c", msg[i]);
        } else{
            printf("%c", msg[i]+pos);
        }
    }
     */

    return 0;
}