#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double genera_aleatorio() {
    double min = 1.0; 
    double max = 2.0;                                                                 
    double rango = max - min;

    double random = (double)rand()/(double)RAND_MAX;
    
    return (random * rango) + min;
}

int main() {
    srand((unsigned int)time(NULL));
    printf("%1.15lf\n", genera_aleatorio());
}
