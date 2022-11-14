//
//  tp08.h
//  lp1_ufp
//
//  Created by Rui on 31/10/17.
//  Copyright © 2017 Rui. All rights reserved.
//
//  Revised:
//  * 15/10/2021: add summary for the class
//  ==========================================================================
// 5. Estruturas de dados
// 5.1. Declaração de estruturas de dados (struct)
// 5.2. Declaração e inicialização de variáveis do tipo struct
// 5.3. Declaração de tipos de estruturas (typedef)
// 5.4. Operadores sobre estruturas
// 5.5. Passagem de estruturas como parâmetros de funções
// 5.6. Alocação/libertação dinâmica de memória com structs
// Definição e manipulação de estruturas.
//  ==========================================================================

#ifndef tp08_h
#define tp08_h

#include <stdio.h>
#include <stdlib.h>

/**
 * Declare a new structure to represent Cartesian points in 2D spaces.
 *  e.g. struct pt  p1 = {1.0f, 1.0f};
 * NB 1: on pr09.h an equivalent structure is created but named struct point.
 * NB 2: instead of defining a structure it also possible to declare a new type PT with:
 *  typedef struct { int x, y; } PT;
 */
struct pt { float x, y; };
//typedef struct { float x, y; } PT;


/**
 * Declare a new data type to represent rectangles (contains two fields: down and up points).
 *  e.g. RECT r1 = { {0.0f, 0.0f}, {1.0f, 1.0f} }
 */
typedef struct rect { struct pt downpt, uppt; } RECT;

/**
 * Compare to points in space (equal if both have the same coordinates).
 * @param pt1 - one point in space.
 * @param pt2 - another point in space.
 * @return 1 (true) or 0 (false).
 */
int compare_pts(struct pt pt1, struct pt pt2);

/**
 * Compare two rectangles in a 2D space (are equal if both have the same points).
 * @param r1 - one rectangle in space.
 * @param r2 - another rectangle in space.
 * @return 1 (true) or 0 (false).
 */
int compare_rects(RECT r1, RECT r2);

/**
 * Allocate heap memory for storing the coordinates of a point.
 * @return address to allocated point memory.
 */
struct pt* create_pt(struct pt p);

/**
 * Allocate heap memory for storing a rectangle in space.
 * @return address to allocated rectangle memory.
 */
struct rect* create_rect(RECT r);

/**
 * Use scanf to read the coordinates of a point and store them into memory pointed by pp.
 * @param pp - pointer to a point.
 */
void read_pt(struct pt* pp);
struct pt read_pt_v2(void);


/**
 * Use scanf to read the coordinates of points of a rectangle and store them into memory pointed by pr.
 * @param pr - pointer to a rectangle.
 */
void read_rect(RECT* pr);
RECT read_rect_v2(void);


/**
 * Print the coordinates of a point with a given label.
 * @param pt_label - string containing the label of the point to print.
 * @param p - point to print.
 */
void print_pt(char pt_label[], struct pt p);

/**
 * Print the coordinates of the points of a rectangle.
 * @param rect_label - string containing the label of the rectangle to print.
 * @param r -  rectangle to print.
 */
void print_rect_v1(char rect_label[], RECT r);

/**
 * Print the coordinates of the points of a rectangle pointed by pr.
 * @param rect_label - string containing the label of the rectangle to print.
 * @param pr - pointer to rectangle to print.
 */
void print_rect_v2(char rect_label[], const RECT *pr);

int main_tp08(int argc, const char * argv[]);


#endif /* tp08_h */
