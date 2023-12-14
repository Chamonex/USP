#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id1;
    int id2;
    int amigos;
} t_rua;

typedef t_esquina* t_apontador;

typedef struct t_esquina{
    int id;
    t_rua* rua_direita;
    t_rua* rua_baixo;
    t_apontador esq_direita;
    t_apontador esq_baixo;
} t_esquina;

// ---------------------------------------------------------------- //


t_rua* lerRua() {
    t_rua* r = malloc(sizeof(t_rua));

    if (r == NULL) {
        r->id1 = -1;
        return r;
    }

    scanf("%d", r->id1);
    scanf("%d", r->id2);
    scanf("%d", r->amigos);

    return r;
}


t_esquina* criaEsquina(int id, int colunas) {

    t_esquina* e = (t_esquina*) malloc(sizeof(t_esquina));
    e->id = id;

    if (!(id % colunas == id)) {    // se for a ultima da linha, não tem direita

        e->rua_direita = lerRua();

    }

    e->rua_baixo = lerRua();

    e->esq_direita = NULL;
    e->esq_baixo= NULL;

    return e;
}

int linkarEsquinas(t_esquina** bairro, int nEsquinas, int colunas) {

    for (int i = 0; i < nEsquinas; i++) {

        if (i == (nEsquinas - 1)) {         // ultimo, não linka nada
            return 1;
        }

        

        if (i < (nEsquinas - colunas)) {    // não está na ultima linha,
                                            // linka os dois

            bairro[i]->esq_direita = bairro[i+1];

            bairro[i]->esq_baixo = bairro[i+colunas];

        }

        if (i % colunas == i) {             // está na ultima coluna,
                                            // não linka o direita
            bairro[i]->esq_baixo = bairro[i+colunas];   
        }

    }

}


int main() {
    int linhas, colunas;
    int nRuas, nEsquinas;

    scanf("%d%d", &linhas, &colunas);
    printf("%d - %d\n", linhas, colunas);
    nRuas = (linhas - 1) * (colunas - 1);
    nEsquinas = linhas * colunas;


    t_esquina** bairro = (t_esquina**) malloc(nEsquinas * sizeof(t_esquina*));



    for (int i = 0; i < nEsquinas; i++) {
        bairro[i] = criaEsquina(i, colunas);
    }

    linkarEsquinas(bairro, nEsquinas, colunas);

    

}