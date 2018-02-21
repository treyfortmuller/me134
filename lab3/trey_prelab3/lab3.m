%%ME134 - Lab 3
%Jenny Wong, Charlene Shong, Trey Fortmuller

%% Pre-lab 4.3 MATLAB Step Response
% finding an appropriate gain based on the given design requirements
% for a proportional controller for a cart on a rail

% define constants for the plant dynamics
m_c = 0.94; % [kg]
r = 6.36e-3; % [m]
R_m = 2.6; % [ohms]
K_t = 7.67e-3; % [Nm/A]
K_m = 7.67e-3; % [Vs/rad]
K_g = 3.72; % gear ratio
J_m = 3.9e-7; % [kgm^2]

% the common denominator in some of the state space matrix components
den = J_m * K_g^2 * R_m + r^2 * R_m * m_c;

% create the state space model for the plant
A = [0 1; 0 (K_t* K_m * K_g^2) / den];
B = [0; (r * K_t * K_g) / den];
C = [1 0];
D = 0;

sys = ss(A, B, C, D);

% gain K in the simulink model
K = 15;

% run the simulink model of the cart system and open the output
sim('prelab3.slx');
open('prelab3.slx');

% plot the step response of the closed loop system
plot(response);
title('Cart Controller Step Response');
xlabel('Time (seconds)');
ylabel('Position (meters)');

% get step response data
disp(stepinfo(sys));