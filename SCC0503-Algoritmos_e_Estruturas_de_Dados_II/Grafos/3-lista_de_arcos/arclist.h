#include <stdio.h>
#include <stdlib.h>

#define Vertex int  // um vertice é somente um inteiro


typedef struct {
// um arco é formado de dois vertices somente.
    Vertex v;
    Vertex w;
} Arc;

// uma lista de arcos contém o número
// de arcos e um array de arcos (ponteiro)
struct Arclist {
    int size;
    Arc *arcs;
};

// um grafo é um ponteiro para uma arclist;
typedef struct Arclist *Graph;

// arco é para dígrafos e arestas para grafos
#define Edge Arc    


Graph initGraph() {
    Graph G = (Graph) malloc(sizeof(*G)); // sizeof do CONTEUDO QUE CABE EM G (arclist);
                                          // poderia substituir por malloc(sizeof(arclist));
    G->size = 0;    // o Grafo inicializa fazio;
    G->arcs = NULL; // o ponteiro de arcos aponta para NULL.
    return G;
}


Arc newArc(Vertex v, Vertex w) {
    Arc e;          // função que retorna um arco com os
    e.v = v;        // vértices passados.
    e.w = w;
    return e;
}

void destroyGraph(Graph G) {
    // lembrando que G é um ponteiro para arclist
    free(G->arcs);
    G->size = 0;
}

void insertArc(Graph G, Vertex v, Vertex w) {
    // checando se já não tem um arco igual:
    int i;
    for(i = 0; i < G->size; i++) {
        if ((G->arcs[i].v == v) && (G->arcs[i].w == w)) {
            // este arco já existe
            return;
        }
    }
    Arc newa =  newArc(v, w);
    G->size++;  // incrementando o contador de arcos
    G->arcs = (Arc*) realloc(G->arcs, G->size * sizeof(Arc));   // aumentando o espaço da lista de arcos                                                            // isso não altera o conteúdo já existente na memoria.
    G->arcs[G->size -1] = newa;
}

void insertEdge(Graph G, Vertex v, Vertex w) {
    insertArc(G, v, w);
    insertArc(G, w, v);
}

void removeArc(Graph G, Vertex v, Vertex w) {
    int i;
    for (i = 0; i < G->size; i++) {
        if (G->arcs[i].v == v && G->arcs[i].w == w) {
            // encontrou o grafo que quer remover
            G->arcs[i] = G->arcs[G->size -1];
            G->size--;
            return;
        }
    }
}


void printGraph(Graph G) {
  for (int i = 0; i < (G->size); i++) {
    printf("(%d -- %d)\n", G->arcs[i].v, G->arcs[i].w);
  }
}
