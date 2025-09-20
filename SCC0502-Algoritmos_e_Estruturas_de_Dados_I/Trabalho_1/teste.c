#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand((unsigned)time(0));
	float r = (float)rand()/RAND_MAX;

    printf("%.3f", r);

    
}