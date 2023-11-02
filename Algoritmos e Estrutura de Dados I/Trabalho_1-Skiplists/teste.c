#include <stdlib.h>
#include <stdio.h>


int obterChave(char nome[]) {
    int c = nome[0];
    int cont = 1;
    int chave = 0;

    // funciona somente para letras minusculas
    while (c > 96 && c < 123) {
        chave += (c-96) * cont;
        cont++;
        c = nome[cont-1];
    }

    return chave;    
}


void main() {

    char nome[] = "pedro";
    int chave = obterChave(nome);
    printf("%d", chave);
}
