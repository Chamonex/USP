#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"

/*
    Exemplo de entrada
    4
    5 i 5 i 6 i 3 r 3 r 6
    6 i 1 i 2 r 1 i 3 r 2 r 3
    4 i 1 i 2 i 1 r 1
    7 i 3 i 5 i 7 r 3 r 5 i 4 r 4

    Saída esperada para o exemplo
    pilha
    fila
    indefinido
    impossivel
*/
void main() {

    int nTestes;
    t_pilha pilha;
    inicializar(&pilha);
    t_fila fila;
    inicializarF(&fila);
    int erro_f = 0;
    int erro_p = 0;

    scanf("%d", &nTestes);

    for (int i = 0; i < nTestes; i++) {
        int n;
        scanf("%d", &n);
        getchar();
        for (int j = 0; j < n; j++) {
            char opt;
            int chave;

            opt = getc(stdin);
            printf("%c\n", opt);
            scanf("%d", &chave);
            printf("%d\n", chave);
            getchar();
            
            switch (opt)
            {
            case 'i':
                inserir(chave, &fila);
                push(chave, &pilha);   
                break;
            
            case 'r':
                erro_f += remover(chave, &fila);
                erro_p += pop(chave, &pilha);
            
            default:
                break;
            }
        }

        if (erro_f != 0 && erro_p != 0)
            printf("impossivel\n");
        else if (erro_f != 0 && erro_p == 0)
            printf("pilha\n");
        else if (erro_f == 0 && erro_p != 0)
            printf("fila\n");
        else if (erro_f == 0 && erro_p == 0)
            printf("indefinido\n");

    }
}