function analisis_puntos
clear all
clf
close all

t=load('puntos.txt'); 
x=t(:,1);
y=t(:,2);
x1=[0:(length(x)/3)-1];
y1=[0:(length(y)/3)-1];
k=1;
i=3;
while i<=length(x)
  z=x(i)*x(i-1)*x(i-2);
  x1(k)=z^(1/3);
  y1(k)=y(i);
  i=i+3;
  k=k+1;
endwhile

plot(x1,y1,'-r*','linewidth',2,'markersize',6,'markeredgecolor','k','markerfacecolor','k');
title('Analisis de los Resultados');
xlabel('Numero Total de Lineas Cache');
ylabel('Coste Medio por Iteracion');
