#include "arclist.h"
#include <stdio.h>

int main() {
    int x, y;
    int n;
    Graph G;


    if (scanf("%d\n", &n) == 1) {
        G = initGraph();
        while (scanf("%d %d\n", &x, &y) != EOF) {
            insertArc(G, x, y);
        }
    }

    printGraph(G);
    printf("removing 1 -- 4\n");
    removeArc(G, 1, 4);
    printGraph(G);
    printf("add 1-- 3");
    insertArc(G, 1, 3);
    printGraph(G);

    destroyGraph(G);

    return 0;

}