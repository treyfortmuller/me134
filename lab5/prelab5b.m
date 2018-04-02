%% Pre-lab 5b
% Charlene Shong

%% Constants
% controller
ki = 0.1226;
kx = 17.6580;
a = 900;
kc = 2*kx/(a*2*ki);
ka = 2;
% system parameters
m = 0.0162;
dc = 2; %dc gain
zc = 1;
pc = zc*20; %pole-zero ratio of 20

% transfer function
s = tf('s'); %a TF model using a rational function in the Laplace variable, s
G = (a*ka*ki)/(m*(s^2 - kx/m));
Gc = kc*(1 + s/zc)/(1 + s/pc); %controller tf
Gt = Gc*G; %new system tf

%% Plots
subplot(2,2,1);
rlocus(G)
title('Root Locus without Controller');

subplot(2,2,2);
step(G)
title('Step Response without Controller');

subplot(2,2,4);
margin(Gt)

subplot(2,2,3);
rlocus(Gt)
title('Root Locus with Controller');

%% Calculations
R1 = 10000/kc
R2 = zc*R1/(pc - zc)
C = 1/(pc*R2)