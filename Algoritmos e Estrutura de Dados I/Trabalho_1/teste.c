#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void main() {

    char entrada[42];
    char *atual;
    char opt;
    char nome[20];
    char tel[20];
    int len;
    int cont = 0;   // 0 = opt
                    // 1 = nome
                    // 2 = tel


    // RECEBER ENTRADA
    fgets(entrada, sizeof(entrada), stdin);

    len = strlen(entrada);
    if (entrada[len - 1] == '\n')
        entrada[len - 1] = '\0';


    // REPARTIR ENTRADA
    atual = strtok(entrada, " ");

    while (atual != NULL) {

        if (cont == 0) {
            printf("OPCAO\n");
            opt = atual[0];
            
        }

        if (cont == 1) {
            printf("NOME\n");
            len = strlen(atual);
            printf("len nome = %d", len);
            for (int i = 0; i < len; i++) {
                nome[i] = atual[i];
            }
        }

        if (cont == 2) {
            len = strlen(atual);
            for (int i = 0; i < len; i++) {
                tel[i] = atual[i];
            }
        }


        atual = strtok(NULL, " ");
        cont++;
    }

    
    
}