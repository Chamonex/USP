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
    p->anterior = NULL;

    if(f->cont == 0) { 
        f->cont++;
        p->prox = NULL;
        f->fim = p;
        f->inicio = p;
        return SUCESSO;
    }

    f->fim->anterior = p;
    t_apontador_f aux = f->fim;
    f->fim = p;
    p->prox = aux;
    f->cont++;
    
    return SUCESSO;
}


int remover(int key, t_fila *f) {
    
    if (f->inicio->e.chave != key)
        return 1;

    f->cont--;
    t_apontador_f aux = f->inicio;
    free(f->inicio);
    f->inicio = aux->anterior;
    return 0;
}


int vaziaF(t_fila *f) {
    if (f->cont == 0)
        return VAZIA;
    
    return SUCESSO;
}


int cheiaF(t_fila f) {
    t_apontador_f teste = malloc(sizeof(t_no_f));
    if (teste == NULL)
        return CHEIA;

    return SUCESSO;
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

// void limparF(t_fila *f) {
    
//}
