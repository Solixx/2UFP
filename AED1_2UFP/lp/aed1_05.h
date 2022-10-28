//
// Created by manue on 28/10/2022.
//

#ifndef AED1_2UFP_AED1_05_H
#define AED1_2UFP_AED1_05_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct No{
    int item;
    struct No * next;
};

struct Fila_ll{
    struct No * head; //first element of linked list
    struct No * tail; //last element of linked list
    int size;
};

void cliente0_aed05();

void print_queue_ll(struct Fila_ll *q);
void enqueue_ll(int item, struct Fila_ll *q);
int dequeue_ll(struct Fila_ll *q);
void initqueue(struct Fila_ll * q);

#define C 10
struct PilhaInts_ArrayFixo{
    int s[C];
    int N;
};

void cliente1_aed05();

void printStack_IntFixo(struct PilhaInts_ArrayFixo * s);
void push_IntFixo(int item, struct PilhaInts_ArrayFixo * s);
int pop_IntFixo(struct PilhaInts_ArrayFixo * s);
int isEmpty_IntFixo(struct PilhaInts_ArrayFixo * s);

void main_pr_aed1_05();

#endif //AED1_2UFP_AED1_05_H
