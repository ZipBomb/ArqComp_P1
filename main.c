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

int main(int argc, char *argv[]){

    if(argc != 3 || atoi(argv[1]) < 1 || atoll(argv[2]) < 1)
        handle_error("uso_correcto: test <D> <L>");

	int D = atoi(argv[1]);
	double L = atoll(argv[2]);
  int R;
  if(D<8)
	 R = (int)(((L*8)/D)+1);
  else
   R = L;

	FILE *fp;
    if((fp = fopen("puntos.txt","a+")) == NULL)
	handle_error("en la apertura del archivo");
	int *e=(int *)malloc(10*R*sizeof(int));

    double S[10];
	double ck=0;

    double *A = NULL;

	A = _mm_malloc(R*D*8,512);

    int i=0,j=0,k=0,z=0;

    // Inicialización de los valores del vector
    srand((unsigned int)time(NULL));
	for(z=0; z<R*D;z++)
        	*(A+z) = genera_aleatorio();

	// Generación de secuencias de D cada R índices
	e[0]=0;
	for(i=1;i<10*R;i++){
		if(i%10==0)
			k+=1;
		e[i]=k*D;
	}

	for(i=0;i<10;i++){

		double sum = 0;
		start_counter();
        //Sumar las posciones multiplos de D desde el vector e, estas están cada R indices
		for(j=0;j<R*10;j=j+10)
			sum+=*(A+e[j]);

		//Guardar Resultados
		ck=get_counter();
		S[i]=sum;

		fprintf(fp,"%f  ",ck/(R));
		fprintf(fp,"%f  ",L);
		fprintf(fp,"%d\n",D);
	}


	mhz(1, 1);

	for(i=0;i<10;i++)
		printf("Resultado %d: %f\n", i+1,S[i]);

    //Liberar
  _mm_free(A);
  free(e);

	return 0;
}
