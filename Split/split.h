#define ERROR -1

typedef struct {
    char *nome;
    float saldo;
} user;


void prompt();
int buscar_conta(char*, user**);
int logar(user**);
int add_divida(user**, int);
void print_lista(user*);

