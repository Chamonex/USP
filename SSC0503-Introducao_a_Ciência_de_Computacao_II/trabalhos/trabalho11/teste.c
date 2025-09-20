#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void ExchangeCharacters(char* str, int p1, int p2)
{
    char tmp;
    tmp = str[p1];
    str[p1] = str[p2];
    str[p2] = tmp;
}


void RecursivePermute(char* str, int k)
{
    int i, len;

    len = strlen(str);

    if (k == len)            // 0
      printf( "%s\n", str);

    else {
        for (i = k; i < len; i++) {
            ExchangeCharacters(str, k, i);
            RecursivePermute(str, k + 1);
            ExchangeCharacters(str, i, k);
        }
    }
}


void main()
{
    int n;

    scanf("%d", &n);

    char* str = (char*) malloc(n*sizeof(char));


    for (int i = 0; i < n/2; i++) {
        str[i] = '0';
        str[i + n/2] = '1';
    }

    RecursivePermute(str, 0);
}
