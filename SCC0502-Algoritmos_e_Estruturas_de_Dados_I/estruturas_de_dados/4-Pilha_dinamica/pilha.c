#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// typedef struct {
// 	int e;
// 	int *prox;
// } t_no;

// typedef struct {
// 	t_no *topo;		// cabeça
// 	int cont;
// } t_pilha;


void inicializar(t_pilha *p) {

    p->cont = 0;
    p->topo = NULL;

}


int push(t_elemento e, t_pilha *p) {
    
    // insere novo nó
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


int pop(t_pilha *p) {

    if (vazia(*p) == VAZIA) {
        printf("A pilha esta vazia!\n");
        return ERROR;
    }

    t_apontador aux;
    aux = p->topo->prox;

    free(p->topo);

    p->topo = aux;

    return SUCESSO;

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



int topo(t_pilha *p) {

    if (vazia(*p) == VAZIA) {
        printf("vazia, nao tem topo!\n");
        return VAZIA;
    }

    return p->topo->e.chave;

}


int contar(t_pilha *p) {

    return p->cont;

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

