#include "skiplist.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void inicializar(t_skiplist *l) {
    l->h = 0;
    l->n = 0;
    l->header = NULL;

}

static int criarChave(char nome[]) {

    return (sizeof nome);

}


t_apontador buscarNo(char nome[], t_apontador p) {  

    int chave = criarChave(nome);

    while (p != NULL) {
        if (p->e.chave == chave) {
            return p;
        }

        if (p->prox->e.chave > chave) {
            if (p->baixo == NULL) {
                printf("MUDDAR! .buscarNo -> nao encontrei o elemento para alterar!");
                t_apontador erro = NULL;
                return erro;
            }
            p = p->baixo;
        }
        else
            p = p->prox;
    }
    
    printf(".BuscarNo -> Operacao invalida: contatinho nao encontrado\n");
    t_apontador erro = NULL;
    return erro;

}


int alterar(char nome[], int tel, t_skiplist *l) {
    t_apontador p = l->header;
    t_apontador alterar = buscarNo(nome, p);

    if (alterar == NULL) {
        printf("Nao encontrei\n");
        return ERROR;
    }

}
