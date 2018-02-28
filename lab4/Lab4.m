%% Lab 4
m = 0.94;
r = 6.36*10^-3;
Rm = 2.6;
Kt = 7.67*10^-3;
Km = 7.67*10^-3;
Kg = 3.71;
Jm = 3.9*10^-7;

a = m*r*r*Rm + Kg*Kg*Jm*Rm;
b = Kg*Kg*Kt*Km;
c = Kg*Kt*r;

Mos = 8/100;
tr = 0.16;

%%
cfinal = pos_h(end);
percent_os = (max(pos_h) - cfinal)/ cfinal * 100;
time1_index = find(pos_h >= 0.1*cfinal,1);
time1 = tout(time1_index);
time9_index = find(pos_h >= 0.9*cfinal,1);
time9 = tout(time9_index);
rise_time = time9 - time1;

%% 5.1 Proportional Control
res_a = 44000;

%min K to meet tr - tr = 0.16, os = 11.0739 percent
K = 42.5;

%min K to meet os - tr = 0.19, os = 7.8097 percent
K = 36.07;

%min K to meet os and tr - DNE

%% 5.2 PD Control
% from prelab kd = 4.9293-50 should work
kd = 45;

%changed to zero to 15 instead of 12

%% 5.3 Performance for Different Input Signals

%changed Simulink input blocks and ran same code as 5.2

%% 5.4 Performance for Limited Braking Ability

%K = 42.5, tr = 0.155, os = 13.68

%% General Code for Plotting

cfinal = pos_h(end);
percent_os = (max(pos_h) - cfinal)/ cfinal * 100;
time1_index = find(pos_h >= 0.1*cfinal,1);
time1 = tout(time1_index);
time9_index = find(pos_h >= 0.9*cfinal,1);
time9 = tout(time9_index);
rise_time = time9 - time1;
rise_time %display rise time
percent_os %display percent overshoot
plot(tout, pos_h)
hold on
plot(tout,simin)
xlabel('Time (s)')
legend('Position (m)','Step Input')
title('Limited Braking Step Response for K = 36.07')