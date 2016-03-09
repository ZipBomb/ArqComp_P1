#include "rutinas_clock.h"

// R = 0.5*512, 1.5*512, 0.5*512, 0.75*512, 2*512, 4*512, 8*512
// D = 2, 12, 26, 64, 92

int main(int argc,char *argv[]){
	int D=atoi(argv[1]);
	int L=512*atoll(argv[2]);
	int R=(int)((L/D)+1);
	double *A = NULL;
	int e[10*R];
	double S[10];
	double ck=0,total_ck=0;

	A = _mm_malloc(R*D*8,512);
	int i=0;
	for(i=0; i<R*D;i++)
		*(A+i)=((double)rand()/(double)RAND_MAX);

	i=0;
	for(i=0;i<10*R;i++)
		e[i]=i*D;

	i=0;
	int j=0;
	start_counter();
	for(i=0;i<10;i++){
		double sum = 0;
		for(j=0;j<R*D;j++){
			sum+=*(A+e[i]);
		}
		total_ck+=ck;
		S[i]=sum;
	}
	ck=get_counter();
	printf("\nClocks=%1.10lf \n", ck);
	mhz(1, 1);

	for(i=0;i<10;i++)
		printf("Resultado %d: %f\n", i+1,S[i]);


	/* Esta rutina imprime a frecuencia de reloxo estimada coas rutinas start_counter/get_counter */


	return 0;
}
