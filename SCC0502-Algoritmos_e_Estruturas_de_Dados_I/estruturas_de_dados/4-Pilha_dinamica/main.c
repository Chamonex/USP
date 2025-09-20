#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {

    t_pilha p;
    inicializar(&p);

    t_elemento e1;
    e1.chave = 1;
    t_elemento e2;
    e2.chave = 2;
    t_elemento e3;
    e3.chave = 3;
    
    push(e1, &p);
    
    imprimir(p);

    push(e2, &p);
    push(e3, &p);

    imprimir(p);

    pop(&p);

    imprimir(p);
    
    return 0;

}