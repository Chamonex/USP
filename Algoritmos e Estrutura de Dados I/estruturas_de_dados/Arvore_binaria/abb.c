#include "abb.h"
#include <stdio.h>
#include <stdlib.h>


t_arvore criaArvore() {
    /*
        malloc em uma nova árvore (apenas um ponteiro da raiz,
        que vai apontar para NULL já que está vazia)
    */
    t_arvore t = malloc(sizeof(t_arvore));
    t = NULL;
    return t;
}


void limpar(t_arvore);
t_chave pesquisar(t_apontador, t_chave);
int inserir(t_elemento, t_apontador);
int remover(t_chave, t_apontador);
int vazia (t_arvore);