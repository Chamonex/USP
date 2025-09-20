#ifndef ABB_H
#define ABB_H

#define ERROR -1
#define SUCESSO 1

typedef int t_chave;

typedef struct {
    t_chave chave;
    // outros campos! 
} t_elemento;

typedef struct t_no *t_apontador;

typedef struct t_no {
    t_apontador esq, dir;
    t_elemento e;
} t_no;

// a arvore é só um apontador!
typedef t_apontador t_arvore;

t_arvore criarArvore();
void limpar(t_arvore);
t_elemento pesquisar(t_apontador, t_chave);
int inserir(t_apontador, t_elemento);
int remover(t_apontador, t_chave);
int vazia (t_arvore);

#endif
