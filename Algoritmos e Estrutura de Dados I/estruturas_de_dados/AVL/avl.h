#ifndef ABB_H
#define ABB_H

#define SUCESSO 1
#define ERROR -1

typedef int t_chave;

typedef struct {
	t_chave chave;
	// outros atributos
} t_elemento;

typedef struct t_no *t_apontador;

typedef struct t_no {
	t_apontador esq, dir;
	t_elemento e;
	int h;
} t_no;


typedef t_apontador t_arvore;

void limpar(t_arvore t);
t_arvore criarArvore();
t_elemento pesquisar(t_chave c, t_arvore t);
int inserir(t_chave c, t_arvore t);
int remover(t_chave c, t_abb *t);
int vazia(t_abb *t);
void em_ordem(t_abb *t);


#endif