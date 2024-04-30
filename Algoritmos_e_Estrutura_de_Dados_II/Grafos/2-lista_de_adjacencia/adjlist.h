/*
    cada vértice do grafo possui uma lista encadeada.
    A lista associada com um vértice v contém todos os 
    vizinhos de v.
    Por exemplo, eis o vetor de listas de adjacência do
    grafo cujos arcos são  0-1 0-5 1-0 1-5 2-4 3-1 5-3 :

        0: 5 1
        1: 5 0
        2: 4
        3: 1
        4:  
        5: 3
*/


#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define SUCCESS 1
#define Vertex int

// um Grafo é um ponteiro para a estrutura grafo
typedef struct graph *Graph;
// um Link é um ponteiro para um Node
typedef struct Node *Link;

struct Node {
    Vertex w;   // vizinho de v
    int weight;
    Link next;
};

struct graph {
    int nVertices;
    int nArcos;
    Link* adj;      // ponteiro para um vetor de listas de adjacencia
};

Graph initGrapg(int);
int insertArc(Graph, Vertex, Vertex, int);
int insertEdge(Graph, Vertex, Vertex, int);
static Link createNode(Vertex, Link, int);
int removeArc(Graph, Vertex, Vertex);
int removeEdge(Graph, Vertex, Vertex);
void printGraph(Graph);


// constrói um grafo com vértices 0 1 ... v-1
Graph initGrapg(int v) {
    Graph G = malloc(sizeof(*G));
    G->nVertices = v;
    G->nArcos = 0;
    G->adj = malloc (v * sizeof(Link));
    for(int i = 0; i < v; i++) {
        G->adj[i] = NULL;   // pois ainda não há arcos.
    }
    return G;
}

int insertArc(Graph G, Vertex v, Vertex w, int weight) {
    for (Link a = G->adj[v]; a != NULL; a = a->next) {
        if (a->w == w) {
            printf("This Arc already exists!\n");
            return ERROR;
        }
    }
    G->adj[v] = createNode(w, G->adj[v], weight); // vai para o inicio da lista
    G->nArcos++;
    return SUCCESS;
}

int insertEdge(Graph G, Vertex v, Vertex w, int weight) {
    if (insertArc(G, v, w, weight) == SUCCESS) {
        if (insertArc(G, w, v, weight) == SUCCESS)
            return SUCCESS;
    }
    return ERROR;
}

static Link createNode(Vertex w, Link next, int weight) {
    Link a = malloc(sizeof(*a));
    a->w = w;
    a->next = next;
    a->weight = weight;
    return a;
}

int removeArc(Graph G, Vertex v, Vertex w) {
    if (v > G->nVertices)
        return ERROR;

    for (Link a = G->adj[v]; a != NULL; a = a->next) {
        if (a->next->w = w) {
            // como dar um free? 
            a->next = a->next->next;
            G->nArcos--;
            return SUCCESS;
        }
    }
    return ERROR;
}

int removeEdge(Graph G, Vertex v, Vertex w) {
    if(removeArc(G, v, w) == SUCCESS) {
        if (removeArc(G, w, v) == SUCCESS)
            return SUCCESS;
    }
    return ERROR;
}

void printGraph(Graph G) {
  printf("Graph, %d vertex and %d arcs\n", G->nVertices, G->nArcos);
  for (int i = 0; i < G->nVertices; i++) {
    printf("Vertex %d: ", i);
    for (Link p = G->adj[i]; p != NULL; p = p->next) {
      printf(" %d (%d) %d / ", i, p->weight, p->w);
    }
    printf("\n");
  }
  printf("\n\n");
}



// EXERCÍCIOS:

/* 
    Implemente uma função que encontre o vértice adjacente a um vértice x com
    aresta de menor peso em um grafo direcionado valorado, representado como
    listas de adjacências.
*/

    Vertex menorPesoAdj(Graph G, Vertex x) {
        Link p;
        int peso = 99999;
        Vertex vertex;

        for (p = G->adj[x]; p != NULL; p = p->next) {
            if (p->weight < peso) {
                peso = p->weight;
                vertex = p->w;
            }
        }

        return vertex;
    }
