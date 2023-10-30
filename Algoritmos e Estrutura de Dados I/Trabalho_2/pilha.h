#ifndef PILHA_H
#define PILHA_H

#define SUCESSO 1
#define ERROR -1
#define CHEIA -2
#define VAZIA -3


typedef struct {
	int chave;
} t_elemento;

typedef struct t_no *t_apontador;

typedef struct t_no {
	t_elemento e;
	t_apontador prox;
} t_no;

typedef struct {
	t_apontador topo;		// cabeça
	int cont;
} t_pilha;

void inicializar(t_pilha *p);
int push(int chave, t_pilha *p);
int pop(int chave, t_pilha *p);
int vazia(t_pilha p);
int cheia(t_pilha p);
void imprimir(t_pilha p);
// void limpar(t_pilha *p);
#endif