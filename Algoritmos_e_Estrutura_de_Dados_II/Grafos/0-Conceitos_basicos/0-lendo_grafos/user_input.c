#include <stdio.h>

int main() {

    int n;  // numero de vertices
    
    char x[20], y[20];  // pares de arestas
    // ex: [a, b] é uma aresta que liga o vértice a ao vertice b

    printf("Numero de vertices: ");
    scanf("%d", &n);

    printf("Digite os pares de arestas relacionadas aos %d vertices.\nDigite -1 para terminar.\n", n);

    /*
        - o scanf retorna o número de itens que foram lidos.
        - %[^-1]  leia uma sequencia de caracteres até encontrar o caractere '-1'
                  como tem o '^', o caractere -1 não deve ser lido.
        - assim, o scanf não retornara 2 e o while encerrará.
        - %20s, devem ser lidos até 20 ítens.
    */
    while (scanf("%[^-1]20s %20s", &x, &y) == 2) {
        print("Aresta: %s %s\n", x, y);
    }
    printf("fim.");
    return 0;
}