#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id1;
    int id2;
    int amigos;
} t_rua;

typedef struct t_esquina *t_apontador;

typedef struct t_esquina{
    int id;
    t_rua rua_direita;
    t_rua rua_baixo;
    t_apontador esq_direita;
    t_apontador esq_baixo;
} t_esquina;

// ---------------------------------------------------------------- //


t_rua lerRua() {
    
    t_rua r;
    
    scanf("%d%d%d", &r.id1, &r.id2, &r.amigos);

    return r;
}


t_esquina* criaEsquina(int id, int colunas, int nEsquinas) {

    t_esquina* e = (t_esquina*) malloc(sizeof(t_esquina));
    e->id = id;

    if (id+1 == nEsquinas) {
        e->esq_direita = NULL;
        e->esq_baixo = NULL;
        return e;
    }

    if (!(id % colunas == (colunas-1))) {   // se nao for a ultima da linha
                                            // pode ler a direita

        e->rua_direita = lerRua();
    }

    if (!(id >= (nEsquinas - colunas))) {       // Se nao for a ultima linha
                                                // pode ler baixo

        e->rua_baixo = lerRua();
    }
    
    e->esq_direita = NULL;
    e->esq_baixo= NULL;

    return e;
}

int linkarEsquinas(t_esquina** bairro, int nEsquinas, int colunas) {


    for (int i = 0; i < nEsquinas; i++) {

        if (i == (nEsquinas - 1)) {         // ultimo, não linka nada
            return 1;
        }

        // ! ultima linha
        if (i < (nEsquinas - 1 - colunas))
            bairro[i]->esq_baixo = bairro[i+colunas];
        
        // ! ultima coluna
        if (!(i % colunas == (colunas-1)))
            bairro[i]->esq_direita = bairro[i+1];   

    }

}

void ExchangeCharacters(char* str, int p1, int p2) {
    char tmp;
    tmp = str[p1];
    str[p1] = str[p2];
    str[p2] = tmp;
}

int testarCaminho(char* aux, t_esquina** bairro, int len) {
    int x = 0;

    t_apontador e = bairro[0];


    for (int i = 0; i < len; i++) {
        if (aux[i] == '1') {
            x += e->rua_direita.amigos;
            e = e->esq_direita;
        }
        else if (aux[i] == '0') {
            x +=  e->rua_baixo.amigos;
            e = e->esq_baixo;
        }
    }

    return x;

}

void RecursivePermute(char* str, int k, t_esquina** bairro, int* x, int nCaminho, int *dinamica) {
    int i, len;
    int teste = 0;
    len = strlen(str);

    if (k == len) {
        // ! se ja fiz o teste com esse str

        if ( )
        teste = testarCaminho(str, bairro, nCaminho);
        if (teste > *x)
            *x = teste;
    }

    else {
        for (i = k; i < len; i++) {
            ExchangeCharacters(str, k, i);
            RecursivePermute(str, k + 1, bairro, x, nCaminho, dinamica);
            ExchangeCharacters(str, i, k);
        }
    }
}

void inicializarVetor(int n, int *v) {

    for (int i = 0; i < n; i++) 
        v[i] = 0;

}

int main() {
    int linhas, colunas;
    int nEsquinas;
    char *vaux;
    int x = 0;
    int nCaminho;
    int* dinamica;

    scanf("%d%d", &linhas, &colunas);

    nEsquinas = linhas * colunas;

    nCaminho = linhas + colunas -2;

    dinamica = (int*) malloc(nCaminho * sizeof(int));

    t_esquina** bairro = (t_esquina**) malloc(nEsquinas * sizeof(t_esquina*));
    t_esquina* auxiliar;

    for (int i = 0; i < nEsquinas; i++) {
        auxiliar = criaEsquina(i, colunas, nEsquinas);
        bairro[i] = auxiliar;
    }

    inicializarVetor(nCaminho, auxiliar);

    linkarEsquinas(bairro, nEsquinas, colunas);
    
    vaux = (char*) malloc(nCaminho * sizeof(char));

    for (int i = 0; i < (colunas-1); i++) {
        vaux[i] = '1';
    }
    
    for (int i = (colunas-1); i < nCaminho; i++) {
        vaux[i] = '0';
    }

    // corrigir erro
    vaux[nCaminho] = '\0';

    
    RecursivePermute(vaux, 0, bairro, &x, nCaminho, dinamica);
    
    printf("%d\n", x);

}