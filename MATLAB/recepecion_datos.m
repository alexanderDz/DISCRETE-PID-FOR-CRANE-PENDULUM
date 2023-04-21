
%%INICIALIZAR=========================
close all;
clear all;
clc;
voltaje = 0;

delete(instrfind({'port'},{'COM3'}));
puerto = serial('COM3');
puerto.BaudRate = 9600;

fopen(puerto);
contador = 1;
muestras = input('Ingrese un valor de muestras: ');
%=====================================
figure('Name','Grafica datos');
title('Grafica datos');
xlabel('Numero de muestras');
ylabel('Datos');
grid on;
hold on;
% ciclo para la grafica

while contador <= muestras
    ylim([0 10]);
    xlim([0 muestras]);
    valorADC = fscanf(puerto,'%d')';
    voltaje(contador) = valorADC(1);%*5/1024;%vector de almacenamiento
    plot(voltaje);
    drawnow
    contador = contador + 1;
end
% cierra y borra puerto
fclose(puerto);
delete(puerto);


