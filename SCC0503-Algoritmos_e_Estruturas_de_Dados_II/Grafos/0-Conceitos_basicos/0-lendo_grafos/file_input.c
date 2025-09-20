#include <stdio.h>

int main() {
    int n, x, y;

    if(scanf("%d\n", &n) == 1) {    // por que o \n no input??
        printf("Vertices: %d\n", n);

        // EOF = end of file.
        // ler até acabar o arquivo de input.
        while (scanf("%d %d\n", &x, &y) != EOF) {
            printf("Aresta: %d %d\n", x, y);
        }
    }

    printf("fim");
    return 0;
}