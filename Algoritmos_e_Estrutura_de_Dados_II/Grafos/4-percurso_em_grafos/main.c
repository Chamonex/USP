#include <stdio.h>
#include "adjlist.h"



void main() {

    Graph G;
    G = initGraph(5);           // tenho os vértices 0, 1, 2 e 3
    printGraph(G);
    insertArc(G, 0, 1, 1);
    insertArc(G, 1, 2, 2);
    insertArc(G, 1, 3, 3);
    insertArc(G, 3, 4, 4);
    printGraph(G);

    clearVisited(G);   
    printf("\nnewDFS:\n");
    newDFS(G, 0);    

    clearVisited(G);   
    printf("\nnewDFS (ITERATIVO):\n");
    newDFSiterativo(G);



    // RESTE COM CICLOS
    printf("\n\nUSANDO GRAFO COM CICLO\n\n");
    Graph G2;
    G2 = initGraph(3);
    insertArc(G2, 0, 1, 0);
    insertArc(G2, 1, 2, 0);
    insertArc(G2, 2, 1, 0);
    insertArc(G2, 1, 3, 0);
    clearVisited(G2);
    
    startBSF(G, 0);
}