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

typedef struct {
    Vertex v;
    Vertex w; 
    int weight;
} Aresta;

Graph* initGraph(int);
Graph* initGraph(int);
int insertArc(Graph*, Vertex, Vertex, int);
int insertEdge(Graph*, Vertex, Vertex, int);
int removeArc(Graph*, Vertex, Vertex);
int removeEdge(Graph*, Vertex, Vertex);
void printGraph(Graph*);
static Vertex** generateAdj(int);
Aresta encontrarMenorPeso(Graph*);


Graph* initGraph(int V) {
    
    Graph *G = malloc(sizeof(*G));
    G->nVertices = V;
    G->nArcos = 0;
    G-> adj = generateAdj(G->nVertices);
    return G;
}


// função que cria uma matriz quadratica
static Vertex** generateAdj(int V) {
    
    int i, j;
    Vertex** m = malloc(V * sizeof(int*));

    for (i = 0; i < V; i++) {
        m[i] = malloc(V * sizeof(int));
        for (j = 0; j < V; j++)
            m[i][j] = 0;    // inicia sem nenhuma ligação
    }

    return m;

}


// insere um novo arco no grafo
int insertArc(Graph *G, Vertex v, Vertex w, int weight) {
    if (G->adj[v][w] == 0) {
        G->adj[v][w] = weight;
        G->nArcos++;

        return SUCCESS;
    }
    else {
        printf("The vertex %d - %d already exist, with weiht = %d\n", v, w, G->adj[v][w]);
        return ERROR;
    }
}


int insertEdge(Graph *G, Vertex v, Vertex w, int weight){
    
    if(insertArc(G, v, w, weight) == 1) {
        if (insertArc(G, w, v, weight) == 1) {
            return SUCCESS;
        }
    }
    return ERROR;

}


// remove um arco do grafo
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


// escreve o grafo atual na tela
void printGraph(Graph *G) {
    
    for (int i = 0; i < G->nVertices; i++) {
        for (int j = 0; j < G->nVertices; j++) {
            printf("%d ", G->adj[i][j]);
        }
        printf("\n");
    }
}


// EXERCICIOS:

// encontre a aresta de menor peso em um grafo
Aresta encontrarMenorPeso(Graph *G) {
    int i, j;
    Aresta menor;
    menor.weight = 9999;

    for (i = 0; i < G->nVertices; i++) {
        
        for (j = 0; j < G->nVertices; j++) {
            if ((G->adj[i][j] > 0) && (G->adj[i][j] < menor.weight)) {
                menor.v = i;
                menor.w = j;
                menor.weight = G->adj[i][j];
            }
        }
    }

    return menor;
}

// encontre a aresta de MAIOR peso em um grafo
Aresta encontrarMaiorPeso(Graph *G) {
    int i, j;
    Aresta maior;
    maior.weight = 0;

    for (i = 0; i < G->nVertices; i++) {
        
        for (j = 0; j < G->nVertices; j++) {
            if (G->adj[i][j] > maior.weight) {
                maior.v = i;
                maior.w = j;
                maior.weight = G->adj[i][j];
            }
        }
    }

    return maior;
}