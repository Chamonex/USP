#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int sortBin() {

    srand((unsigned)time(NULL));
    int i = rand() %2;
    return i;

}


void main() {
    // for (int i = 0; i < 10; i++)
    //     printf("%d\n", sortBin());

    srand((unsigned)time(NULL)); // alimentando o rand com a seed time
	float r = (float)rand()/RAND_MAX;
    printf("%f", r);
}

