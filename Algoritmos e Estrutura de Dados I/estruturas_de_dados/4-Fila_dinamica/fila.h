typedef struct {
    int chave;
} t_elemento;

typedef struct t_no *t_apontador;

typedef struct t_no {
    t_apontador prox;
    t_elemento e;
} t_no;


typedef struct {

} t_fila;




int inserir(t_fila, int);
int remover(t_fila, int);
int cria(t_fila);
int frente(t_fila);
int vazia(t_fila);
int cheia(t_fila);

