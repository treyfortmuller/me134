%% Prelab6b

%% setup for the open loop, linearized state space model
% system constants
M = 0.94;
m = 0.23;
Lp = 0.3302;

r = 6.36*10^-3;
Rm = 2.6;
Kt = 7.67*10^-3;
Km = 7.67*10^-3;
Kg = 3.71;
Jm = 3.9*10^-7;
g = 9.81;

a = M*r^2*Rm + Kg^2*Jm*Rm;
b = Kg^2*Kt*Km;
c = Kg*Kt*r;
d = M + m/4;
e = M*c;
f = M*b;

% A matrix elements
a12 = 1;
a22 = -f/d/a;
a23 = -3/4*m*g/d;
a34 = 1;
a42 = f/(4/3*Lp)/d/a;
a43 = 3/4*g/Lp + 3/4*m*g/d/(4/3*Lp);

% B matrix elements
b2 = e/d/a;
b4 = -e/(4/3*Lp)/d/a;

% constructing the matrices for the open loop, linearized state space sys
% the state vector is [x x_dot theta theta_dot]
A = [0 a12   0   0;
     0 a22 a23   0;
     0   0   0 a34;
     0 a42 a43   0
     0 0 0 0 ];
 
B = [0; b2; 0; b4];

C = [1 0 1 0];

D = 0;

% the open loop, linearized state space model of the inverted pendulum
G = ss(A, B, C, D);

%% 3.1 Controllability & Observability

% determining controllability
Co = ctrb(G); % the controllability matrix of G
UnCo = length(A) - rank(Co) % the number of uncontrollable states

% determining observability
Ob = obsv(G); % the observability matrix of G
UnOb = length(A) - rank(Ob) % the number of unobservable states

%% 3.2 Observer Design













