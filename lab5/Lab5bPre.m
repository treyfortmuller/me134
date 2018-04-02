%% Constants of the controller
k_i = 0.114;
k_x = 30.0676;
a = 843;
% k_c = 2*k_x/a/2/k_i;
k_c = 4;
k_a = 2;
m = 0.0162;
dc = 2; % DC gain of 2
z_c = 1.5;
p_c = z_c * 20; % pole to zero ratio of 20

% Transfer function for plant
% s = tf('s');
% num = a * k_a * k_i;
% den = m * (s^2 - k_x/m);
% G = num/den;
% fig1 = figure(1);
% rlocus(G);
% fig2 = figure(2);
% step(G)

% Transfer function for plant and controller
G_c = k_c * (1 + s/z_c) / (1 + s/p_c);
G_t = G_c * G;

% Root locus and phage margin of the whole system
fig3 = figure(3);
margin(G_t)
% fig4 = figure(4);
% rlocus(G_t)

% Calculate the values of resistance and capacitor
R1 = 1e4/k_c
R2 = z_c * R1 / (p_c - z_c)
C = 1/(p_c*R2)