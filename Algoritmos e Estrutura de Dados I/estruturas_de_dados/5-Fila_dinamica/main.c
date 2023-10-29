#include <stdio.h>
#include "fila.h"

int main() {


    t_fila f;
    inicializar(&f);

    t_elemento e1;
    e1.chave = 1;
    t_elemento e2;
    e2.chave = 2;
    t_elemento e3;
    e3.chave = 3;

    inserir(e1, &f);
    inserir(e2, &f);
    inserir(e3, &f);

    printar(&f);

    remover(&f);

    printar(&f);

    remover(&f);

    printar(&f);

    inserir(e1, &f);

    printar(&f);

    remover(&f);
    remover(&f);
    remover(&f);

    return 0;
}