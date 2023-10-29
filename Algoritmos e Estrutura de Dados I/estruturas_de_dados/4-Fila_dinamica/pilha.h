#ifndef PILHA_H
#define PILHA_H

#define SUCESSO 1
#define ERROR -1
#define CHEIA -2
#define VAZIA -3

#define MAX 128

typedef struct {
	int e;
	int *prox;
} t_no;

typedef struct {
	t_no *topo;		// cabeça
	int cont;
} t_pilha;

void inicializar(t_pilha *p);
int push(int, t_pilha *p);
int pop(t_pilha *p);
int vazia(t_pilha p);
int cheia(t_pilha p);
int topo(t_pilha *p);
int contar(t_pilha *p);

#endif