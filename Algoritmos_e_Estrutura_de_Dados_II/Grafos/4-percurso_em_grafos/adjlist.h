#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define SUCCESS 1
#define Vertex int

typedef struct graph *Graph;
typedef struct Node *Link;

struct Node {
    Vertex w;       
    int weight;
    int visited;    // se já foi visitado pela busca
    Link next;
};

struct graph {
    int nVertices;
    int nArcos;
    Link* adj;      // ponteiro para um vetor de listas de adjacencia
};

Graph initGraph(int);
int insertArc(Graph, Vertex, Vertex, int);
int insertEdge(Graph, Vertex, Vertex, int);
static Link createNode(Vertex, int);
int removeArc(Graph, Vertex, Vertex);
int removeEdge(Graph, Vertex, Vertex);
void printGraph(Graph);

void DFS(Graph, Vertex);
static void clearVisited(Graph);
void startDFS(Graph, Vertex);

// constrói um grafo com vértices 0 1 ... v-1
Graph initGraph(int v) {
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
    if (G->adj[v] == NULL) {
        G->adj[v] = createNode(w, weight);
        G->nArcos++;
        return SUCCESS;
    }
    else {
        for(Link a = G->adj[v]; a != NULL; a = a->next) {
            if (a->next == NULL) {
                a->next = createNode(w, weight);
                G->nArcos++;
                return SUCCESS;
            }
        }
    }
    return SUCCESS;
}

int insertEdge(Graph G, Vertex v, Vertex w, int weight) {
    if (insertArc(G, v, w, weight) == SUCCESS) {
        if (insertArc(G, w, v, weight) == SUCCESS)
            return SUCCESS;
    }
    return ERROR;
}

static Link createNode(Vertex w, int weight) {
    Link a = malloc(sizeof(*a));
    a->w = w;
    a->visited = 0;     // começa como falso
    a->weight = weight;
    a->next = NULL;
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
      printf(" %d->%d / ", i, p->w);
    }
    printf("\n");
  }
}






//------------- DFS -----------//



void DFS(Graph G, Vertex x) {

    G->adj[x]->visited = 1;         // no inicial
    printf(">> DFS %d visitado\n", G->adj[x]->w);
    // percorrer os adjacentes a v
    for (Link p = G->adj[x]; p != NULL; p = p->next) {
        Vertex proximo = p->w;
        if (G->adj[proximo]->visited == 0) {
            DFS(G, proximo);
        }   
    }
}

static void clearVisited(Graph G) {
    for (int i = 0; i < G->nVertices; i++) {
        if (G->adj[i] != NULL)
            G->adj[i]->visited = 0;
    }
}

void startDFS(Graph G, Vertex x) {
    printf("DFS\n");
    clearVisited(G);
    DFS(G, x);
}

