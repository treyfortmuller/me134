%% Prelab6a
%% 3.2.1
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

a34 = 1;

a42 = f/(4/3*Lp)/d/a;
a43 = 3/4*g/Lp + 3/4*m*g/d/(4/3*Lp);

b2 = e/d/a;
b4 = -e/(4/3*Lp)/d/a;

%% 3.2.2
A = [0 a12   0   0;
     0 a22 a23   0;
     0   0   0 a34;
     0 a42 a43   0]
B = [0; b2; 0; b4]

%% 3.3.1
disp('The Eigenvalues of the system are:');
disp(eig(A));

%% 3.3.2
Cx = [1 0 0 0]; % just position
Ca = [0 0 1 0]; % just angle

C_tot = [1 0 1 0]; % the total output

Gx = ss(A, B, Cx, 0);
Ga = ss(A, B, Ca, 0);
G_tot = ss(A, B, C_tot, 0) % the total, linearized open loop system in ss

% figure;
% step(Gx);
% title('Step Response for Position');
% 
% figure;
% step(Ga);
% title('Step Response for Pendulum Angle');

figure;
step(G_tot);
title('Step Response for Position + Pendulum Angle');

%% 3.3.3
evals_ref = [-2+10i -2-10i -1.6+1.3i -1.6-1.3i];
poly_ref = [1 7.2 121.05 349.8 442];

syms s k1 k2 k3 k4
K = [k1 k2 k3 k4];
det(s*eye(4)- (A-B*K))

alpha = [0 (1702048330515329)/1125899906842624 0 -(3865948661073583)/1125899906842624;
         (1702048330515329)/1125899906842624 0 -(3865948661073583)/1125899906842624 -(902507433127031)/1267650600228229401496703205376;
         0 -(5070589949573361625951928816354967)/150533508777102241427733505638400 -(902507433127031)/1267650600228229401496703205376 0;
         -(5070589949573361625951928816354967)/150533508777102241427733505638400 0 0 0];
     
beta = [7.2 - (7615247905447333)/1125899906842624;
        121.05 + (7356410423830389)/281474976710656;
        349.8 + (8358244827842790063191863187794119)/55459713759985036315480765235200;
        442];

K = alpha\beta;
K = K';
k1 = K(1);
k2 = K(2);
k3 = K(3);
k4 = K(4);

Ak = A-B*K;

disp('The K values are:');
disp(num2str(K));

disp('The Eigenvalues of the system are:');
disp(eig(Ak));

disp('The eigenvalues we want are:');
disp(evals_ref');

%% 3.3.4
Bk = B*K;

[num1,den1] = ss2tf(Ak,Bk,Cx,zeros(1,4),1)
figure;
bode(tf(num1,den1))

[num2,den2] = ss2tf(Ak,Bk,Ca,zeros(1,4),1)
figure;
bode(tf(num2,den2))

[num3,den3] = ss2tf(Ak,Bk,Cx+Ca,zeros(1,4),1)
figure;
bode(tf(num3,den3))

