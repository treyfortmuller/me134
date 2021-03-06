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

% create the transfer function model of the plant
num = [r * K_t * K_g]; % the numerator

s2 = J_m * K_g^2 * R_m; % the coefficient on s^2
s = r^2 * R_m * m_c; % the coefficient on s
den = [s2 s]; % the denominator

plant = tf(num, den);

disp("The plant has pole(s): " + pole(plant));

% proportional control gain K in the simulink model
K = 15;

% % run the simulink model of the cart system and open the output
% sim('prelab3.slx');
% open('prelab3.slx');
% 
% % plot the step response of the closed loop system
% plot(simout);
% title('Cart Controller Step Response');
% xlabel('Time (seconds)');
% ylabel('Position (meters)');
% 
% % get the step response data
% stepinfo(simout.data, simout.time)