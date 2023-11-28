#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

void limpar(t_apontador p) {

    /*
        para limpar uma árvore, devemos usar PÓS-ORDEM
    */

    if (p != NULL) {
        limpar(p->esq);
        limpar(p->dir);
        free(p);
    }

    return;
}

t_arvore criaArvore() {
    t_arvore t = malloc(sizeof(t_no));
    if (t == NULL) {
        printf("CRIAARVORE: memoria cheia!\n");
        t->e.chave = -1;
        return t;
    }

    t->h = 0;
    t->e = NULL;
}


t_chave pesquisar(t_chave c, t_abb *t);
int inserir(t_chave c, t_abb *t);
int remover(t_chave c, t_abb *t);
int vazia(t_abb *t);
