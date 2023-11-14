/*
    Começa assumindo que tenho 1 carta em ordem.
    Ponho a segunda carta
    Agora tenho 2 cartas ordenadas.

    Faço isso do maior para o menor.
        - ele é menor que o índie 3 ?   Sim
        - ja arreda para o indice 3 e pergunta para o 2
*/



#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *c) {
    int aux;
    aux = *c;
    *c = *a;
    *a = aux;
}


int main() {

    int *v, n;
    int save, cont, c, a;       // a = analizando;  c = comparando

    scanf("%d", &n);
    v = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    for (cont = 0; cont < n; cont++)
        printf("%d ", v[cont]);

    for (a = n-1; a > 0; a--) {
        save = a;
        for (c = a-1; c >= 0; c-- ){
            if (v[a] < v[c]) {
                troca(&v[a], &v[c]);
                a--;
                printf("\n");
            }
        }
        a = save;
    }

    return 0;
}