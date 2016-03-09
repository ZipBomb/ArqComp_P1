#include "rutinas_clock.h"

#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)

// R = 0.5*512, 1.5*512, 0.5*512, 0.75*512, 2*512, 4*512, 8*512
// D = 2, 12, 26, 64, 92

int main(int argc,char *argv[]){

    if(argc != 3 || argv[1] < 0 || argv[2] < 0) {
        handle_error("en los argumentos");
    }
 
	int D=atoi(argv[1]);	
    int L=512*atoll(argv[2]);
	int R=(int)((L*8/D)+1);
	double *A = NULL;
	int e[10*R];
	double S[10];
	double ck=0,total_ck=0;
    
	A = _mm_malloc(R*D*8, 512);
	int i=0,j=0,k=0;
	for(i=0; i<R*D;i++)
		*(A+i)=((double)rand()/(double)RAND_MAX);

	e[0]=0;
	for(i=1;i<10*R;i++){
		if(i%R==0)
			k+=1;
		e[i]=k*D;
	}
   
    start_counter();
	for(i=0;i<10;i++){
		double sum = 0;
		for(j=0;j<D;j=j+D){
			sum+=*(A+e[j]); 
		}
		total_ck+=ck;
		S[i]=sum;   
	}
    ck=get_counter();

	printf("\nClocks=%1.10lf \n", ck/10);
	mhz(1, 1);

	for(i=0;i<10;i++)
		printf("Resultado %d: %f\n", i+1,S[i]);

	/* Esta rutina imprime a frecuencia de reloxo estimada 
       coas rutinas start_counter/get_counter */

	return 0;
}
