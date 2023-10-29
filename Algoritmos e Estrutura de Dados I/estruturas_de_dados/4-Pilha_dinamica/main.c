#include <stdio.h>
#include "pilha.h"

int main() {

    t_pilha p;
    inicializar(&p);

    push(20, &p);
    push(30, &p);
    push(40, &p);

    while(p.topo >= 0)
        printf("%d\n", pop(&p));
    
    printf("%d\n", pop(&p));

    for (int i = 0; i <= MAX+1; i++) {
        printf("%d\n", push(i, &p));
    }


    return 0;
}