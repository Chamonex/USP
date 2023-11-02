#include <stdio.h>
#include <stdlib.h>
#include "skiplist.h"

void main() {
    
    char opt = 'a';
    t_skiplist *l = inicializar(10, 0.5);


    while (opt != '0') {
        scanf("%c", &opt);
        getchar();
        char nome[20];
        int novo_tel;
        int tel;

        
        switch (opt)
        {
        case 'I':

            gets(nome);
            getchar();

            scanf("%d", &tel);
            getchar();

            inserir(l, nome, tel);
            break;

        case 'P':

            gets(nome);
            getchar();
            pesquisar(l, nome);
            break;
        
        case'A':

            gets(nome);
            getchar();

            scanf("%d", &novo_tel);
            getchar();

            alterar(l, nome, novo_tel); 
            break;
        
        case 'R':
            gets(nome);
            getchar();

            remover(l, nome); 
            break;

        }
    }

}