function analisis_puntos
clear all
clf
close all

t=load('puntos.txt');
y=t(:,1);
x=t(:,2);
D=t(:,3);
y1=[0:(length(x)/3)-1];
x1=[0:(length(y)/3)-1];
D1=[0:(length(D)/3)-1];
k=1;
i=3;
while i<=length(x)
  z=y(i)*y(i-1)*y(i-2);
  x1(k)=z^(1/3);
  y1(k)=x(i);
  D1(k)=D(i);
  i=i+3;
  k=k+1;
endwhile

for i=1:7
  bar(y1(i:5:end),x1(i:5:end),'-or');
  title('Analisis de los Resultados');
  xlabel('Numero Total de Lineas Cache');
  ylabel('Coste Medio por Iteracion');
end
