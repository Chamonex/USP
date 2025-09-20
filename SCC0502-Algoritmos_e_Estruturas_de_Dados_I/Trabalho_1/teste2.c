#include <stdio.h>
#include <string.h>

void main() {

    

}

int sorteiaNivel(SkipList *sk){
	
	float r = (float)rand()/RAND_MAX;
	int nivel = 0;
	while(r < sk->P && nivel < sk->NivelMAX){
		nivel++;
		r = (float)rand()/RAND_MAX;
	}
	return nivel;
}

static int obterChave(char nome[]) {

    // gerar uma chave com base no vetor de caracteres nome
    int c = nome[0];
	float r = (float)rand()/RAND_MAX*10;
    int chave = 0;

    // funciona somente para letras minusculas
    while (c > 96 && c < 123) {
		
        chave += (c-96) * r;
        c = nome[cont-1];
    	float r = (float)rand()/RAND_MAX*10;
    }
    
    return chave;

}