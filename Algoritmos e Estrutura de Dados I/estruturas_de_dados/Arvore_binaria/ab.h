typedef int t_chave;

typedef struct {
    t_chave chave;
    // outros campos! 
} t_elemento;

typedef struct t_no *t_apontador;

typedef struct t_no {
    t_elemento e;
    t_apontador esq, dir;
} t_no;

typedef t_apontador t_arvore;