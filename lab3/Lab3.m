%% Lab 3

%% Pre-lab MATLAB Step Input
%Charlene Shong

% System Parameters
mc = 0.94; %kg
r = 6.36e-3; %m
Rm = 2.6; %ohm
Kt = 7.67e-3; %Nm/A
Km = 7.67e-3; %Vs/rad
Kg = 3.71;
Jm = 3.9e-7; %kg*m^2

% Set Gain
K = 15;

% Simulink Model
sim('prelab3.mdl');
open('prelab3.mdl');
plot(simout);xlabel('Time (ms)');ylabel('Response');
title('Step Response of Cart System');
stepinfo(simout.data,simout.time)
close('prelab3.mdl');

%% 5.3
r = 0.01482975; % pinion radius
res = 4096; % counts/rev
res_t = res/(2*pi*r); % theoretical encoder resolution
res_a = 44000; % actual encoder resolution from calculations
err = abs(res_t - res_a)/res_t*100; % percent error

disp(['actual encoder resolution:',num2str(res_a)])
disp(['percent error from theoretical:',num2str(err)])

%% 5.4
Kp = 60;
