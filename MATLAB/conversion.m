function [v1, v2, v3] = conversion(valor)
valores = textscan(valor,'%s%s%s','delimiter',':');
[v1, v2, v3] = deal(valores{:});
v1 = str2double(v1);
v2 = str2double(v2);
v3 = str2double(v3);
% v1 = v1*5/4095;
% v2 = v2*5/4095;
% v3 = v3*5/4095;
end