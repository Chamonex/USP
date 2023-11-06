#include <stdio.h>
#include <string.h>
#include "SkipList.h"

void main() {

    SkipList *l = criaSkipList(10, 0.5);
    char opt = 'a';
    char nome[20];
    int tel;
    
    while(opt != '0') {
        opt = getchar();
        getchar();

        switch (opt)
        {
        case 'I':
            
            gets(nome);
            scanf("%d", &tel);
            getchar();
            insereSkipList(l, nome, tel);

            break;
        
        case 'P':
            gets(nome);
            buscaSkipList(l, nome);
            break;

        case 'R':
            gets(nome);
            removeSkipList(l, nome);
            
            break;

        case 'A':
            
            gets(nome);
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