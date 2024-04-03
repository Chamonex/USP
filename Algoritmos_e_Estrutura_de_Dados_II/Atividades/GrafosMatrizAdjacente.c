#include <stdio.h>
#include <stdlib.h>

// Graph initGraph();
// destroyGraph(Graph); 
// insertArc(Graph, Arc); 
// removeArc(Graph, Arc);
// printGraph(Graph);

typedef struct {
    int size;
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

    Grafo g = (Grafo) malloc(sizeof(Matriz*));
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

    return g;
}

void destroyGraph(Grafo g) {
    int i, j;

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

void printGraph(Grafo g) {

    for (int i = 0; i < g->size; i++) {

        for (int j = 0; j < g->size; j++) {

            printf("%d ", g->m[i][j]);

        }
        printf("\n");
    }
}


void final(Grafo g) {
    int i, j;
    int first = 1;

    // Total of vertices: 6, total of arcs: 7
    // Vertex 0, arcs: 1, 2
    // Vertex 1, arcs: 0, 4
    // Vertex 2, arcs: 0, 3, 4, 5
    // Vertex 3, arcs: 2, 5
    // Vertex 4, arcs: 1, 2
    // Vertex 5, arcs: 2, 3

    printf("Total of vertices: %d, total of arcs: %d\n", g->size, g->nArc);
    
    
    for (i = 0; i < g->size; i++) {
        printf("Vertex %d, arcs: ", i);
        for (j = 0; j < g->size; j++) {
            if (g->m[i][j] == 1) {
                
                if (first == 1) {
                    printf("%d", j);
                    first = 0;
                }
                else {
                    printf(", %d", j);
                }

            }
        }
        first = 1;
        printf("\n");
    }


}

int main() {

    int n, x, y;
    scanf("%d", &n);
    Grafo g = initGraph(n);
    Arco a;
    while (scanf("%d %d\n", &a.x, &a.y) != EOF) {
        insertArc(g, a);
    }

    final(g);
}
