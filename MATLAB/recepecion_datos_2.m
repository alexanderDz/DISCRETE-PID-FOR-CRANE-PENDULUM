%%INICIALIZAR=========================
% SE DEBE ACOMODAR NUEVAMENTE EL IMAN PARA VOLVER A MEDIR
close all;
clear all;
clc;

delete(instrfind({'port'},{'COM3'}));
puerto = serial('COM3');
puerto.BaudRate = 115200;

fopen(puerto);
contador = 1;
muestras = input('Ingrese un valor de muestras: ');
%=====================================
v1 = zeros;
v2 = zeros;
v3 = zeros;
voltaje = zeros(zeros,3);

figure('Name','Grafica datos');
title('Grafica datos');
xlabel('Numero de muestras');
ylabel('Datos');
grid on;
hold on;
% ciclo para la grafica
for c =1:1:muestras
    fprintf(puerto,'%d',1);
    valor = fscanf(puerto,'%s');
    [v1(c), v2(c), v3(c)] = conversion(valor);

    voltaje(c,1) = v1(c);
    voltaje(c,2) = v2(c);
    voltaje(c,3) = v3(c);
    axis([0 muestras -2 360]);
    plot(voltaje);
    drawnow;
end
    
% cierra y borra puerto
fprintf(puerto,'%d',0);
fclose(puerto);
delete(puerto);