/*
    utilização de uma matriz binária para representar a conecção entre os vértices.
    n vértices == matriz nXn
*/

#include <stdio.h>
#include <stdlib.h>

#define Vertex int  // um Vertex é um int

typedef struct Node *Link;  // o tipo link é um ponteiro 
                            // para um node!
// nó da lista de adjacencia
struct Node {
    Vertex w;  
    Link next;  // aponta para  próximo nó
};

struct Graph {
    int nVertices;  // quantidade de vértices
    int nArcos;     // quantidade de arcos
    Link *adj;      // ponteiro para array de vertices
                    // acaba se tornando uma matriz de
                    // nodes (matriz de adjacência)
};

typedef struct Graph *Digraph;
#define Graph Digraph   // o grafo também é um dígrafo.

Graph initGraph(int nV) {
    // recebe o número de vértices
    Graph G = (Graph) malloc(sizeof(*G));
    G->nVertices = nV;
    G->nArcos = 0;
    G->adj = (Link*) malloc(nV * sizeof(Link*)); // matriz de Nodes

    for (int i = 0; i < nV; i++) {
        G->adj[i] = NULL;
    }
}

