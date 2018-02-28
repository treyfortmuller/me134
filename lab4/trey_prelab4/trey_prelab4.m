%%ME134 - Lab 4
%Jenny Wong, Charlene Shong, Trey Fortmuller

%% Pre-lab 4.1.1 Plant Model

% define constants for the plant dynamics
m_c = 0.94; % [kg]
r = 6.36e-3; % [m]
R_m = 2.6; % [ohms]
K_t = 7.67e-3; % [Nm/A]
K_m = 7.67e-3; % [Vs/rad]
K_g = 3.72; % gear ratio
J_m = 3.9e-7; % [kgm^2]

% create the transfer function model of the plant
num = [r * K_t * K_g]; % the numerator

s2 = J_m * K_g^2 * R_m; % the coefficient on s^2
s = r^2 * R_m * m_c; % the coefficient on s
den = [s2 s 0]; % the denominator

plant = tf(num, den); % the plant dynamics represented as a TF

% find and display the poles of the the plant TF
disp("The plant has pole(s): " + pole(plant));