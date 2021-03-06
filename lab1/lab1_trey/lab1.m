% Trey Fortmuller
% Lab 1

% constants for our RLC circuit
R = 2;
L = 1e-3;
c = 1e-3;

V = 1;

% numerically solving the ODEs
A = [0, (-1/L); (1/c), (-1/(c*R))];
B = [(1/L); 0];

RLCdynamics = @(t, x) A*(x) + B;

tspan = [0, 4e-2];
x0 = [0; 0];

[t,x] = ode45(RLCdynamics,tspan,x0);

figure(1);
plot(t, x(:,1), t, x(:,2));

% creating the state space model
C = [0, 1];
D = 0;

figure(2);
RLCss = ss(A,B,C,D);
step(RLCss);

% create a transfer function model
num = 1;
den = [L*c, L/R, 1];
RLCtf = tf(num, den);

figure(3);
step(RLCtf)

% create the simulink model
k1 = 1/L;
k2 = 1/c;
k3 = 1/(c*R);
sim('RLC');













