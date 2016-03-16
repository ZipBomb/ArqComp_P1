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

  if(D<8)
	 int R = (int)((L/D)+1);
  else
   int R = L;

	int *e=(int *)malloc(10*R*sizeof(int));

    double S[10];
	double ciclos[10];
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
		if(i%R==0)
			k+=1;
		e[i]=k*D;
	}

	for(i=0;i<10;i++){
		start_counter();
		double sum = 0;

        //Sumar las posciones multiplos de D desde el vector e, estas están cada R indices
		for(j=0;j<R*10;j=j+R)
			sum+=*(A+e[j]);

		//Guardar Resultados
		S[i]=sum;
		ck=get_counter();

        //Guardar ciclos
		ciclos[i]=ck;
	}

	//Ordenar los ciclos medidos
	double aux=0;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(ciclos[j]>ciclos[j+1]){
				aux=ciclos[j];
				ciclos[j]=ciclos[j+1];
				ciclos[j+1]=aux;
			}
		}
	}

	mhz(1, 1);

	for(i=0;i<10;i++)
		printf("Resultado %d: %f\n", i+1,S[i]);

	FILE *fp;
    if((fp = fopen("puntos.txt","a+")) == NULL)
        handle_error("en la apertura del archivo");

	//Escribir en el archivo las tres mejores medidas
  for(i=0;i<3;i++){
		fprintf(fp, "%f", ciclos[i]);
		fprintf(fp, "  %f", L);
    fprintf(fp, "  %d\n", D);
	}

  _mm_free(A);
  free(e);

	return 0;
}
