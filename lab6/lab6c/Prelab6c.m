%%Prelab6c
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

%%
A = [0 a12   0   0;
     0 a22 a23   0;
     0   0   0 a34;
     0 a42 a43   0];
B = [0; b2; 0; b4];
C = [1 0 0 0;
     0 0 1 0];
D = 0;
%%
% evals_ref = [-2+10i -2-10i -1.6+1.3i -1.6-1.3i];
% poly_ref = [1 7.2 121.05 349.8 442];
% K = place(A,B,evals_ref);
% Ak = A-B*K;
% Bk = B*K;

%%
%K_lab = [-12.9796 -14.723 -47.8456 -6.5363];

%% 
% P = [-10+15j -10-15j -12+17j -12-17j];
% % eig of (A-LC) = eig of (A' - C'*L')
% l = place(A',C',P);
% L = l';
% Cl = L*C;

%% 3.1
%dim Q = 4x4 because x is 4x1. dim R = 1x1 because u is 1x1
ref = [0 0 0 0];
x0 = 0.3;
a0 = 0.05;
ic = [0.3 0 0.05 0];
q2 = 0;
q4 = 0;
disp('case1: nominal');
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

[K,S,E] = lqr(A,B,Q,R);
Ak = A-B*K;
Bk = B*K;
disp(['The K values are;',num2str(K)])
disp(['The eigen values/CL poles are;',num2str(E')])

%%make obsever poles far from CL poles (6 times)
P = 6*E';
l = place(A',C',P);
L = l'
Cl = L*C;

sim('pl6c')

x = x';
y = C*x;
y = y';
r_x_h = r_x_h';
u = K*r_x_h;
u = u';
disp(['max position deviation is:', num2str(max(abs(y(:,1))))])
disp(['max angle deviation is:', num2str(max(abs(y(:,2))))])
disp(['max abs control is:', num2str(max(abs(u)))]);

figure;
plot(t,y(:,1),t,u,'-.');
legend('position','control');
xlabel('time (s)');
title('position (m) and control (V)');
xlim([0 2]);

figure;
plot(t,y(:,2),t,u,'-.');
legend('angle','control');
xlabel('time (s)');
title('angle (rad) and control (V)');
xlim([0 2]);

%% 3.2
%%case2
disp('case2: q3 = 0.01 << 1');
q1 = 1;
q3 = 0.01;
r = 1;
q1_n = q1/x0^2;
q3_n = q3/a0^2;
r_n = r/6^2;

Q = [q1_n 0 0    0;
     0    0 0    0;
     0    0 q3_n 0;
     0    0 0    0];
R = r_n;
[K,S,E] = lqr(A,B,Q,R);
Ak = A-B*K;
Bk = B*K;
disp(['The K values are;',num2str(K)])
disp(['The eigen values/CL poles are;',num2str(E')])

sim('pl6c')

x = x';
y = C*x;
y = y';
r_x_h = r_x_h';
u = K*r_x_h;
u = u';

disp(['max position deviation is:', num2str(max(abs(y(:,1))))])
disp(['max angle deviation is:', num2str(max(abs(y(:,2))))])
disp(['max abs control is:', num2str(max(abs(u)))]);
%small q3 gives bigger change in x and theta but smaller control

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

%%case3
disp('case3: q3 = 100 >> 1');
q1 = 1;
q3 = 100;
r = 1;
q1_n = q1/x0^2;
q3_n = q3/a0^2;
r_n = r/6^2;

Q = [q1_n 0 0    0;
     0    0 0    0;
     0    0 q3_n 0;
     0    0 0    0];
R = r_n;
[K,S,E] = lqr(A,B,Q,R);
Ak = A-B*K;
Bk = B*K;
disp(['The K values are;',num2str(K)])
disp(['The eigen values/CL poles are;',num2str(E')])

sim('pl6c')

x = x';
y = C*x;
y = y';
r_x_h = r_x_h';
u = K*r_x_h;
u = u';

disp(['max position deviation is:', num2str(max(abs(y(:,1))))])
disp(['max angle deviation is:', num2str(max(abs(y(:,2))))])
disp(['max abs control is:', num2str(max(abs(u)))]);
%big q3 gives smaller change in x and same in theta but bigger control

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

%%case4
disp('case4: r = 0.01 << 1');
q1 = 1;
q3 = 1;
r = 0.01;
q1_n = q1/x0^2;
q3_n = q3/a0^2;
r_n = r/6^2;

Q = [q1_n 0 0    0;
     0    0 0    0;
     0    0 q3_n 0;
     0    0 0    0];
R = r_n;
[K,S,E] = lqr(A,B,Q,R);
Ak = A-B*K;
Bk = B*K;
disp(['The K values are;',num2str(K)])
disp(['The eigen values/CL poles are;',num2str(E')])

sim('pl6c')

x = x';
y = C*x;
y = y';
r_x_h = r_x_h';
u = K*r_x_h;
u = u';

disp(['max position deviation is:', num2str(max(abs(y(:,1))))])
disp(['max angle deviation is:', num2str(max(abs(y(:,2))))])
disp(['max abs control is:', num2str(max(abs(u)))]);
%small r gives slightly smaller change in x and slightly bigger change in theta but bigger control

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

%%case5
disp('case5: r = 100 >> 1');
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
[K,S,E] = lqr(A,B,Q,R);
Ak = A-B*K;
Bk = B*K;
disp(['The K values are;',num2str(K)])
disp(['The eigen values/CL poles are;',num2str(E')])

sim('pl6c')

x = x';
y = C*x;
y = y';
r_x_h = r_x_h';
u = K*r_x_h;
u = u';

disp(['max position deviation is:', num2str(max(abs(y(:,1))))])
disp(['max angle deviation is:', num2str(max(abs(y(:,2))))])
disp(['max abs control is:', num2str(max(abs(u)))]);
%big r gives slightly smaller change in x and same theta but smaller control

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

%% 3.3
%position will first increase before converging to zero shows that the cart
%is moving to swing the angle closer to 0
