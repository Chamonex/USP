#include <stdio.h>
#include "adjmatrix.h"

int main() {

    Graph *G = initGraph(4);
    printGraph(G);
    printf("\n\n");
    insertArc(G, 0, 1, 2);
    insertArc(G, 1, 3, 5);
    insertArc(G, 3, 2, 1);
    printGraph(G);
    Aresta menor = encontrarMenorPeso(G);
    printf("a aresta de menor peso e:\n");
    printf("%d -> %d\n", menor.v, menor.w);
    printf("com o peso = %d\n", menor.weight);

    Aresta maior = encontrarMaiorPeso(G);
    printf("a aresta de maior peso e:\n");
    printf("%d -> %d\n", maior.v, maior.w);
    printf("com o peso = %d\n", maior.weight);
    
    return 0;
}