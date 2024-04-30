#include <stdio.h>
#include "adjlist.h"

void main() {

    Graph G;
    G = initGrapg(4);
    printGraph(G);
    insertArc(G, 1, 0, 4);
    insertArc(G, 1, 2, 1);
    insertArc(G, 1, 3, 3);
    printGraph(G);

    Vertex menorPeso = menorPesoAdj(G, 1);
    printf("o vertice adjacente a 0, com menor peso e %d\n", menorPeso);
    
}