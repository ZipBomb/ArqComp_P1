#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
  FILE *fp;


  fp=fopen("puntos.txt","r");


  char aux[20];
  double ciclos[350];
  int lineas[350];
  int saltos[350];
  int i=0,z=0,j=0;
  while(!feof(fp) && i<350){
    fscanf(fp," %[^  ]",aux);
    ciclos[i]=atof(aux);
    fscanf(fp," %[^  ]",aux);
    lineas[i]=atof(aux);
    fscanf(fp," %[^\r\n]",aux);
    saltos[i]=atoi(aux);
    i++;
    if(i%10==0){
      double aux=0;
    	for(z=i-10;z<i-1;z++){
    		for(j=i-10;j<i-1;j++){
    			if(ciclos[j]>ciclos[j+1]){
    				aux=ciclos[j];
    				ciclos[j]=ciclos[j+1];
    				ciclos[j+1]=aux;
    			}
    		}
      }
    }

  }

  double ejeY[35];
  int ejeX[35];
  int D[35];
  z=0;
  for(i=0;i<350;i++){
    double aux=0;
    if(i%10==0){
      aux=ciclos[i]*ciclos[i+1]*ciclos[i+2];
      ejeY[z]=pow(aux,0.333333);
      ejeX[z]=lineas[i];
      D[z]=saltos[i];
      z++;
    }
  }


  z=0;
  for(i=0;i<5;i++){
    FILE *cp;
    j=0;
    if(z==0){
      cp=fopen("D=5.csv","w");
      for(j=i;j<35;j=j+5){
        fprintf(cp, "%d ", ejeX[j]);
        fprintf(cp, "%f\n", ejeY[j]);
      }
    }

    else if(z==1){
      cp=fopen("D=29.csv","w");
      for(j=i;j<35;j=j+5){
        fprintf(cp, "%d ", ejeX[j]);
        fprintf(cp, "%f\n", ejeY[j]);
      }
    }

    else if(z==2){
      cp=fopen("D=53.csv","w");
      for(j=i;j<35;j=j+5){
        fprintf(cp, "%d ", ejeX[j]);
        fprintf(cp, "%f\n", ejeY[j]);
      }
    }

    else if(z==3){
      cp=fopen("D=77.csv","w");
      for(j=i;j<35;j=j+5){
        fprintf(cp, "%d ", ejeX[j]);
        fprintf(cp, "%f\n", ejeY[j]);
      }
    }

    else if(z==4){
      cp=fopen("D=95.csv","w");
      for(j=i;j<35;j=j+5){
        fprintf(cp, "%d ", ejeX[j]);
        fprintf(cp, "%f\n", ejeY[j]);
      }
    }

    z++;

  }


}
