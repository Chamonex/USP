#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void inicializar(t_fila *f) {

    f->cont = 0;
    f->fim = NULL;
    f->inicio = NULL;

}
int inserir(int e, t_fila *f) {
    // inserir elemento no fim da fila

    t_apontador p = malloc(sizeof(t_no));

    if (p == NULL)
        return CHEIA;
    
    p->chave = e;
    f->cont++;
    p->anterior = NULL;

    if(f->inicio == NULL) { //vazia
        p->prox = NULL;
        f->fim = p;
        f->inicio = p;
        return SUCESSO;
    }

    f->fim->anterior = p;
    t_apontador aux = f->fim;
    f->fim = p;
    p->prox = aux;
    
    // printf("elemento inserido\n");
    return SUCESSO;
}


int remover(t_fila *f) {
    // remover um elemento do inicio da fila
    // retorna a chave do elemento

    if (vazia(*f) == VAZIA) {
        printf("REMOVER - fila vazia, impossivel remover!\n");
        return ERROR;
    }
    
    int chave = f->inicio->chave;

    t_apontador aux = f->inicio;
    free(f->inicio);
    f->inicio = aux->anterior;
    f->cont--;

    return chave;
}


int vazia(t_fila f) {
    if (f.cont == 0)
        return VAZIA;
    
    return SUCESSO;
}


int cheia() {

    t_apontador teste = malloc(sizeof(t_no));
    if (teste == NULL)
        return CHEIA;

    return SUCESSO;
}


int proximo(t_fila *f) {
    
    if (vazia(*f)) 
        return VAZIA;

    int chave = f->inicio->chave;
    return chave;

}


int contar(t_fila *f) {

    return f->cont;

}


int printar(t_fila *f) {
    

    t_apontador p = f->inicio;
    if (p == NULL) {
        printf("FILA VAZIA!\n");
        return ERROR;
    }

    printf("INICIO\n");

    while(p != NULL) {
        printf("  %d\n", p->chave);
        p = p->anterior;
    }
    printf("FIM\n");

    return 1;
}