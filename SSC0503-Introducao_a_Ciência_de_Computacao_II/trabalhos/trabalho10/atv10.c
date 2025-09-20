#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 64

char* acharoverlap(char** conjuntoreads, int n, char* overlap);
int overlapsize(char* read1, char* read2);
char* overlapstring(char* read1, char* read2, int size, char* overlap);
char* superstring(char* read1, char* read2, char* overlap, int size);
char* maiorstr (char* read1, char* read2);

int r1, r2;



int main (){
    int n;
    int t_ov;
    scanf("%d", &n);
    char **conjuntoreads = (char **)malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++)
        conjuntoreads[i] = (char *)malloc(MAX * sizeof(char));

    for (int i = 0; i < n; i++)
        scanf("%s", conjuntoreads[i]);                  // vetor de string
        
    char *auxstr = (char*)calloc(MAX, sizeof(char));    //pq calloc?
        
    int aux_n = n;

    while (n != 1)
    {
            auxstr = acharoverlap(conjuntoreads, n, auxstr);
            t_ov = overlapsize(conjuntoreads[r1], conjuntoreads[r2]);
            char *strfinal = superstring(conjuntoreads[r1], conjuntoreads[r2], auxstr, t_ov);    
            int novo = strlen(strfinal)+1;
            if (conjuntoreads[0] != NULL)
            {
                free(conjuntoreads[0]);
            }
            conjuntoreads[0] = (char*)calloc(novo, sizeof(char));
            strncpy(conjuntoreads[0], strfinal, novo);
            n--;
            if (strfinal != NULL)
            {
                free(strfinal);
            }
            }


        printf("%s\n", conjuntoreads[0]);
        
        for (int i = 0; i < aux_n; i++)
        {
            if (conjuntoreads[i] != NULL)
            {
                free(conjuntoreads[i]);
            }
        }
        

        free(auxstr);
        free(conjuntoreads);

    return 0;

}

int overlapsize(char* read1, char* read2){
int t1 = strlen(read1)+1;
int t2 = strlen(read2)+1;
int chartcomp[t1][t2];
int maxover = 0;


for (int i = 0; i < t1; i++)
{
    for (int j = 0; j < t2; j++)
    {
         if (i == 0 || j == 0) {
                chartcomp[i][j] = 0;
            } else if (read1[i - 1] == read2[j - 1]) {
                chartcomp[i][j] = chartcomp[i - 1][j - 1] + 1;
                maxover = (chartcomp[i][j] > maxover) ? chartcomp[i][j] : maxover;
            } else {
                chartcomp[i][j] = 0;
        }
   }
}

return maxover;
}

char* overlapstring(char* read1, char* read2,int size, char* overlap){
int t1 = strlen(read1)+1;
int t2 = strlen(read2)+1;
int k = 0;
int chartcomp[t1][t2];


for (int i = 0; i < t1; i++)
{
    for (int j = 0; j < t2; j++)
    {
         if (i == 0 || j == 0) {
                chartcomp[i][j] = 0;
            } else if (read1[i - 1] == read2[j - 1]) {
                chartcomp[i][j] = chartcomp[i - 1][j - 1] + 1;
                if (chartcomp[i][j] == size)
                {
                    int aux = i-size;
                    for (k; k < size; k++)
                    {
                        overlap[k] = read1[aux];
                        aux++;
                    }
                }
            } else {
                chartcomp[i][j] = 0;
        }
   }
}

return overlap;
}

char* acharoverlap(char** conjuntoreads, int n, char* overlap){
    int moverlap = 0;    
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if(overlapsize(conjuntoreads[i], conjuntoreads[j]) > moverlap){
                    moverlap = overlapsize(conjuntoreads[i], conjuntoreads[j]);
                    r1=i;
                    r2 =j;
                }
                
            }
        }
    overlap = overlapstring(conjuntoreads[r1], conjuntoreads[r2], moverlap, overlap);
    return overlap;
}

char* maiorstr (char* read1, char* read2){
int t1 = strlen(read1);
int t2 = strlen(read2);

    if (t1<t2)
    {
       return read1;   }
    
return read2;
}

char* superstring(char* read1, char* read2, char* overlap, int size){
int t1 = strlen(read1);
int t2 = strlen(read2);
int tamnovo = t1 + t2 - size + 2;
char* sstr = (char*)calloc(tamnovo, sizeof(char));
int p1 = strncmp(read1, overlap, size); //read1 prefixo e read2 sufixo
int p2 = strncmp(read2, overlap, size); //read2 prefixo e read1 sufixo

    if (p1 == 0)
    {
        for (int i = 0; i < strlen(read2); i++)
        {
            sstr[i] = read2[i];
        }

        for (int i = 0; i < strlen(read1)-size; i++)
        {
            sstr[i+strlen(read2)] = read1[i+size];
        }
    
    }

    else if (p2 == 0)
    {
        for (int i = 0; i < strlen(read1); i++)
        {
            sstr[i] = read1[i];
        }

        for (int i = 0; i < strlen(read2)-size; i++)
        {
            sstr[i+strlen(read1)] = read2[i+size];
        }
    
    }

    else if (size == 0)
    {
        if (sstr != NULL)
        {
            free(sstr);
        }
        int t = t1 + t2 + 2;
        sstr = (char*)calloc(t, sizeof(char));

        for (int i = 0; i < t1; i++)
        {
            sstr[i] = read1[i];
        }

        for (int i = 0; i < t2; i++)
        {
            sstr[i+t1] = read2[i];
        }
    }
    
    else
    {
        if (sstr != NULL)
        {
            free(sstr);
        }
        int t = strlen(maiorstr(read1, read2))+1;
        sstr = (char*)calloc(t, sizeof(char));
        strncpy(sstr, maiorstr(read1, read2), t);
    }

    return sstr;
}