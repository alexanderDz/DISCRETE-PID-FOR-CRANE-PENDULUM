%%INICIALIZAR=========================
clc
clear all;
if ~isempty(instrfind)
    fclose(instrfind);
    delete(instrfind);
end
close all
clc
%% ABRIR PUERTO SERIAL ===============
data = serial('COM3');
data.DataBits = 8;
data.StopBits = 1;
data.BaudRate = 115200;
data.Parity = 'none';
fopen(data);
%%OBSERVAR INTERFAS===================
f = figure;
boton_prueba = uicontrol(f,'style','push','position',[15 100 90 50],'string','ON','callback','fwrite(data,"1")');
boton_prueba2 = uicontrol(f,'style','push','position',[120 100 90 50],'string','OFF','callback','fwrite(data,"0")');
