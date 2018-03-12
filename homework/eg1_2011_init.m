%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Script for initialising eg1_diag2.mdl
%
% 11/03/04
%
% 08/02/11 - MCT: slightly updated
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Enter variables required for simulating model
%
% This will put the following variables with their
% numerical values into the Matlab workspace
%
% To find out what variables you have in the workspace
% (and thus which can be used in Simulink) type 'who' or 'whos'
%

M1  =  4;
M2  =  2;
B   =  1;
K   =  1;

% Simulate model

sim('eg1_2011');

% Plot response

plot(y.time,y.signals.values);
grid;
xlabel('Time [sec]');
ylabel('v2 [m/s]');
