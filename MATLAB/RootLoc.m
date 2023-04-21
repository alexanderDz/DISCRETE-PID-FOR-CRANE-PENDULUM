clear all;
% c = zpk([-0.05],[0 -2 3],[4])
g1 = tf ([1],[0.45 0 -39.2])
g2 = tf([0.45 0 -49],[-3 0 0])
gt = g1*g2
figure;impulse(gt)
figure;rlocus(gt)
figure;step(gt)