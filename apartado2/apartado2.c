#include "rutinas_clock.h"
#include "time.h"

#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)

double genera_aleatorio() {
    double min = 1.0;
    double max = 2.0;
    double rango = max - min;

    double random = (double)rand()/(double)RAND_MAX;

    return random * rango + min;
}

void shuffle(int *array, int tam) {
    if(tam > 1) {
        int i;
        for(i=0; i<(tam-1); i++) {
            int j = i + rand() / (RAND_MAX / (tam-i)+1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

int main(int argc, char *argv[]){

    if(argc != 3 || atoi(argv[1]) < 1 || atoll(argv[2]) < 1)
        handle_error("uso_correcto: test <D> <L>");

	int D = atoi(argv[1]);
	double L = atoll(argv[2]);
FILE *fp;
    if((fp = fopen("puntos.txt","a+")) == NULL)
        handle_error("en la apertura del archivo");
    int R;
    if(D<8)
        R = (int)((L*8/D)+1);
    else
        R = L;

	int *e=(int *)malloc(10*R*sizeof(int));

    double S[10];

	double ck=0;

    double *A = NULL;
	A = _mm_malloc(R*D*8,64);

    int i,j;
    int *k = (int *)calloc(R, sizeof(int));

    // Inicialización de los valores del vector
    srand((unsigned int)time(NULL));
	for(i=0; i<R*D;i++)
        *(A+i) = genera_aleatorio();

    for(i=0;i<R;i++)
        *(k+i)=i;

    shuffle(k, R);

    j = -1;
    for(i=0; i<10*R; i++) {
        if(i%10==0) {
            j++;
        }
        e[i]=k[j]*D;
    }

	for(i=0;i<10;i++){
		double sum = 0;

        //Sumar las posciones multiplos de D desde el vector e, estas están cada R indices
		start_counter();
		for(j=0;j<R*10;j=j+10)
			sum+=*(A+e[j]);

		ck=get_counter();
		//Guardar Resultados
		S[i]=sum;

		fprintf(fp,"%f  ",ck/(R));
		fprintf(fp,"%f  ",L);
		fprintf(fp,"%d\n",D);
	}

    _mm_free(A);
    free(e);

	mhz(1, 1);

	for(i=0;i<10;i++)
		printf("Resultado %d: %f\n", i+1,S[i]);

	return 0;
}
