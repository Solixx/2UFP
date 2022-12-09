//
//  tp11.h
//  lp1_ufp
//
//  Created by Rui on 31/10/17.
//  Copyright © 2017 Rui. All rights reserved.
//
//  Revised:
//  * 05/12/2022: add summary for the class
//  ==========================================================================
// 7. Ficheiros
// 7.1. Entrada e saída de dados (streams)
// 7.2. Ficheiros standard (stdin, stdout, stderr)
// 7.3. Modos de abertura de ficheiros
// 7.4. Ficheiros de texto
// Leitura/escrita de arrays dinâmicos de/para ficheiros de texto.
//  ==========================================================================
#ifndef tp11_h
#define tp11_h

#include <stdio.h>
#include "tp08.h" //import RECT

// Define a dynamic array of RECTs (cf. RECT from tp10)
typedef struct dynarrayrects
{
    RECT *prects;
    int size;
} DYNARRAYRECTS;

/** Create a dynamic array of RECT with given number of available positions */
void create_dyn_array_rects(DYNARRAYRECTS *pdar, int numberOfRectangles);

/** Print a RECT */
void print_rectangle(int i, RECT r);

/** Print the content of the dynamic array of RECT */
void print_dyn_array_rects(DYNARRAYRECTS dar);

/**
 * Insert a RECT into the fisrt available position of the dynamic array:
 * @param pdar - pointer to the dynamic  array
 * @param rect - data of RECTANGLE to insert.
 */
void insert_rect_dyn_array_rects(DYNARRAYRECTS *pdar, RECT rect);

/**
 *Read data from a file containing several RECT:
 * @param pcs - pointer to dynamic array.
 */
void read_dyn_array_rects_txt(DYNARRAYRECTS *pdar, char filename[]);

/**
 * Write content of dynamic array of RECT into a text file:
 * @param cs - copy of dynamic array.
 * @param filename - path to output text file.
 */
void save_dyn_array_rects_txt(DYNARRAYRECTS dar, char filename[]);
                                                
/**
 * Test function for class tp11.
 */
int main_tp11(int argc, const char * argv[]);


#endif /* tp11_h */
