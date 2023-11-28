#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

static int max(int a, int b) {
	return a > b ? a : b;
}

static int retorna_h(t_arvore t) {
	if (t == NULL)
		return -1;
	else
		return t->h;
}

static int update_altura(t_arvore t) {

	return max(retorna_h(t->esq), retorna_h(t->dir)) + 1;
    
}

static void rot_dir(t_arvore t) {

	t_apontador aux, A;

	aux = t->esq;
	A = aux->dir;

	(*t)->esq = A;
	aux->dir = (*t);

	(*t)->h = update_altura(&(*t));
	aux->h = update_altura(&(aux));

	// mudar a raiz
	(*t) = aux;

}

static void rot_esq(t_abb *t) {

	t_apontador aux, A;

	aux = (*t)->dir;
	A = aux->esq;

	(*t)->dir = A;
	aux->esq = (*t);

	(*t)->h = update_altura(&(*t));
	aux->h = update_altura(&(aux));


	// mudar a raiz
	(*t) = aux;

}

void limpar(t_arvore t) {

	if (t == NULL) {
        printf("LIMPAR: arvore ja vazia\n");
        return;
    }

	limpar(t->esq);
	limpar(t->dir);
	free(t);

}

t_arvore criarArvore() {
    t_arvore t = malloc(sizeof(t_no));
    if (t == NULL) {
        printf("CRIAARVORE: memoria cheia!\n");
        return t;
    }

    t = NULL;
    return t;
}

t_elemento pesquisar(t_chave chave, t_arvore t) {

	if (t == NULL) {
		printf("PESQUISAR: Arvore vazia!\n");
        t_elemento e;
        e.chave = -1;
		return e;
	}

	if (chave == t->e.chave) {
		printf("PESQUISAR: Chave encontrada\n");
		return t->e;
	} 
    
    else {

		if(chave < t->e.chave)
			return pesquisar(chave, t->esq);

		else 
			return pesquisar(chave, t->dir);

	}

}

static int cria_raiz(t_chave chave, t_arvore t) {

	t = malloc(sizeof(t_no));

	if (t == NULL) {
		printf("CRIARAIZ: Memoria cheia\n");
		return ERROR;
	}

	t->e.chave = chave;
	t->dir = NULL;
	t->esq = NULL;
	t->h = 0;

	return SUCESSO;

}

int inserir(t_chave chave, t_arvore t) {

	if (t == NULL) {
		return cria_raiz(chave, t);
	}

	if (chave == t->e.chave) {
		printf("INSERIR: Chave já inserida!\n");
		return ERROR;
	} 
    
    else {

		int ret;

		if(chave < t->e.chave)
			ret = inserir(chave, t->e.esq);
		else
			ret = inserir(chave, t->e.dir);

		
		t->h = update_altura(t);

		int fb = retorna_h(&(*t)->esq) - retorna_h(&(*t)->dir);

		// tratar desbalanceamento
		if (fb > 1) {

			t_apontador esq = (*t)->esq; // com certeza esse no existe! reflitão
			int fb_esq = retorna_h(&(esq->esq)) - retorna_h(&(esq->dir));

			if (fb_esq < 0) { // rot. esq-dir
				printf("Esq-dir\n");
				rot_esq(&esq);
				rot_dir(&(*t));

			} else { // rot. dir
				printf("Dir\n");
				rot_dir(&(*t));
			}

			// if (fb_esq < 0) // rot. esq-dir
			// 	rot_esq(&esq);
			// rot_dir(&(*t));


		} else if (fb < -1) {

			t_apontador dir = (*t)->dir; // com certeza esse no existe! reflitão
			int fb_dir = retorna_h(&(dir->esq)) - retorna_h(&(dir->dir));

			if (fb_dir >= 0) { //rot. dir-esq
				printf("Dir-esq\n");

				rot_dir(&dir);
				rot_esq(&(*t));

			} else { //rot. esq
				printf("Esq\n");
				rot_esq(&(*t));
			}

			// if (fb_dir >= 0) //rot. dir-esq (faz a dir no filho)
			// 	rot_dir(&dir);
			// rot_esq(&(*t));


		}

		return ret;

	}

}

static void achaMaiorEsqTroca(t_arvore t, t_arvore sub_t) {

    // encontrar elemento mais a esquerda da arvore à direita
	if (sub_t->dir == NULL) {
        
		t_apontador p = sub_t;

		t->e = sub_t->e;
		
		sub_t = sub_t->esq;

		free(p);

		return;
	}

	achaMaiorEsqTroca(t, &(*sub_t)->dir);
	(*t)->h = update_altura(&(*t));

}

int remover(t_chave c, t_arvore t) {

	if (t == NULL) {
		printf("REMOVER: Arvore vazia!\n");
		return ERROR;
	}

	// tratar quando acha
	if (c == t->e.chave) {

		t_apontador p;

		//caso 1 (nó folha)
		if (t->e.esq == NULL && t->e.dir == NULL) {

			p = t;
			t = NULL;
			free(p);

			return SUCESSO;
		}

		//caso 2 (1 filho esq)
		if (t->dir == NULL) {

			p = t;
			t = p->esq;
			free(p);

			return SUCESSO;
		} 
		//caso 2 (1 filho dir)
		if (t->esq == NULL) {

			p = t;
			t = p->dir;
			free(p);

			return SUCESSO;
		}

		//caso 3 (2 sub-arvores filhos)
		achaMaiorEsqTroca(t, t->esq);
		return SUCESSO;

	}

	int ret;

	if(c < (*t)->chave)
		ret = remover(c, &(*t)->esq);
	else
		ret = remover(c, &(*t)->dir);

	// ajustar
	(*t)->h = update_altura(&(*t));

	return ret;

}


int vazia(t_abb *t);

void em_ordem(t_abb *t) {

	if ((*t) == NULL)
		return;

	em_ordem(&(*t)->esq);
	printf("%d (%d);  ", (*t)->chave, (*t)->h);
	em_ordem(&(*t)->dir);

}