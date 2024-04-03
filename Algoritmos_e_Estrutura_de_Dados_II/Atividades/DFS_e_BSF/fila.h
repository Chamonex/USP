#ifndef PILHA_H
#define PILHA_H

#define SUCESSO 1
#define ERROR -1
#define CHEIA -2
#define VAZIA -3



typedef struct t_no *t_apontador;

typedef struct t_no {
	int chave;
	t_apontador prox;
    t_apontador anterior;
} t_no;

typedef struct {
	t_apontador inicio;
    t_apontador fim;
	int cont;
} t_fila;

void inicializar(t_fila *f);
int inserir(int e, t_fila *f);
int remover(t_fila *f);
int vazia(t_fila f);
int cheia();
int proximo(t_fila *f);
int contar(t_fila *f);
int printar(t_fila *f);

#endif