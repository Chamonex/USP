#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

// Graph initGraph();
// destroyGraph(Graph); 
// insertArc(Graph, Arc); 
// removeArc(Graph, Arc);
// printGraph(Graph);


typedef struct {
    int size;   // numero vertices
    int* visitado;
    int **m;
    int nArc;   // numero arcos
} Matriz;

typedef struct {
    int x;
    int y;
} Arco;

typedef Matriz* Grafo;


Grafo initGraph(int n) {
    int i, j;

    Grafo g = malloc(sizeof(Matriz));
    g->size = n;
    g->nArc = 0;
    g->m = (int **) malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
        g->m[i] = (int *) malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            g->m[i][j] = 0;
        }
    }

    g->visitado = (int*) malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        g->visitado[i] = 0;

    return g;
}

void destroyGraph(Grafo g) {
    int i;

    for (i = 0; i < g->size; i++) {
        free(g->m[i]);    
    }
}

void insertArc(Grafo g, Arco a) {
    g->m[a.x][a.y] = 1;
    g->m[a.y][a.x] = 1;
    g->nArc++;
}

 
void removeArc(Grafo g, Arco a) {
    g->m[a.x][a.y] = 0;
    g->m[a.y][a.x] = 0;
    g->nArc--;
}



void DFS(Grafo g, int v) {

    int i;

    printf("visited %d\n", v);
    g->visitado[v] = 1;

    // encontrar os adjacentes de v;
    for (i = 0; i < g->size; i++) {
        if(g->m[v][i] != 0) {   // tem um adjacente
            if (g->visitado[i] == 0) { // ainda nao foi visitado
                DFS(g, i);
            }
        }
    }

}


void BSF(Grafo g, int v) {

    int i;
    t_fila fila;
    inicializar(&fila);

    inserir(v, &fila);

    while (vazia(fila) != VAZIA) {
        // enquanto a fila não fica vazai:

        int prox = remover(&fila);
        if (g->visitado[prox] == 0) {

            printf("visited %d\n", prox);
            g->visitado[prox] = 1;
            for (i = 0; i < g->size; i++) {
                if (g->m[prox][i] != 0) {
                    if (g->visitado[i] == 0) {
                        inserir(i, &fila);
                    }
                }
            }
        }
    }
}



int main() {

    int n;
    scanf("%d", &n);
    Grafo g = initGraph(n);
    Arco a;
    while (scanf("%d %d\n", &a.x, &a.y) != EOF) {
        insertArc(g, a);
    }


    printf("DFS\n");
    DFS(g, 0);

    for (int i = 0; i < g->size; i++)
        g->visitado[i] = 0;

    printf("BFS\n");
    BSF(g, 0);

    destroyGraph(g);
    return 0;

}
