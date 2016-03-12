function Analisis_puntos
clear all
clf
close all

t=load('puntos.txt'); 
x=t(:,1);
y=t(:,2);

plot(x,y,'-r*','linewidth',2,'markersize',6,'markeredgecolor','k','markerfacecolor','k');
title('Analisis de los Resultados');
xlabel('Numero Total de Lineas Cache');
ylabel('Coste Medio por Iteracion');