#include "abb.h"
#include <stdio.h>
#include <stdlib.h>


t_arvore criaArvore() {
    /*
        malloc em uma nova árvore (apenas um ponteiro da raiz,
        que vai apontar para NULL já que está vazia)
    */
    t_arvore t = malloc(sizeof(t_arvore));
    
    if (t == NULL) {
        printf("CRIAARVORE: memoria cheia!\n");
        t->e.chave = -1;
        return t;
    }

    t = NULL;
    return t;
}


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


t_elemento pesquisar(t_apontador p, t_chave chave) {
    /*
        começa com a raiz da árvore
    */

    // arvore vazia, raiz = NULL
    if (p == NULL) {
        printf("PESQUISAR: arvore vazia!\n");
        // função retorna t_elemento, criar um para informar erro
        t_elemento erro;
        erro.chave = -1;
        return erro;
    }

    if (chave == p->e.chave) {
        printf("PESQUISAR: chave encontrada!\n");
        return p->e;
    }

    if (chave < p->e.chave) {
        p = p->esq;
        return pesquisar(p, chave);
    }
    else if (chave > p->e.chave) {
        p = p->dir;
        return pesquisar (p, chave);
    }
    
}

static criaRaiz(t_apontador p, t_elemento e) {

    p->e = e;
    p->dir = NULL;
    p->esq = NULL;

    return SUCESSO;

}

int inserir(t_apontador p, t_elemento e) {

    if (p == NULL) 
        return criaRaiz(p, e);

    else if (p->e.chave == e.chave) {

        printf("INSERIR: chave ja existe!\n");
        return ERROR;
    
    }

    else {
        if (e.chave < p->e.chave)
            return inserir(p->esq, e);
        else
            return inserir(p->dir, e);
    }

}

static void caso3(t_apontador maior, t_apontador atual) {

    
    if (maior->esq != NULL)
        caso3(maior->esq, atual);
    
    t_apontador aux = maior;
    atual = maior;
    free(aux);

    return;

}

int remover(t_apontador p, t_chave chave) {

    if (p == NULL) {
        printf("REMOVER: lista vazia!\n");
        return ERROR;
    }

    if (chave < p->e.chave) 
        return remover(p->esq, chave);

    if (chave > p->e.chave)
        return remover(p->dir, chave);

    if (chave == p->e.chave) {

        t_apontador aux;

        // caso 1 -> elemento folha
        if (p->dir == NULL && p->esq == NULL) {
            aux = p;
            p = NULL;
            free(aux);

            return SUCESSO;
        }

        // caso 2 -> elemento com 1 sub-arvore esq
        if (p->dir == NULL) {
            aux = p;
            p = p->esq;
            free(aux);

            return SUCESSO;
        }

        // caso 2 -> elemento com 1 sub-arvore dir
        if (p->esq == NULL) {
            aux = p;
            p = p->dir;
            free(aux);

            return SUCESSO;
        }

        // caso 3 -> elemento com 2 sub-arvores
        else {
            // encontrar o maior elemento da sub arvore a esquerda
            caso3(p->esq, p);
            return SUCESSO;
        }

    }


}
