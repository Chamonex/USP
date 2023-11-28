#ifndef ABB_H
#define ABB_H

#define SUCESSO 1
#define ERROR -1

typedef int t_chave;

typedef struct {
    t_chave chave;
    // outros
} t_elemento;

typedef struct t_no *t_apontador;

typedef struct t_no {
	t_apontador esq, dir;
	t_elemento e;
	int h;
} t_no;

typedef t_apontador t_arvore;


typedef t_apontador t_abb;


void limpar(t_apontador);
t_arvore criaArvore();
int inserir(t_chave c, t_abb *t);
int remover(t_chave c, t_abb *t);
int vazia(t_abb *t);


#endif