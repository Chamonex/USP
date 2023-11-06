#include "skiplist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


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


static struct t_no* novoNo(int nivel, char nome[], int tel) {

    struct t_no *novo = malloc(sizeof(struct t_no));

    if (novo == NULL) {
        // memoria cheia
        novo->e.chave == -1;
        return novo;
    }  

    strcpy(novo->e.nome, nome);
    novo->e.chave = obterChave(nome);

    novo->prox = malloc((nivel+1) * sizeof(struct t_no*));
        // proximo é um ponteiro para um ponteiro (vetor de ponteiros)
        
    for (int i = 0; i <= (nivel + 1); i++)
        novo->prox[i] = NULL;

    return novo;

}


static int sorteiaNivel(t_skiplist *l){
    
    srand((unsigned)time(NULL)); // alimentando o rand com a seed time
	float r = (float)rand()/RAND_MAX;   // numero de zero a um
	int nivel = 0;
	
    while(r < l->p && nivel < l->nivelMax){
		nivel++;
		r = (float)rand()/RAND_MAX;
	}

	return nivel;
}


static int sortBin() {
    // retorna 1 ou 0, aleatorio
    srand((unsigned)time(NULL));
    int i = rand() %2;
    return i;
    
}


static struct t_no* pesquisarNo(t_skiplist *l, char nome[]) {

    /* 
    printar o nome do elemento buscado
    */

    int chave = obterChave(nome);

    struct t_no *atual = l->inicio;

    for (int i = l->nivel; i >= 0; i--) {   // passar em cada nível
        while((atual->prox[i] != NULL)&&(atual->prox[i]->e.chave < chave)) // entender ! 

            atual = atual->prox[i]; 
        
    }

    atual = atual->prox[0];

    if(atual->e.chave == chave) {

        return atual;

    }

}



t_skiplist* inicializar(int max, float p) { // descobrir o que é o p -----------------

    t_skiplist *l = (t_skiplist*) malloc(sizeof(t_skiplist));

    if (l == NULL) {
        // memoria cheia
        l->inicio->e.chave = -1;
        return l;
    }   

    l->nivelMax = max;
    l->p = p;
    l->nivel = 0;


    struct t_no *novo = malloc(sizeof(struct t_no));

    novo->e.chave = -1;

    novo->prox = malloc(sizeof(struct t_no*));

    novo->prox[0] = NULL;

    l->inicio = novo;
    return l;
}


int pesquisar(t_skiplist *l) {


    /* 
    printar o nome do elemento buscado
    */

    if (l == NULL)
        return ERROR;

    char nome[20];
    gets(nome);

    int chave = obterChave(nome);

    struct t_no *atual = l->inicio;

    for (int i = l->nivel; i >= 0; i--) {   // passar em cada nível
        if(atual->prox[i] != NULL) 
            printf("if ok"); 
        
    }

    // for (int i = l->nivel; i >= 0; i--) {   // passar em cada nível
    //     while((atual->prox[i] != NULL)&&(atual->prox[i]->e.chave < chave)) 
    //         atual = atual->prox[i]; 
        
    // }

    atual = atual->prox[0];


    if(atual->e.chave == chave) {
        printf("Contatinho encontrado: telefone %d\n", atual->e.tel);
        return SUCESSO;
    }

    printf("Operacao invalida: contatinho nao encontrado\n");
    return ERROR;

}



int inserir(t_skiplist *l) {

    printf("abriu inserir\n");
    char nome[20];
    int tel;
    gets(nome);
    getchar();
    scanf("%d", &tel);
    int chave = obterChave(nome);

    struct t_no *atual = l->inicio;
    struct t_no **aux;

    aux = malloc((l->nivelMax +1) * sizeof(struct t_no*));  // ponteiro de ponteiros

    for (int i = 0; i <= l->nivelMax; i++)
        aux[i] = NULL;

    for (int i = l->nivel; i >= 0 ;i--) {
        while (atual->prox[i] != NULL && atual->prox[i]->e.chave < chave) {
            atual = atual->prox[i];
        }

        aux[i] = atual; // aponta para onde o nó será inserido
        
    }

    
    atual = atual->prox[0]; 
    if (atual == NULL)
    
    if (atual != NULL) {

        if (atual->e.chave == chave) {
            // nao pode ter a mesma chave
            printf("Contatinho ja inserido\n");
            return ERROR;
        }
    }

    int sort = sortBin();
 
    // se for o ultimo elemento
    // e for sorteado (50%)
    // tem que sortear o nivel nível
    
    int novo_nivel = sorteiaNivel(l);

    struct t_no *novo = novoNo(novo_nivel, nome, tel);

    if (novo->e.chave == -1) {
        // memoria cheia
        free(aux);
        return ERROR;
    }

    if (novo_nivel > l->nivel) {
        // aumentar o nivel da skiplist
        for (int i = l->nivel+1; i <= novo_nivel; i++)
            aux[i] = l->inicio;     
            // aux[i] = l->inicio; // nao seria melhor apontar para NULL? ----------
        
        l->nivel = novo_nivel;
    }

    for (int i = 0; i <= novo_nivel; i++) {
        // inserir elemento
        novo->prox[i] = aux[i]->prox[i];
        aux[i]->prox[i] = novo;
    }

    free(aux);
    return SUCESSO;

}


int remover(t_skiplist *l, char nome[]){
    
    struct t_no *atual = l->inicio;

    struct t_no **aux;
    aux = malloc((l->nivelMax+1) * sizeof(struct t_no*));

    int chave = obterChave(nome);

    for (int i = 0; i <= l->nivelMax; i++) 
        aux[i] = NULL;

    for (int i = l->nivel; i >= 0; i--) {
        while (atual->prox[i] != NULL && atual->prox[i]->e.chave < chave) 
            atual = atual->prox[i];
        
        aux[i] = atual; // nó anterior
    }

    atual = atual->prox[0]; // nó que deve ser excluido   

    if (atual != NULL && atual->e.chave == chave) {

        for(int i = 0; i <= l->nivel; i++) {
            if (aux[i]->prox[i] != atual)
                break;
            aux[i]->prox[i] = atual->prox[i];   
        }

        while(l->nivel > 0 && l->inicio->prox[l->nivel] == NULL)
			l->nivel--;
        
        free(atual->prox);
        free(atual);
        free(aux);

        return SUCESSO;
    }

    free(aux);
    return ERROR;   // nao encontrou a chave
}


int alterar(t_skiplist *l, char nome[], int novo_tel) {

    struct t_no *n = pesquisarNo(l, nome);
    if (n->e.chave == -1) {
        printf("Operacao invalida: contatinho nao encontrado\n");
        return ERROR;
    }
    
    n->e.tel = novo_tel;
    return SUCESSO;

}


void limpar(t_skiplist* l) {
    if (l == NULL)
        return;
    
    struct t_no *no, *atual;
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

