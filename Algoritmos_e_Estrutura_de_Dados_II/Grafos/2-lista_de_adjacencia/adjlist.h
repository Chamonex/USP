/*
    utilização de uma matriz binária para representar a conecção entre os vértices.
    n vértices == matriz nXn
*/

#include <stdio.h>
#include <stdlib.h>

#define Vertex int
#define ERROR 0
#define SUCCESS 1
 
typedef struct {
    int nVertices;  // quantidade de vértices
    int nArcos;     // quantidade de arcos
    Vertex** adj;   // matriz de Vertex
} Graph;

Graph* initGraph(int);
Graph* initGraph(int);
int insertArc(Graph*, Vertex, Vertex);
int insertEdge(Graph*, Vertex, Vertex);
int removeArc(Graph*, Vertex, Vertex);
int removeEdge(Graph*, Vertex, Vertex);
void printGraph(Graph*);


static Vertex** generateAdj(int V) {
    
    int i, j;
    Vertex** m = malloc(V * sizeof(int*));

    for (i = 0; i < V; i++) {
        m[i] = malloc(V * sizeof(int));
        for (j = 0; j < V; j++)
            m[i][j] = 0;
    }

    return m;

}



Graph* initGraph(int V) {
    
    Graph *G = malloc(sizeof(*G));
    G->nVertices = V;
    G->nArcos = 0;
    G-> adj = generateAdj(G->nVertices);
    return G;
}

// função que cria uma matriz quadratica

int insertArc(Graph *G, Vertex v, Vertex w) {
    if (G->adj[v][w] == 0) {
        G->adj[v][w] = 1;
        G->nArcos++;

        return SUCCESS;
    }
    else {
        printf("The vertex %d - %d already exist\n", v, w);
        return ERROR;
    }
}

int insertEdge(Graph *G, Vertex v, Vertex w){
    
    if(insertArc(G, v, w) == 1) {
        if (insertArc(G, w, v) == 1) {
            return SUCCESS;
        }
    }
    return ERROR;

}

int removeArc(Graph *G, Vertex v, Vertex w) {
    if (G->adj[v][w] == SUCCESS) {
        G->adj[v][w] = 0;
        G->nArcos--;
        
        return SUCCESS;
    }
    else {
        printf("\nThe vertex %d-%d no longer exists\n", v, w);
        return ERROR;
    }
}

int removeEdge(Graph *G, Vertex v, Vertex w) {
    if (removeArc(G, v, w) == SUCCESS) {
        if (removeArc(G, w, v) == SUCCESS) {
            return SUCCESS;
        }
    }
    return ERROR;
}

void printGraph(Graph *G) {
    
    for (int i = 0; i < G->nVertices; i++) {
        for (int j = 0; j < G->nVertices; j++) {
            printf("%d ", G->adj[i][j]);
        }
        printf("\n");
    }
}

