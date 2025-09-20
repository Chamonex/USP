
struct NO{
    int chave;
    char nome[20];
    char tel[20];
    struct NO **prox;
};

typedef struct{

	int NivelMAX;
	float P;
	int nivel;
	struct NO *inicio;

} SkipList;


SkipList* criaSkipList(int MAXLVL, float P);
int alteraSkiplist(SkipList* sk, char nome[], char tel[]);
void liberaSkipList(SkipList* sk);
int insereSkipList(SkipList *sk, char nome[], char tel[]);
int removeSkipList(SkipList *sk, char nome[]);
int buscaSkipList(SkipList *sk, char nome[]);

