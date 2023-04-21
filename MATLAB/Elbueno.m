clc;
clear all;
oe = importdata('g_con_fit_80.mat')
gd=tf(oe)
figure;
step(gd);
title('TF con OE discreto');
figure;
rlocus(gd);
title('LGR discreto');
%PID discreto
 z=tf('z');
 cd=0.09*(z-0.5);
 god=feedback(cd*gd,1);
figure;
step(god);
title('control discreto');
figure;
rlocus(god);
title('control LGR discreto');

%CONVERSION A CONTINUO
gc=d2c(gd)
figure;
step(gc);
title('TF con OE continuo');
figure;
rlocus(gc);
title('LGR continuo');
%control continuo
s=tf('s');
cc=0.03*(1+2*s);
goc=feedback(cc*gc,1);
figure;
step(goc);
title('control continuo');
figure;
rlocus(goc);
title('control LGR continuo');