clc;
clear all;
datos1 = importdata('ac6.mat');
x1 = importdata('pos6.mat');
angulo = importdata('ang6.mat');

for i = 1:1:500
    x(i)=x1(i)/10;
end
    for n=10:1:500
        posicion(n)=(x(n)+x(n-1)+x(n-2)+x(n-3)+x(n-4)+x(n-5)+x(n-6)+x(n-7)+x(n-8)+x(n-9))/10;
    end

vel = diff(posicion);
al = diff(vel);

M = 0.05;
m = 0.005;

for c = 10:1:498
    fuerza(c) = (M+m)*al(c);
end

% figure;
% plot(al);grid on;
% title('al');
% figure;
% plot(x);grid on;
% title('Aceleracion1');

fuerza1=fuerza(12:498);
angulo1=angulo(1:487);

figure;
plot(fuerza);grid on;
title('Fuerza');
figure;
plot(al);grid on;
title('Aceleracion');
figure;
plot(posicion);grid on;
title('Posicion');
figure;
plot(angulo1);grid on;
title('Angulo');