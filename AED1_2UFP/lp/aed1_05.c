//
// Created by manue on 28/10/2022.
//

#include "aed1_05.h"

void main_pr_aed1_05(){

    //cliente0_aed05();
    cliente1_aed05();
}

void cliente0_aed05(){

    struct Fila_ll queue1;
    //queue1 = malloc(sizeof (struct Fila));

    //Init queue
    initqueue(&queue1);
    enqueue_ll(4, &queue1);
    enqueue_ll(1, &queue1);
    enqueue_ll(3, &queue1);

    dequeue_ll(&queue1);
    enqueue_ll(8, &queue1);
    dequeue_ll(&queue1);

    print_queue_ll(&queue1);

    //free(queue1);
}

void print_queue_ll(struct Fila_ll *q){
    struct No * pNo = q->head;
    printf("(QUEUE HEAD)");
    while (pNo != NULL){
        printf("%d", pNo->item);
        pNo = pNo->next;
    }
    printf("(QUEUE TAIL)");
}

void initqueue(struct Fila_ll * q){
    //init da Fila
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

void enqueue_ll(int item, struct Fila_ll *q){
    struct No * pNo = malloc(sizeof (struct No));
    pNo->item = item;
    pNo->next = NULL;
    q->size = q->size + 1;
    if(q->tail != NULL){
        q->tail->next = pNo;
    }
    q->tail = pNo;
    if(q->head == NULL){
        q->head = q->tail;
    }
}

int dequeue_ll(struct Fila_ll *q){
    if(q->size > 0){
        int item = q->head->item;
        struct No * old_head = q->head;
        q->head = q->head->next;
        q->size = q->size - 1;
        if(q->head == NULL){
            q->tail = NULL;
        }
        free(old_head);
        return item;
    } else{
        return -1;
    }
}

void printStack_IntFixo(struct PilhaInts_ArrayFixo * s){
    printf("(base da Stack) ");
    for (int i = 0; i < s->N; ++i) {
        printf("%d ", s->s[i]);
    }
    printf("(Topo da Stack)(N=%d)\n", s->N);
}

void cliente1_aed05(){
    struct PilhaInts_ArrayFixo s1;
    s1.N = 0;
    printf("Exemplo 2: Pilha com array fixo\n");
    int ops[] = {5,10,15,-1,12,-1,18,-1,-1,-1,34,22};
    int num_ops = 12;
    for (int i = 0; i < num_ops; ++i) {
        if(ops[i] == -1){
            pop_IntFixo(&s1);
        } else{
            push_IntFixo(ops[i], &s1);
        }
        printStack_IntFixo(&s1);
    }
}

void push_IntFixo(int item, struct PilhaInts_ArrayFixo * s){
    //TODO
}

int pop_IntFixo(struct PilhaInts_ArrayFixo * s){
    //TODO
    return 0;
}

int isEmpty_IntFixo(struct PilhaInts_ArrayFixo * s){
    return 0;
}