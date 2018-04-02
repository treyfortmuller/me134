%% Lab 5a
% distance from equilibrium position
x_from_eq = [-4 -3 -2 -1 0 1 2]; %%mm
% output voltage
v = [2.97 3.01 2.98 3.23 4.04 5.03 5.10]; %%V

%% 5.2 3a
figure;
plot(x_from_eq,v)
title('Output Voltage Linearization');
xlabel('Distance from Equalibrium Position (mm)');
ylabel('Output Voltage (V)');

%% 5.2 3b
% slope near equilibrium position
a = (v(6) - v(4)) / (2*0.001) %%V/m 

% Optimal Equilibrium voltage of y
v_eq = v(4) + a*0.001

%% 5.2 4d
% current monitor voltage
v_m = [-0.221 -0.234 -0.244 -0.255 -0.261]; %%V
% current
i_m = v_m * 20/3; %%A
i0 = -1.74;
i_from_eq = i_m - i0;

% mass of ball
m = [2.6 2 1.1 0.5 0]; %%g
% weight of call
w = 9.81*0.001*m;

figure
plot(i_from_eq,w)
hold on
line(i_from_eq,w)
xlabel('Current Deviation from Equilibrium (A)')
ylabel('Weight (N)')
title('Weight of Ball as Function of \deltaI')

%% 5.2 4e
% slope Ki near equilibrium current
Ki = (w(4) - w(5)) / (i_from_eq(4) - i_from_eq(5)) %%N/A

%% 5.2 5d
% delta x 
d = [0 -1 -2 -3 -4 -5]; %mm
% mass
m = [0 1.8 4.6 5.7 6.5 7.3]; %%g
% weight
w = 9.81*0.001*m; %%N
plot(d,w)
xlabel('Position Deviation from Equilibrium (m)')
ylabel('Weight (N)')
title('Weight of Ball as Function of \deltax')

%% 5.2 5e
% slope Kx near equilibrium position
Kx = (w(2) - w(1)) / ((d(2) - d(1))*0.001) %%N/m

%% 6
DC = 1000; % A/m
Ka = 2; %A/V
% Kc
Kc = DC/a/Ka