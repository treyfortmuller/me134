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

% height of the step input
step_height = 0.15;

% proportional controller gain K
K_array = [10, 20, 30, 40];

% the numerator and denominator coefficient arrays for the transfer
% function model of the plant
num = [0 0 (r*K_t*K_g)];
den = [(m_c*(r^2)*R_m + R_m*(K_g^2)*J_m) (K_t*K_m*(K_g^2)) 0];

% run the simulink model for various values of K
for i = 1:length(K_array)
    K = K_array(i); % pick out the value of K from the array
    
    % run the simulink model of the proportional controller
    sim('p_control_cart.mdl');
    open('p_control_cart.mdl');
    
    % plot the output of the simulink simulation
    plot(simout);
    hold on % plot on the same figure
end

% add a legend to differentiate the plots for different K
legend({'K = 14', 'K = 15', 'K = 16', 'K = 17'});

hold off


