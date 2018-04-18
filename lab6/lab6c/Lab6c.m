%%Lab6c

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

a12 = 1;

a22 = -f/d/a;
a23 = -3/4*m*g/d;
b2 = e/d/a;

a34 = 1;

a42 = f/(4/3*Lp)/d/a;
a43 = 3/4*g/Lp + 3/4*m*g/d/(4/3*Lp);
b4 = -e/(4/3*Lp)/d/a;

res_p = 1/43960;
res_a = -1/651.9;

%%
A = [0 a12   0   0;
     0 a22 a23   0;
     0   0   0 a34;
     0 a42 a43   0];
B = [0; b2; 0; b4];
C = [1 0 0 0;
     0 0 1 0];
D = 0;

ref = [0.3 0 0 0];

x0 = 0.3;
a0 = 0.05;
ic = [0.3 0 0.05 0];
q2 = 0;
q4 = 0;

%% case1: nominal
q1 = 1;
q3 = 1;
r = 1;
q1_n = q1/x0^2;
q3_n = q3/a0^2;
r_n = r/6^2;

Q = [q1_n 0 0    0;
     0    0 0    0;
     0    0 q3_n 0;
     0    0 0    0];
R = r_n;

[K,~,E] = lqr(A,B,Q,R);
Ak = A-B*K;
Bk = B*K;

%this P is given in previous labs
P = [-10+15j -10-15j -12+17j -12-17j]; 
l = place(A',C',P);
L = l';
Cl = L*C;

%% run this after you run the cart
x = x';
y = C*x;
y = y';
r_x_h = r_x_h';
u = K*r_x_h;

figure;
plot(t,y(:,1),t,u,'-.');
legend('position','control');
xlabel('time (s)');
title('position (m) and control (V)');

figure;
plot(t,y(:,2),t,u,'-.');
legend('angle','control');
xlabel('time (s)');
title('angle (rad) and control (V)');

%% case2: high q1 = 5
q1 = 5;
q3 = 1;
r = 1;
q1_n = q1/x0^2;
q3_n = q3/a0^2;
r_n = r/6^2;

Q = [q1_n 0 0    0;
     0    0 0    0;
     0    0 q3_n 0;
     0    0 0    0];
R = r_n;
[K,~,E] = lqr(A,B,Q,R);
Ak = A-B*K;
Bk = B*K;

%% run this after you run the cart
x = x';
y = C*x;
y = y';
r_x_h = r_x_h';
u = K*r_x_h;
u = u';

figure;
plot(t,y(:,1),t,u,'-.');
legend('position','control');
xlabel('time (s)');
title('position (m) and control (V)');

figure;
plot(t,y(:,2),t,u,'-.');
legend('angle','control');
xlabel('time (s)');
title('angle (rad) and control (V)');

%% case3: high q3 = 5
q1 = 1;
q3 = 5;
r = 1;
q1_n = q1/x0^2;
q3_n = q3/a0^2;
r_n = r/6^2;

Q = [q1_n 0 0    0;
     0    0 0    0;
     0    0 q3_n 0;
     0    0 0    0];
R = r_n;
[K,~,E] = lqr(A,B,Q,R);
Ak = A-B*K;
Bk = B*K;

%% run this after you run the cart
x = x';
y = C*x;
y = y';
r_x_h = r_x_h';
u = K*r_x_h;
u = u';

figure;
plot(t,y(:,1),t,u,'-.');
legend('position','control');
xlabel('time (s)');
title('position (m) and control (V)');

figure;
plot(t,y(:,2),t,u,'-.');
legend('angle','control');
xlabel('time (s)');
title('angle (rad) and control (V)');

%% case4: high r = 100
q1 = 1;
q3 = 1;
r = 100;
q1_n = q1/x0^2;
q3_n = q3/a0^2;
r_n = r/6^2;

Q = [q1_n 0 0    0;
     0    0 0    0;
     0    0 q3_n 0;
     0    0 0    0];
R = r_n;
[K,~,E] = lqr(A,B,Q,R);
Ak = A-B*K;
Bk = B*K;

%% run this after you run the cart
x = x';
y = C*x;
y = y';
r_x_h = r_x_h';
u = K*r_x_h;
u = u';

figure;
plot(t,y(:,1),t,u,'-.');
legend('position','control');
xlabel('time (s)');
title('position (m) and control (V)');

figure;
plot(t,y(:,2),t,u,'-.');
legend('angle','control');
xlabel('time (s)');
title('angle (rad) and control (V)');

%% new ref 
% run lab6c_sine simulink model after picking
% a case from case1-4 and running that section to regenerate
% Ak and Bk 

% we pick case4 for high r
M = 0.05;