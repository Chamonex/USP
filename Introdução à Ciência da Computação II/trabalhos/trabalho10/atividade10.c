#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 64

static int fatorial(int n) {
    int i = n-1;
    while (i > 1) {
        n *= i;
        i--;
    }
    return n;
}

void copiarAux(char** conjunto_reads,char** temp, int n) {
    int i;
    for (i = 0; i < n; i++) {
        temp[i] = conjunto_reads[i];
    }
}

int compara (char a, char b) {
    if (a == b)
        return 1;
    return 0;
}

void overlapPair(int v[], char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i = 0, j = 0, i2;
    int overlap = 0, aux = 0;
    int index1 = 0, index2 = 0;

    // para teste:
    printf("\n OVERLAP PAIR %s -> %s\n", str1, str2);


    // comparações
    while (i < len1) {
        i2 = i;

        while (j < len2+1) {
            
            if (compara(str1[i2], str2[j])) {
                aux++;
                j++;
                i2++;
            }
            else {
                if ((aux > overlap)&&(i2 == strlen(str1))) {
                    // printf("\n ultimo caractere str1 (%d) = %c\n\n",i2, str1[i2]);
                    index1 = i2 - aux;
                    index2 = j - aux;
                    overlap = aux;
                }
                
                aux = 0;
                j++;
            }

        }
        i++;
        j = 0;
    }

    printf("\n---OVERLAP PAIR %s e %s---\n\n", str1, str2);
    printf("OVERLAP = %d\n", overlap);
    printf("INDEX 1 = %d\n", index1);
    printf("INDEX 2 = %d\n", index2);

    v[0] = overlap;
    v[1] = index1;
    v[2] = index2;
}

void findMostOverlaping(char** temp, int maiorOverlap[], int n, int a, int b) {

    if ((temp[a][0] != '\0')||(temp[b][0] != '\0')) {

        int *v = malloc(5 * sizeof(int));
        overlapPair(v, temp[a], temp[b]);
        
        // atualizar o maior overlap
        if (v[0] > maiorOverlap[0]) {
            maiorOverlap[0] = v[0];
            maiorOverlap[1] = v[1];
            maiorOverlap[2] = v[2];
            maiorOverlap[3] = a;
            maiorOverlap[4] = b;
        }
        
        //permutações:
        b++;
        if (a == b)
            b++;
        if (b == n) {
            a++;
            b = 0;
        }
        if (a == n)     // acabou
            return; 
    }
    findMostOverlaping(temp, maiorOverlap, n, a, b);      // guardar o return!
}

void concatenar(char** temp, int maiorOverlap[]) {

    printf("CONCATENAR\n");
    int cont;

    for (cont = 0; cont < maiorOverlap[0]; cont++)  
        temp[maiorOverlap[3]][maiorOverlap[1]+cont] = temp[maiorOverlap[4]][maiorOverlap[2]+cont];

    printf("primeiro passo = %s\n", temp[maiorOverlap[3]]);

    char* aux = malloc(sizeof(char) * (MAX - maiorOverlap[0]));
    int iaux = 0;
    int errorCont = 0;

    for (cont; cont < strlen(temp[maiorOverlap[4]]); cont++) {
        aux[iaux] = temp[maiorOverlap[4]][cont];
        printf("a string auxiliar recebeu %c\n", temp[maiorOverlap[4]][cont]);
        errorCont++;
        iaux++;
    }
    printf("auxiliar = %s\n", aux);
    
    // TRATAMENTO ERRO
    while((aux[errorCont] <65)||(aux[errorCont] > 90 && aux[errorCont] < 97)||(aux[errorCont] > 122)) {
        printf("vou excluir o %d (%c)", errorCont, aux[errorCont]);
        aux[errorCont] = '\0';
        errorCont--;
    }

    printf("auxiliar apos correcao = %s\n", aux);
    
    strcat(temp[maiorOverlap[3]], aux);
    printf("RESULTADO PREVIO -> %s\n", temp[maiorOverlap[3]]);
    
    free(temp[maiorOverlap[4]]);
    temp[maiorOverlap[4]][0] = '\0';

}

void main() {
    
    int n, i;
    scanf("%d", &n);
    int nTemp = n;

    char **conjunto_reads = (char **)malloc(n * sizeof(char*));
    
    for (i = 0; i < n; i++)
        conjunto_reads[i] = (char *)malloc(MAX * sizeof(char));

    for (i = 0; i < n; i++) {
        scanf("%s", conjunto_reads[i]);
        getchar();
    }

    char **temp = (char **)malloc(n * sizeof(char*));             
    
    copiarAux(conjunto_reads, temp, n);

    int *maiorOverlap = malloc(3 * sizeof(int));

    while (nTemp > 1) {

        maiorOverlap[0] = 0;

        if (temp)
        findMostOverlaping(temp, maiorOverlap, n, 0, 1);
        concatenar(temp, maiorOverlap);
        nTemp--;

        printf("PRINTANDO TEMP\n");    
        for (int k = 0; k < n; k++)
            printf("%d -> %s\n", k, temp[k]);    
    }
    printf("FIM\n");
    printf("\n\n%s\n", temp[maiorOverlap[3]]);

}

