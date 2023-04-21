clc
clear all;
if ~isempty(instrfind)
    fclose(instrfind);
    delete(instrfind);
end
close all
clc

a = serial('COM3','BaudRate',115200);
val = 20;
fopen(a);
fprintf(a,'%i',val);
fclose(a);