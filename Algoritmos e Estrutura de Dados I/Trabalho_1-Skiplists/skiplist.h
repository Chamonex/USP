#ifndef SKIPLIST_H
#define SKIPLIST_H

#define SUCESSO 1;
#define ERROR -1;


// t_elemento


typedef struct t_no {
    int chave;
    t_no **prox; 
} t_no;

typedef struct {
    int nivelMax;  
    float p;        // fração dos nós
    int nivel;      // nivel atual
    t_no *inicio;
} t_skiplist;

t_skiplist* inicializar(int max, float p);
int buscar(t_skiplist *l, int chave);
void limpar(t_skiplist *l);
int inserir(t_skiplist *l, int chave);)

#endif