#include "skiplist.h"
#include <stdio.h>
#include <stdlib.h>


static t_no* novoNo(int chave, int nivel) {

    t_no* novo = malloc(sizeof(t_no));

    if (novo == NULL)   // memoria cheia
        return ERROR;

    novo->chave = chave;
    novo->prox = malloc((nivel+1) * sizeof(t_no*));

    for (int i = 0; i <= nivel; i++)
        novo->prox[i] = NULL;
    
    return novo;

}


t_skiplist* inicializar(int max, float p) {

    t_skiplist* sk = (t_skiplist*) malloc(sizeof(t_skiplist));

    if (sk == NULL)     // memoria cheia
        return ERROR;

    sk->nivelMax = max;
    sk->p = p;
    sk->nivel = 0;

    sk->inicio = novoNo(-1, max);

    return sk;
}


void limpar(t_skiplist* l) {
    if (l == NULL)
        return;
    
    t_no *no, *atual;
    atual = l->inicio->prox[0];

    while (atual != NULL) {
        no = atual;
        atual = atual->prox[0];
        free(no->prox);
        free(no);
    }

    free(l->inicio);
    free(l);
}

