#include <stdio.h>
#include <stdlib.h>
#include "split.h"

void main() {
    
    user user_list[4];
    int conta;
    int opt = -1;

    user_list[0].saldo = 0;
    user_list[0].nome = "Brexa";
    
    user_list[1].saldo = 0;
    user_list[1].nome = "Duolingo";
    
    user_list[2].saldo = 0;
    user_list[2].nome = "Grana";
    
    user_list[3].saldo = 0;
    user_list[3].nome = "Pandeiras";

    conta = logar(&user_list);

    while (conta == ERROR)
        conta = logar(&user_list);

    while (opt != 0) {

        prompt();
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            add_divida(&user_list, conta);
            break;
        
        case 2:
            print_lista(user_list);
            break;
        
        default:
            printf("escolha uma opcao correta!\n");
            break;
        }

    }


}