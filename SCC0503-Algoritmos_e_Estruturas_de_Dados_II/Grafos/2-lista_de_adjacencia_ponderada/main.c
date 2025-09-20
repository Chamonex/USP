#include <stdio.h>
#include "adjlist.h"

void main() {

    Graph G;
    G = initGrapg(4);
    insertArc(G, 1, 2, 4);
    printGraph(G);
    
}