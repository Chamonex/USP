#include "skiplist.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void inicializar(t_skiplist *l) {
    l->h = 0;
    l->n = 0;
    l->header = NULL;

}

int pesquisar(int chave, t_skiplist *l) {
    t_apontador p = l->header;

    while (p != NULL) {
        if (p->e.chave == chave) {
            printf("contatinho encontrado: telefone %d\n", p->e.telefone);
            return SUCESSO;
        }

        if (p->prox->e.chave > chave) {
            if (p->baixo == NULL) {
                printf("Operacao invalida: contatinho nao encontrado\n");
                return ERROR;
            }
            p = p->baixo;
        }
        else
            p = p->prox;
    }
}

static int criarChave(char nome[]) {
    
}


static t_apontador buscarNo(char nome[], t_apontador p) {  

    while (p != NULL) {
        if (p->e.nome == nome) {
            return p;
        }

        if (p->prox->e.chave > chave) {
            if (p->baixo == NULL) {
                printf("Operacao invalida: contatinho nao encontrado\n");
                return ERROR;
            }
            p = p->baixo;
        }
        else
            p = p->prox;
    }
}


int alterar(char nome[], int tel, t_skiplist *l) {
    t_apontador p = l->header;
    buscarNo(nome, p);
}
