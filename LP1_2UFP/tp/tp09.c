//
// Created by manue on 21/11/2022.
//

#include "tp09.h"

int main_tp09(int argc, const char * argv[]){

    STACK_NODE_POINTS snp1 = {0, NULL};
    struct pt p1 = {1.0f, 1.0f}, p2 = {2.0f, 2.0f}, p3 = {3.0f, 3.0f}, p4;

    if(is_empty_stacknodepoints_v1(&snp1)){
        printf("Stack Esta Vazia\n");
    }

    push_stack_node_points(&snp1, p1);

    if(is_empty_stacknodepoints_v1(&snp1)){
        p4 = pop_stack_node_points_copynode(&snp1);
    }
    snp1.ptop = pop_stack_node_points_refnode(&snp1);

    return 0;
}

int is_empty_stacknodepoints_v1(const STACK_NODE_POINTS* psnp){

    return psnp->nnodes == 0 && psnp->ptop == NULL;
}

void push_stack_node_points(STACK_NODE_POINTS *psnp, struct pt newpt){
    NODE_POINT *pnew = (NODE_POINT*) calloc(1, sizeof (NODE_POINT));
    pnew->info = newpt;
    pnew->pdown = psnp->ptop;
    psnp->ptop = pnew;
    psnp->nnodes++;
}

struct pt pop_stack_node_points_copynode(STACK_NODE_POINTS* psnp){
    struct pt p = {0.0f, 0.0f};
    NODE_POINT *paux = psnp->ptop;
    if(!is_empty_stacknodepoints_v1(psnp)){
        p = paux->info;
        psnp->ptop = paux->pdown;
        free(paux);
        paux = NULL;
        psnp->nnodes--;
    }

    return p;
}

NODE_POINT* pop_stack_node_points_refnode(STACK_NODE_POINTS* psnp){
    NODE_POINT *paux = psnp->ptop;
    if(!is_empty_stacknodepoints_v1(psnp)){
        psnp->ptop = paux->pdown;
        psnp->nnodes--;
    }

    return paux;
}

NODE_POINT* peep_stack_node_points_refnode(const STACK_NODE_POINTS* psnp, int top_delta){
    NODE_POINT *paux = NULL;
    if(!is_empty_stacknodepoints_v1(psnp) && top_delta < psnp->nnodes){
        paux = psnp->ptop;
        while (top_delta > 0 && paux != NULL){
            paux = paux->pdown;
            top_delta--;
        }
    }

    return paux;
}