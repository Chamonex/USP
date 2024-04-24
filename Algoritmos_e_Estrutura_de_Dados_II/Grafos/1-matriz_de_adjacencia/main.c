#include <stdio.h>
#include "adjmatrix.h"

int main() {

    Graph *G = initGraph(6);
    printGraph(G);
    insertEdge(G, 1, 2);
    printf("\n\n\n");
    printGraph(G);
    printf("\n\n\n");
    insertArc(G, 4, 5);
    printGraph(G);
    removeEdge(G, 1, 2);
    removeArc(G, 0, 3);
    
    return 0;
}