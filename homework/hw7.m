% ME134 HW 7

%% PI Controller
close all % close all the previous figures

% the uncompensated system
G = tf([1], [1, 17, 66, 72]); % the open loop transfer function
f1 = figure;
subplot(2, 2, 1);
rlocus(G) % plot the root locus
sgrid([0.5], []) % plot the line of zeta = 0.5

G_cl = feedback(126*G, 1) % the unitary feedback, uncompensated system
subplot(2, 2, 2);
step(G_cl) % plot of the step response of the uncompensated system
stepinfo(G_cl) % step response characterisitcs of the uncompenstated system

% PI compensated system
G_comp = tf([1, 0.1], [1, 17, 66, 72, 0]); % open loop compensated tf
subplot(2, 2, 3);
rlocus(G_comp) % root locus of the compensated closed loop system
sgrid([0.5], []) % plot the line of zeta = 0.5

G_comp_cl = feedback(125*G_comp, 1) % unitary feedback, compensated system
subplot(2, 2, 4);
step(G_comp_cl)
stepinfo(G_comp_cl)

% plotting the step response of the uncompensated and compensated closed
% loop systems superimposed
f2 = figure;
hold on;
step(G_cl);
step(G_comp_cl);

%% PD Controller
close all;

G = tf(1, [1, 30, 200, 0]); % the open loop tf
f1 = figure;
rlocus(G) % the root locus of the closed loop tf, to find he gain at zeta
sgrid(0.456, []);
damp(G) % get the open loop pole locations
% controlSystemDesigner(G)

K = 1160; % the gain for zeta = 0.456
G_cl = feedback(K*G, 1);
stepinfo(G_cl)

% get the angle between the ol poles and the desired cl pole
positive_real = [1, 0, 0]; % +real axis, with dim of 3 for cross product
des_pole1 = [-13.03, 25.43, 0]; % vector from the 1st ol pole to desired
des_pole2 = [-13.03 + 10, 25.43, 0];
des_pole3 = [-13.03 + 20, 25.43, 0];

theta1 = atan2d(norm(cross(positive_real,des_pole1)),dot(positive_real,des_pole1))
theta2 = atan2d(norm(cross(positive_real,des_pole2)),dot(positive_real,des_pole2))
theta3 = atan2d(norm(cross(positive_real,des_pole3)),dot(positive_real,des_pole3))

sum = theta1 + theta2 + theta3 % sum of the pole angles

theta_z = sum - 180 % the angular contribution required for the compensated pole

T = tf([1, 4.4732], [1, 30, 200, 0]) % the compensated open loop tf
f2 = figure;
rlocus(T); % root locus of the compensated system
sgrid(0.456, [])

K_comp = 720;

T_cl = feedback(2000*T, 1) % the compensated, closed loop transfer function
f3 = figure;
step(T_cl)
stepinfo(T_cl)

%% PID Controller