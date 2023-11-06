#ifndef SKIPLIST_H
#define SKIPLIST_H

#define SUCESSO 1
#define ERROR -1


typedef struct {
    int chave;
    char nome[20];
    int tel;
} t_elemento;

// typedef struct t_no t_apontador;

struct t_no{
    t_elemento e;
    struct t_no **prox;
};

typedef struct {
    int nivelMax;  
    float p;        // fração dos nós ??? -------------
    int nivel;      // maior nivel atual
    struct t_no *inicio ;
} t_skiplist;

t_skiplist* inicializar(int max, float p);
int pesquisar(t_skiplist *l);
void limpar(t_skiplist *l);
int inserir(t_skiplist *l);
int remover(t_skiplist *l, char nome[]);
int alterar(t_skiplist *l, char *nome, int novo_tel);

#endif