#include <stdio.h>
#include <string.h>
#include "SkipList.h"
#include <stdlib.h>
#include <time.h>

void imprimeSkipList(SkipList *sk){
    if(sk == NULL)
        return;
    int i;
	printf("\n*****Skip List*****\n");
	for(i=0; i <= sk->nivel; i++){
		struct NO *no = sk->inicio->prox[i];
		printf("Nivel %d: ",i);
		while(no != NULL){
			printf("%d ",no->chave);
            printf("%s ", no->nome);
            printf("%s ", no->tel);
			no = no->prox[i];
		}
		printf("\n");
	}
}

void main() {

    srand((unsigned)time(0));

    SkipList *l = criaSkipList(15, 0.5);
    char opt = 'a';
    char nome[20];
    char entrada[42];
    char *atual;
    char tel[20];
    int cont = 0;
    int len;
    
    
    while(opt != '0') {

        for (int i = 0; i < 20; i++) {
            nome[i] = '\0';
        }
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




        // FUNÇÕES   
        switch (opt) {
            case 'I':

                // tratamento de erro §@
                len = strlen(tel);
                for (int i = len-1; i >= 0; i--) {
                    if (tel[i] < 48 || tel[i] > 57) {
                        tel[i] = '\0';
                    }
                }

                insereSkipList(l, nome, tel);

                break;
            
            case 'P':
                buscaSkipList(l, nome);
                
                break;

            case 'R':
                removeSkipList(l, nome);
                
                break;

            case 'A':
                // tratamento de erro §@
                len = strlen(tel);
                for (int i = len-1; i >= 0; i--) {
                    if (tel[i] < 48 || tel[i] > 57) {
                        tel[i] = '\0';
                    }
                }
                alteraSkiplist(l, nome, tel);
                
                break;
            
            case 'C':
                imprimeSkipList(l);

                break;
            
            case 'L':
                liberaSkipList(l);

                break;
            
            case '0':
                liberaSkipList(l);

            default:
                break;
        }
    }
    
}
