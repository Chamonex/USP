#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


void inicializar(t_pilha *p) {

    p->cont = 0;
    p->topo = NULL;

}


int push(int chave, t_pilha *p) {
    t_elemento e;
    e.chave = chave;
    
    if (cheia(*p) == CHEIA) {
        printf("PUSH -- pilha (memoria) esta cheia!");
        return CHEIA;
    }

    p->cont++;

    t_apontador ponteiro = malloc(sizeof(t_no));
    ponteiro->e = e;

    t_apontador aux = p->topo;
    p->topo = ponteiro;
    ponteiro->prox = aux;

    return SUCESSO;

}


int pop(int key, t_pilha *p) {

    // if (vazia(*p) == VAZIA) {
    //     return ERROR;
    // }

    if (p->topo->e.chave != key)
        return 1; //ERROR

    t_apontador aux;
    aux = p->topo->prox;
    free(p->topo);
    p->topo = aux;

    return 0; //SUCESSO
}

int cheia(t_pilha p) {

    t_apontador a = malloc(sizeof(t_no));

    if (a == NULL)
        return CHEIA;
    return SUCESSO;

}


int vazia(t_pilha p) {

    if (p.cont == 0)
        return VAZIA;
        
    return SUCESSO;

}


void imprimir(t_pilha p) {
    
    if (vazia(p) == VAZIA) {
        printf("pilha vazia, impossivel imprimir!\n");
        return;
    }

    t_apontador ponteiro = p.topo;
    printf("INICIO\n");

    while(ponteiro != NULL) {
        printf("%d\n", ponteiro->e.chave);
        ponteiro = ponteiro->prox;
    }

    printf("FIM\n");

    return;
}


// void limpar(t_pilha *p);

