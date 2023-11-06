#include <stdio.h>
#include <string.h>
#include "SkipList.h"

void main() {

    SkipList *l = criaSkipList(10, 0.5);
    char opt = 'a';
    char nome[20];
    int tel, len;
    
    while(opt != '0') {
        opt = getchar();
        getchar();

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