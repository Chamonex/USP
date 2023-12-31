
// typedef struct {
//     float valor;
//     char* devedor;
//     char* credor;
//     int status;
// } divida;

// typedef struct {
//     divida* dividas;
// } lista;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "split.h"

void prompt() {
    printf("---- PRIMO'S SPLIT ----\n");
    printf(" adicionar divida - 1\n");
    printf(" consultar dividas - 2\n");
    printf(" mudar de conta - 3\n");
    printf(" sair - 0\n");
}


int buscar_conta(char *nome, user **lista) {

    for (int i = 0; i < 4; i++) {
        
        if (strcmp(nome, lista[i]->nome) == 0)
            return i;

    }

    return ERROR;

}

int logar(user **lista) {
    
    char *nome;
    int index;

    // nome com, no máximo 20 caracteres
    nome = (char*) malloc(20 * sizeof(char));

    printf("em qual conta quer logar?\n");
    gets(nome);

    index = buscar_conta(nome, lista);
    
    if (index == ERROR) {
        printf("este usuario nao existe\n");
        return ERROR;
    }

    printf("logado como %s\n", lista[index]->nome);
    return index;
}

int add_divida(user** lista_users, int user_index) {
    // lista -> ponteiro para lista de users

    int opt, user2_index = -1;
    float valor;
    char *user2;

    printf(" - divida [0]\n - credito [1]\n");
    scanf("%d", &opt);

    printf("valor: ");
    scanf("%f", &valor);

    
    if (!opt) {
        printf("para quem deve?\n");
        valor -= (valor*2);
    }

    else
        printf("quem lhe deve?\n");
    
    getchar();
    gets(user2);

    user2_index = buscar_conta(user2, lista_users);
    if (user2_index == ERROR) {
        printf("essa conta nao existe!\n");
        return ERROR;
    }
    
    lista_users[user2_index]->saldo -= valor;
    lista_users[user_index]->saldo += valor;    

    return 1;
}

void print_lista(user* lista) {
    printf("\n\n--------------------\n");
    for (int i = 0; i < 4; i++) {
        printf("%s\n", lista[i].nome);
        printf("%d\n", lista[i].saldo);
        printf("--------------------\n\n");
    }
}
