#include <stdio.h>
#include <string.h>
#include "SkipList.h"

void main() {

    SkipList *l = criaSkipList(10, 0.5);
    char opt = 'a';
    char nome[20];
    char entrada[42];
    char *atual;
    char tel[20];
    int cont = 0;
    int len;
    
    
    while(opt != '0') {

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
    
        // FUNÇÕES   
        switch (opt)
        {
        case 'I':
            
            fgets(nome, sizeof(nome), stdin);
            len = strlen(nome);

            if (nome[len - 1] == '\n')
                nome[len - 1] = '\0';

            scanf("%d", &tel);
            getchar();
            insereSkipList(l, nome, tel);

            break;
        
        case 'P':
            fgets(nome, sizeof(nome), stdin);
            len = strlen(nome);

            if (nome[len - 1] == '\n')
                nome[len - 1] = '\0';

            buscaSkipList(l, nome);
            break;

        case 'R':
            fgets(nome, sizeof(nome), stdin);
            len = strlen(nome);

            if (nome[len - 1] == '\n')
                nome[len - 1] = '\0';

            removeSkipList(l, nome);
            
            break;

        case 'A':
            
            fgets(nome, sizeof(nome), stdin);
            len = strlen(nome);

            if (nome[len - 1] == '\n')
                nome[len - 1] = '\0';

            scanf("%d", &tel);
            getchar();
            alteraSkiplist(l, nome, tel);
            
            break;
        
        case '0':
            liberaSkipList(l);
            break;

        default:
            break;
        }
    }

}