#include "rutinas_clock.h"

// R = 0.5*512, 1.5*512, 0.5*512, 0.75*512, 2*512, 4*512, 8*512
#define R 1000
// D = 2, 12, 26, 64, 92
#define D 2

int main()
{
	double *A = NULL;
	int e[10*R];
	double S[10];
	double ck=0,total_ck=0;

	A = _mm_malloc(R*D*8,512);
	int i=0;
	for(i=0; i<R*D;i++)
		*(A+i)=rand();

	i=0;
	for(i=0;i<10*R;i++)
		e[i]=i*D;

	i=0;
	int j=0;
	for(i=0;i<10;i++){
		start_counter();
		double sum = 0;
		for(j=0;j<R*D;j++){
			sum+=*(A+e[i]);
		}
		ck=get_counter();
		mhz(1, 1);
		printf("\nClocks=%1.10lf \n", ck);
		total_ck+=ck;
		S[i]=sum;
	}

	for(i=0;i<10;i++)
		printf("Resultado %d: %f\n", i+1,S[i]);


	/* Esta rutina imprime a frecuencia de reloxo estimada coas rutinas start_counter/get_counter */


	return 0;
}
