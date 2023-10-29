#ifndef SKIPLIST_H
#define SKIPLIST_H

#define SUCESSO 1;
#define ERROR -1;

typedef struct {
    int chave;
    char nome[20];
    int telefone;
} t_elemento;

typedef struct t_no *t_apontador;
typedef struct t_no {
    t_elemento e;
    t_apontador prox;
    t_apontador baixo;
} t_no;

typedef struct {
    int h;
    int n;
    t_apontador header;
} t_skiplist;

void inicializar(t_skiplist *l);
int inserir(t_skiplist *l, t_elemento);
int alterar(char nome[], int tel, t_skiplist *l);



#endif