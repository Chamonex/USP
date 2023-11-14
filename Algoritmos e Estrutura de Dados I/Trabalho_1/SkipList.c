#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SkipList.h"


static int obterChave(char nome[]) {

    // gerar uma chave com base no vetor de caracteres nome
    int chave = 0;
	int len = strlen(nome);
    int i = 0;
	int j = len-1;
	int cont = 0;
	int k = 0;
    while (i < j) {
        chave += nome[i] * nome[j];
		i++;
		j--;
		k++;
    }
    
    return chave;

}


static struct NO* novoNo(int chave, int nivel){
	struct NO* novo = malloc(sizeof(struct NO));
	if(novo != NULL){
		
        novo->chave = chave;
        novo->prox = malloc((nivel+1)* sizeof(struct NO*));
        int i;

        for(i=0; i<(nivel+1); i++)
            novo->prox[i] = NULL;

	}
	return novo;
}

SkipList* criaSkipList(int NivelMAX, float P){
    SkipList *sk = (SkipList*) malloc(sizeof(SkipList));
	
    if(sk != NULL){
    
	    sk->NivelMAX = NivelMAX;
        sk->P = P;
        sk->nivel = 0;
		
        sk->inicio = novoNo(-1, NivelMAX);
    }

	return sk;
}

int sorteiaNivel(SkipList *sk){
	
	float r = (float)rand()/RAND_MAX;
	int nivel = 0;
	while(r < sk->P && nivel < sk->NivelMAX){
		nivel++;
		r = (float)rand()/RAND_MAX;
	}
	return nivel;
}


int buscaSkipList(SkipList *sk, char nome[]){
    if(sk == NULL)
        return 0;
	
	int chave = obterChave(nome);

	struct NO *atual = sk->inicio;

	int i;
	for(i = sk->nivel; i >= 0; i--){
        while(atual->prox[i] != NULL && atual->prox[i]->chave < chave)
            atual = atual->prox[i];
	}


	atual = atual->prox[0];
	if(atual != NULL && atual->chave == chave) {
		printf("Contatinho encontrado: telefone %s\n", atual->tel);
		return 1;
	}
    else {
		printf("Contatinho nao encontrado\n");	
        return 0;
	}
}

int insereSkipList(SkipList *sk, char nome[], char tel[]){
	
    if(sk == NULL)
        return 0;

	int chave;
	chave = obterChave(nome);

	int i;
	struct NO *atual = sk->inicio;

	struct NO **aux;
	aux = malloc((sk->NivelMAX+1) * sizeof(struct NO*));
	for(i = 0; i <= sk->NivelMAX; i++)
	    aux[i] = NULL;


	for(i = sk->nivel; i >= 0; i--){
		while(atual->prox[i] != NULL && atual->prox[i]->chave < chave)
			atual = atual->prox[i];
		aux[i] = atual;
	}

	atual = atual->prox[0];

	if(atual == NULL || atual->chave != chave){
		
		int novo_nivel = sorteiaNivel(sk);
		
		struct NO* novo = novoNo(chave, novo_nivel);
		
		if(novo == NULL){
            free(aux);
            return 0;
		}

		strcpy(novo->nome, nome);
		strcpy(novo->tel, tel);


		if(novo_nivel > sk->nivel){
			for(i = sk->nivel+1; i <= novo_nivel; i++)
				aux[i] = sk->inicio;

			sk->nivel = novo_nivel;
		}

		for(i = 0; i <= novo_nivel; i++){
			novo->prox[i] = aux[i]->prox[i];
			aux[i]->prox[i] = novo;
		}

		free(aux);
		return 1;
	}

	if (atual->chave == chave) {
		printf("Contatinho ja inserido\n");
		free(aux);
		return 0;
	}

	free(aux);
	return 0;
}

int alteraSkiplist(SkipList* sk, char nome[], char tel[]) {

    if(sk == NULL)
        return 0;
	
	int chave = obterChave(nome);

	struct NO *atual = sk->inicio;

	int i;
	for(i = sk->nivel; i >= 0; i--){
        while(atual->prox[i] != NULL && atual->prox[i]->chave < chave)
            atual = atual->prox[i];
	}

	atual = atual->prox[0];
	if(atual != NULL && atual->chave == chave) {
		strcpy(atual->tel, tel);
		return 1;
	}

	printf("Operacao invalida: contatinho nao encontrado\n");
	return 0;

}


int removeSkipList(SkipList *sk, char nome[]){
    if(sk == NULL)
        return 0;

	int chave = obterChave(nome);

	int i;
	struct NO *atual = sk->inicio;

	struct NO **aux;
	aux = malloc((sk->NivelMAX+1) * sizeof(struct NO*));

	for(i = 0; i <= sk->NivelMAX; i++)
	    aux[i] = NULL;


	for(i = sk->nivel; i >= 0; i--){
		while(atual->prox[i] != NULL && atual->prox[i]->chave < chave)
			atual = atual->prox[i];
		aux[i] = atual;
	}

	atual = atual->prox[0];

	if(atual != NULL && atual->chave == chave){

		for(i = 0; i <= sk->nivel; i++){
			if(aux[i]->prox[i] != atual)
				break;

			aux[i]->prox[i] = atual->prox[i];
		}
		
		while(sk->nivel > 0 && sk->inicio->prox[sk->nivel] == NULL)
			sk->nivel--;

		free(atual->prox);
		free(atual);
		free(aux);
		return 1;
	}

	printf("Operacao invalida: contatinho nao encontrado\n");
	free(aux);
	return 0;
}

void liberaSkipList(SkipList* sk){
    if(sk == NULL)
        return;

    struct NO *no, *atual;
    atual = sk->inicio->prox[0];
    while(atual != NULL){
        no = atual;
        atual = atual->prox[0];
        free(no->prox);
        free(no);
    }

    free(sk->inicio);
    free(sk);
}

