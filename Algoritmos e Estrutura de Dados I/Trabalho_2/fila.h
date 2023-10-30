#ifndef FILA_H
#define FILA_H

#define SUCESSO 1
#define ERROR -1
#define CHEIA -2
#define VAZIA -3


typedef struct {
	int chave;
} t_elemento_f;

typedef struct t_no_f *t_apontador_f;

typedef struct t_no_f {
	t_elemento_f e;
	t_apontador_f prox;
    t_apontador_f anterior;
} t_no_f;

typedef struct {
	t_apontador_f inicio;
    t_apontador_f fim;
	int cont;
} t_fila;

void inicializarF(t_fila *f);
int inserir(int chave, t_fila *f);
int remover(int chave, t_fila *f);
int vaziaF(t_fila *f);
int cheiaF(t_fila f);
int printar(t_fila *f);
// void limparF(t_fila *f);

#endif