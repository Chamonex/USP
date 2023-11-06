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
    char telaux[20];
    int cont = 0;
    int len;
    
    
    while(opt != '0') {

    // RECEBER ENTRADA
    fgets(entrada, sizeof(entrada), stdin);

    len = strlen(entrada);
    if (entrada[len - 1] == '\n')
        entrada[len - 1] = '\0';

        // REPARTIR ENTRADA
        atual = strtok(entrada, " ");

        while (atual != NULL) {
            if (cont == 0) {
                opt = atual[0];
            }

            if (cont == 1) {
                len = strlen(atual);
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
        cont = 0;


        // tratamento de erro §@
        len = strlen(tel);
        for (int i = len-1; i >= 0; i--) {
            if (tel[i] < 48 || tel[i] > 57) {
                tel[i] = '\0';
            }
        }

        // FUNÇÕES   
        switch (opt)
        {
        case 'I':
            insereSkipList(l, nome, tel);

            break;
        
        case 'P':
            buscaSkipList(l, nome);
            
            break;

        case 'R':
            removeSkipList(l, nome);
            
            break;

        case 'A':
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