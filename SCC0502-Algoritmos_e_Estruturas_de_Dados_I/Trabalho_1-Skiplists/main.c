#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "skiplist.h"

void main() {
    
    char opt;
    t_skiplist *l = inicializar(10, 0.5);


    while (1) {

        scanf("%c", &opt);
        getchar();
        char nome[20];
        int novo_tel;
        int tel;

        
        switch (opt)
        {
        case 'I':
            inserir(l);
            
            printf("a"); 
            break;

        case 'P':

            pesquisar(l);
            break;
        
        case'A':

            gets(nome);
            scanf("%d", &novo_tel);
            alterar(l, nome, novo_tel); 
            break;
        
        case 'R':
            gets(nome);

            remover(l, nome); 
            break;
        
        case '0':
            return;

        default:
            break;
        }
    }

}