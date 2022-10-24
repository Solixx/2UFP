//
// Created by manue on 07/10/2022.
//

#include "aed1_02.h"

void main_pr_aed1_02(){
    //client1_aed02();
    client2_aed02();
}

void client1_aed02(){

    int n, *id, p, q;
    FILE *fp = fopen("../data/tinyUF.txt","r");
    fscanf(fp, "%d\n", &n);
    printf("Ficha 2 Ex 4.2 (Quick-Union)\n");
    id = newIntArray(n);
    init_UF_QU(id,n);
    while (!feof(fp)){
        fscanf(fp, "%d%d\n", &p,&q);
        printf("%d %d",p,q);
        if(connected_QU(p,q,id,n)){
            printf(" already connected!\n");
        } else{
            union_QU(p,q,id,n);
            printf(" union!\n");
        }
        printf("Id[] = ");
        printArray(id,n);
    }

    fclose(fp);
}

void init_UF_QU(int id[], int n){
    for (int i = 0; i < n; ++i) {
        id[i] = i;
    }
}

int find_QU(int p, int id[], int n){
    while (p != id[p]){
        p = id[p];
    }
    return p;
}

void union_QU(int p, int q, int id[], int n){
    int i = find_QU(p, id, n);
    int j = find_QU(q, id, n);
    id[i] = j;
}

int connected_QU(int p, int q, int id[], int n){
    return find_QU(p,id,n) == find_QU(q,id,n);
}

void client2_aed02(){
    int n, *id, p, q, *sz;
    FILE *fp = fopen("../data/ficha2_ex4.txt","r");
    fscanf(fp, "%d\n", &n);
    printf("Ficha 2 Ex 4.3 (Weighted Quick-Union)\n");
    id = newIntArray(n);
    sz = newIntArray(n);
    init_UF_WQU(id,sz,n);
    while (!feof(fp)){
        fscanf(fp, "%d%d\n", &p,&q);
        printf("%d %d",p,q);
        if(connected_WQU(p,q,id,sz,n)){
            //printf(" already connected!\n");
        } else{
            union_WQU(p,q,id,sz,n);
            //printf(" union!\n");
        }
        //printf("Id[] = ");
        //printArray(id,n);
        //printf("Sz[] = ");
        //printArray(sz,n);
    }

    fclose(fp);
    printf("\nFinal:\n id[] = ");
    printArray(id,n);
    printf("Final:\n sz[] = ");
    printArray(sz,n);
}

void init_UF_WQU(int id[], int sz[], int n){
    for (int i = 0; i < n; ++i) {
        id[i] = i;
        sz[i] = 1;
    }
}

int find_WQU(int p, int id[], int sz[], int n){
    while (p != id[p]){
        p = id[p];
    }
    return p;
}

void union_WQU(int p, int q, int id[], int sz[], int n){
    int i = find_WQU(p, id, sz, n);
    int j = find_WQU(q, id, sz, n);
    if (i == j) return;
    if (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
    else { id[j] = i; sz[i] += sz[j]; }
}

int connected_WQU(int p, int q, int id[], int sz[], int n){
    return find_QU(p,id,n) == find_QU(q,id,n);
}