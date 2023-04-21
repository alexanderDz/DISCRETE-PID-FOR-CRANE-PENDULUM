%----------------Datos---------------
clc;
posi = importdata('pos6.mat');
ang = importdata('ang6.mat');
fuerza = importdata('Fuerza1ide2.mat');
angulo = importdata('Angulo1Iden2.mat');
%------------Controladores------------
Gt=TF1*TF2;
Gc=pidtune(TF1,'PID');
pidTuner(TF1,Gc)
Gpt=TF1*Gc;

F2=Gpt*TF2;
Gc1=pidtune(F2,'PID')

pidTuner(F2,Gc1)