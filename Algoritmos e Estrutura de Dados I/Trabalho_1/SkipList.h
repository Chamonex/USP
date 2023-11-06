
struct NO{
    int chave;
    char nome[20];
    int tel;
    struct NO **prox;
};

typedef struct{

	int NivelMAX;
	float P;
	int nivel;
	struct NO *inicio;

} SkipList;


SkipList* criaSkipList(int MAXLVL, float P);
int alteraSkiplist(SkipList* sk, char nome[], int tel);
void liberaSkipList(SkipList* sk);
int insereSkipList(SkipList *sk, char nome[], int tel);
int removeSkipList(SkipList *sk, char nome[]);
int buscaSkipList(SkipList *sk, char nome[]);
int tamanhoSkipList(SkipList* sk);
int vaziaSkipList(SkipList* sk);
void imprimeSkipList(SkipList *sk);

//struct NO* novoNo(int key, int level);
