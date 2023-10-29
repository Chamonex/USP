#include <stdio.h>
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


int push(int e, t_pilha *p) {
    
    // insere novo nó

    t_no *n;
    n->e = e;

    if (cheia(*p) == CHEIA) {
        printf("PUSH -- pilha (memoria) esta cheia!");
        return CHEIA;
    }

    p->cont++;

    t_no *aux;
    
    aux = p->topo;
    p->topo = n;
    n->prox = aux;

    return SUCESSO;

}


int pop(t_pilha *p) {

    if (vazia(*p) == VAZIA) {
        printf("A pilha esta vazia!\n");
        return VAZIA;
    }

    p->cont--;

    int e = p->topo->e;

    t_no *aux;
    aux = p->topo;
    free(p->topo);

    p->topo = aux->prox;
    
    return e;

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

    return p->topo;

}


int contar(t_pilha *p) {

    return p->cont;

}

