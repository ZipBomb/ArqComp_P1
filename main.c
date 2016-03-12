#include "rutinas_clock.h"

// R = 0.5*512, 1.5*512, 0.5*512, 0.75*512, 2*512, 4*512, 8*512
// D = 2, 12, 26, 64, 92

int main(int argc,char *argv[]){
	int D=atoi(argv[1]);
	double L=atoll(argv[2]);
	int R=(int)((L*8/D)+1);
	double *A = NULL;
	int e[10*R];
	double S[10];
	double ciclos[10];
	double ck=0;

	A = _mm_malloc(R*D*8,512);
	int i=0,j=0,k=0,z=0;

	//Iniciar los Rand
	for(z=0; z<R*D;z++){
		*(A+z)=((double)rand()/(double)RAND_MAX);
	}

	//Secuencias de D cada R indices
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
		for(j=0;j<R*10;j=j+R){
			sum+=*(A+e[j]);
		}
		//Guardar Resultados
		S[i]=sum;
		ck=get_counter();
		//Guardar ciclos
		ciclos[i]=ck;
		printf("\nClocks=%1.10lf \n", ck);
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

	for(i=0;i<10;i++)
		printf("%f\n", ciclos[i]);

	/* Esta rutina imprime a frecuencia de reloxo estimada coas rutinas start_counter/get_counter */
	mhz(1, 1);

	for(i=0;i<10;i++)
		printf("Resultado %d: %f\n", i+1,S[i]);


	FILE *fp=fopen("puntos.txt","a+");
	//Escribir en el archivo las tres mejores medidas
	for(i=0;i<3;i++){
		fprintf(fp, "%f", ciclos[i]);
		fprintf(fp, "  %f\n", L);
	}




	return 0;
}
