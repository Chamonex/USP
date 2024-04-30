#include <stdio.h>
#include "adjlist.h"



void main() {

    Graph G;
    G = initGraph(5);           // tenho os vértices 0, 1, 2 e 3
    printGraph(G);
    insertArc(G, 0, 1, 0);
    insertArc(G, 1, 2, 0);
    insertArc(G, 2, 3, 0);
    insertArc(G, 2, 4, 0);
    printGraph(G);
    startDFS(G, 0);
    
    
}