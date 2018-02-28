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
K = 25.7;

%% Simulink Model
sim('prelab3.mdl');
open('prelab3.mdl');
plot(simout);xlabel('Time');ylabel('Response');
title('Step Response of Cart System');
stepinfo(simout.data,simout.time)

