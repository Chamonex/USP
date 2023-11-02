#include "skiplist.h"
#include <stdio.h>
#include <stdlib.h>


static t_no* novoNo(int chave, int nivel) {

    t_no *novo = malloc(sizeof(t_no));

    if (novo == NULL)   // memoria cheia
        novo->e.chave == -1;
        return novo;


    // trocar chave por NOME
    novo->e.chave = chave;
    // criar CHAVE
    novo->prox = malloc((nivel+1) * sizeof(t_no*));

    for (int i = 0; i <= nivel; i++)
        novo->prox[i] = NULL;
    
    return novo;

}


static int sorteiaNivel(t_skiplist *l){
    
	float r = (float)rand()/RAND_MAX;
	int nivel = 0;
	
    while(r < l->p && nivel < l->nivelMax){
		nivel++;
		r = (float)rand()/RAND_MAX;
	}

	return nivel;
}


static int obterChave(char nome[]) {
    int c = nome[0];
    int cont = 1;
    int chave = 0;

    // funciona somente para letras minusculas
    while (c > 96 && c < 123) {
        chave += (c-96) * cont;
        cont++;
        c = nome[cont-1];
    }

    return chave;    
}


t_skiplist* inicializar(int max, float p) {

    t_skiplist *l = (t_skiplist*) malloc(sizeof(t_skiplist));

    if (l == NULL)     // memoria cheia
        l->inicio->e.chave = -1;
        return l;

    l->nivelMax = max;
    l->p = p;
    l->nivel = 0;

    l->inicio = novoNo(-1, max);

    return l;
}


int pesquisar(t_skiplist *l, int chave) {
    if (l == NULL)
        return ERROR;

    t_no *atual = l->inicio;

    for (int i = l->nivel; i >= 0; i--) {
        while((atual->prox[i] != NULL)&&(atual->prox[i]->e.chave < chave)) {  // entender ! 

            atual = atual->prox[i];

        }
    }

    atual = atual->prox[0];

    if(atual != NULL && atual->e.chave == chave)
        return SUCESSO;

    return ERROR;

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


int inserir(t_skiplist *l, int chave) {
    if (l == NULL)
        return ERROR;
    
    t_no *atual = l->inicio;
    t_no **aux;
    aux = malloc((l->nivelMax +1) * sizeof(t_no*));

    for (int i = 0; i <= l->nivelMax; i++)
        aux[i] = NULL;
    
    for (int i = l->nivel; i >= 0 ;i--) {
        while (atual->prox[i] != NULL && atual->prox[i]->e.chave < chave)
            atual = atual->prox[i];
        
        aux[i] = atual;
    }

    atual = atual->prox[0];

    if (atual == NULL || atual->e.chave != chave) {
        int novo_nivel = sorteiaNivel(l);

        t_no *novo = novoNo(chave, novo_nivel);

        if (novo = NULL) {
            free(aux);
            return ERROR;
        }

        if (novo_nivel > l->nivel) {
            for (int i = l->nivel+1; i <= novo_nivel; i++)
                aux[i] = l->inicio;
            
            l->nivel = novo_nivel;
        }

        for (int i = 0; i <= novo_nivel; i++) {
            novo->prox[i] = aux[i]->prox[i];
            aux[i]->prox[i] = novo;
        }

        free(aux);
        return SUCESSO;
    }
}


int remover(t_skiplist *l, int chave){
    
    if (l = NULL)
        return ERROR;
    
    t_no *atual = l->inicio;

    t_no **aux;
    aux = malloc((l->nivelMax+1) * sizeof(t_no*));

    for (int i = 0; i <= l->nivelMax; i++) 
        aux[i] = NULL;

    for (int i = l->nivel; i >= 0; i--) {
        while (atual->prox[i] != NULL && atual->prox[i]->e.chave < chave) 
            atual = atual->prox[i];
        
        aux[i] = atual;
    }

    atual = atual->prox[0];

    if (atual != NULL && atual->e.chave == chave) {

        for(int i = 0; i <= l->nivel; i++) {
            if (aux[i]->prox[i] != atual)
                break;
            aux[i]->prox[i] != atual->prox[i];
        }

        while(l->nivel > 0 && l->inicio->prox[l->nivel] == NULL)
			l->nivel--;
        
        free(atual->prox);
        free(atual);
        free(aux);

        return SUCESSO;
    }

    free(aux);
    return ERROR;
}


int alterar(t_skiplist *l, char *nome, int novo_tel) {



}

