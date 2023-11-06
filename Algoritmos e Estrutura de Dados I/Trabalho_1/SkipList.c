#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SkipList.h"


static int obterChave(char nome[]) {

    // gerar uma chave com base no vetor de caracteres nome
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


struct NO* novoNo(int chave, int nivel){
	struct NO* novo = malloc(sizeof(struct NO));
	if(novo != NULL){
        // Cria um novo n� apontando para NULL
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
        // cria o cabe�alho com chave -1
        // a SkipList armazena apenas valores positivos
        sk->inicio = novoNo(-1, NivelMAX);
    }

	return sk;
}

int sorteiaNivel(SkipList *sk){
    // Sorteia o n�vel para o n�
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

	// Partindo do maior n�vel, v� para o pr�ximo n�
	// enquanto a chave for maior do que a do pr�ximo n�
	// Caso contr�rio, desca um n�vel e continue a busca
	int i;
	for(i = sk->nivel; i >= 0; i--){
        while(atual->prox[i] != NULL && atual->prox[i]->chave < chave)
            atual = atual->prox[i];
	}

	// Acesse o n�vel 0 do pr�ximo n�, que �
	// onde a chave procurada deve estar
	atual = atual->prox[0];
	if(atual != NULL && atual->chave == chave) {
		printf("Contatinho encontrado: telefone %d\n", atual->tel);
		return 1;
	}
    else {
		printf("Contatinho nao encontrado\n");	
        return 0;
	}
}

int insereSkipList(SkipList *sk, char nome[], int tel){
	
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

    // Partindo do maior n�vel, v� para o pr�ximo n�
	// enquanto a chave for maior do que a do pr�ximo n�
	// Caso contr�rio, insira o n� no array auxiliar,
	// desca um n�vel e continue a busca
	for(i = sk->nivel; i >= 0; i--){
		while(atual->prox[i] != NULL && atual->prox[i]->chave < chave)
			atual = atual->prox[i];
		aux[i] = atual;
	}

	// Acesse o n�vel 0 do pr�ximo n�, que �
	// onde a chave deve ser inserida
	atual = atual->prox[0];

    // Cria e insere um novo n� se a chave n�o existir
    // Final da lista (atual == NULL) ou
    // entre auxiliar[0] e atual
	if(atual == NULL || atual->chave != chave){
		// Sorteia o n�vel
		int novo_nivel = sorteiaNivel(sk);
		// Cria um novo n� apontando para NULL
		struct NO* novo = novoNo(chave, novo_nivel);
		
		if(novo == NULL){
            free(aux);
            return 0;
		}

		strcpy(novo->nome, nome);
		novo->tel = tel;


		if(novo_nivel > sk->nivel){
			for(i = sk->nivel+1; i <= novo_nivel; i++)
				aux[i] = sk->inicio;

			sk->nivel = novo_nivel;
		}

		// Insere o n�, arrumando os ponteiros
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

int alteraSkiplist(SkipList* sk, char nome[], int tel) {

    if(sk == NULL)
        return 0;
	
	int chave = obterChave(nome);

	struct NO *atual = sk->inicio;

	// Partindo do maior n�vel, v� para o pr�ximo n�
	// enquanto a chave for maior do que a do pr�ximo n�
	// Caso contr�rio, desca um n�vel e continue a busca
	int i;
	for(i = sk->nivel; i >= 0; i--){
        while(atual->prox[i] != NULL && atual->prox[i]->chave < chave)
            atual = atual->prox[i];
	}

	// Acesse o n�vel 0 do pr�ximo n�, que �
	// onde a chave procurada deve estar
	atual = atual->prox[0];
	if(atual != NULL && atual->chave == chave) {
		atual->tel = tel;
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
	// Cria um array de n�s auxiliar apontando para NULL
	struct NO **aux;
	aux = malloc((sk->NivelMAX+1) * sizeof(struct NO*));
	for(i = 0; i <= sk->NivelMAX; i++)
	    aux[i] = NULL;

	// Partindo do maior n�vel, v� para o pr�ximo n�
	// enquanto a chave for maior do que a do pr�ximo n�
	// Caso contr�rio, insira o n� no array auxiliar,
	// desca um n�vel e continue a busca
	for(i = sk->nivel; i >= 0; i--){
		while(atual->prox[i] != NULL && atual->prox[i]->chave < chave)
			atual = atual->prox[i];
		aux[i] = atual;
	}

	// Acesse o n�vel 0 do pr�ximo n�, que �
	// onde a chave a ser removida deve estar
	atual = atual->prox[0];

	// Achou a chave a ser removida?
	if(atual != NULL && atual->chave == chave){
		// Come�ando no n�vel 0, se o array auxiliar
		// aponta para o n� a ser removido, fa�a ele
		// apontar para o pr�ximo n� (remo��o de lista encadeada)
		for(i = 0; i <= sk->nivel; i++){
			if(aux[i]->prox[i] != atual)
				break;

			aux[i]->prox[i] = atual->prox[i];
		}
		// Remova os n�veis sem elemento
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

void imprimeSkipList(SkipList *sk){
    if(sk == NULL)
        return;
    int i;
	printf("\n*****Skip List*****\n");
	for(i=0; i <= sk->nivel; i++){
		struct NO *no = sk->inicio->prox[i];
		printf("Nivel %d: ",i);
		while(no != NULL){
			printf("%d ",no->chave);
			printf("%s ",no->nome);
			printf("%d    ", no->tel);
			no = no->prox[i];
		}
		printf("\n");
	}
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

int vaziaSkipList(SkipList* sk){
    if(sk == NULL)
        return 1;

    if(sk->inicio->prox[0] == NULL)
        return 1;
    else
        return 0;
}

int tamanhoSkipList(SkipList* sk){
    if(sk == NULL)
        return 0;

    int cont = 0;
    struct NO *atual;
    atual = sk->inicio->prox[0];
    while(atual != NULL){
        atual = atual->prox[0];
        cont++;
    }
    return cont;
}
