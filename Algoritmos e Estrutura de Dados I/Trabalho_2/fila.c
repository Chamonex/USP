#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void inicializarF(t_fila *f) {

    f->cont = 0;
    f->fim = NULL;
    f->inicio = NULL;

}


int inserir(int chave, t_fila *f) {
    // inserir elemento no fim da fila
    t_elemento_f e;
    e.chave = chave;

    t_apontador_f p = malloc(sizeof(t_no_f));

    if (p == NULL)
        return CHEIA;
    
    p->e = e;
    f->cont++;
    p->anterior = NULL;

    if(f->inicio == NULL) { //vazia
        p->prox = NULL;
        f->fim = p;
        f->inicio = p;
        return SUCESSO;
    }

    f->fim->anterior = p;
    t_apontador_f aux = f->fim;
    f->fim = p;
    p->prox = aux;
    
    return SUCESSO;
}


int remover(int chave, t_fila *f) {
    // remover um elemento do inicio da fila
    // retorna a chave do elemento

    if (vaziaF(*f) == VAZIA) {
        return ERROR;
    }
    
    if (f->inicio->e.chave != chave)
        return 1;

    t_apontador_f aux = f->inicio;
    free(f->inicio);
    f->inicio = aux->anterior;
    f->cont--;

    return 0;
}


int vaziaF(t_fila f) {
    if (f.cont == 0)
        return VAZIA;
    
    return SUCESSO;
}


int cheiaF(t_fila f) {
    t_apontador_f teste = malloc(sizeof(t_no_f));
    if (teste == NULL)
        return CHEIA;

    return SUCESSO;
}


int proximo(t_fila *f) {
    
    if (vaziaF(*f)) 
        return VAZIA;

    int chave = f->inicio->e.chave;
    return chave;

}


int contarF(t_fila *f) {

    return f->cont;

}


int printar(t_fila *f) {
    
    t_apontador_f p = f->inicio;
    if (p == NULL) {
        printf("FILA VAZIA!\n");
        return ERROR;
    }

    printf("INICIO\n");

    while(p != NULL) {
        printf("  %d\n", p->e.chave);
        p = p->anterior;
    }
    printf("FIM\n");

}
