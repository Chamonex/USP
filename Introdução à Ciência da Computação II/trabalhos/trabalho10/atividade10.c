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

    // printf("\n---OVERLAP PAIR %s e %s---\n\n", str1, str2);
    // printf("OVERLAP = %d\n", overlap);
    // printf("INDEX 1 = %d\n", index1);
    // printf("INDEX 2 = %d\n", index2);

    v[0] = overlap;
    v[1] = index1;
    v[2] = index2;
}

void findMostOverlaping(char** temp, int maiorOverlap[], int n, int a, int b) {

    printf("entrei no findMostOberlaping n = %d\n", n);
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

void trocarString(char** temp, int iStr, int iDestino) {
    char* aux = malloc(MAX * sizeof(char));
    aux = temp[iDestino];
    temp[iDestino] = temp[iStr];
    temp[iStr] = aux;
    free(aux);
    temp[iStr][0] = '\0';
}

void concatenar(char** temp, int maiorOverlap[], int nTemp) {

    printf("CONCATENAR\n");
    int cont;

    for (cont = 0; cont < maiorOverlap[0]; cont++)  
        temp[maiorOverlap[3]][maiorOverlap[1]+cont] = temp[maiorOverlap[4]][maiorOverlap[2]+cont];


    char* aux = malloc(sizeof(char) * (MAX - maiorOverlap[0]));
    int iaux = 0;
    int errorCont = 0;

    for (cont; cont < strlen(temp[maiorOverlap[4]]); cont++) {
        aux[iaux] = temp[maiorOverlap[4]][cont];
        errorCont++;
        iaux++;
    }

    
    // TRATAMENTO ERRO
    while((aux[errorCont] <65)||(aux[errorCont] > 90 && aux[errorCont] < 97)||(aux[errorCont] > 122)) {
        aux[errorCont] = '\0';
        errorCont--;
    }

    strcat(temp[maiorOverlap[3]], aux);
    /*
        maiorOverlap
        0 = overlap
        1 = index 1
        2 = index 2
        3 = string 1
        4 = string 2
        nTemp = numero de vetores que tem agora
    */
    // trocar a string 2 pela ultima 

    // for (int i = 0; i < nTemp; i++)
    //     printf("%d -> %s\n", nTemp, temp[nTemp]);

    // trocarString(temp, maiorOverlap[4], nTemp-1);
    // printf("realizei a trocaString\n");
    // for (int i = 0; i < nTemp; i++)
    //     printf("%d -> %s\n", nTemp, temp[nTemp]);
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

        printf("entrei no while, nTemp = %d\n", nTemp);
        maiorOverlap[0] = 0;

        findMostOverlaping(temp, maiorOverlap, nTemp, 0, 1);
        concatenar(temp, maiorOverlap, nTemp);

        
        for (int i = 0; i < nTemp; i++)
            printf("%d -> %s\n", i, temp[i]);

        nTemp--;

        for (int k = 0; k < n; k++)
            printf("%d -> %s\n", k, temp[k]);  
    }

}

