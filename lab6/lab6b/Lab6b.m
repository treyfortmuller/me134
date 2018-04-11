%%Prelab6b
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

%%
evals_ref = [-2+10i -2-10i -1.6+1.3i -1.6-1.3i];
poly_ref = [1 7.2 121.05 349.8 442];

syms s k1 k2 k3 k4
K = [k1 k2 k3 k4];
det(s*eye(4)- (A-B*K));

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
Bk = B*K;
C = [1 0 0 0;
     0 0 1 0];
%%
K_lab = [-12.9796 -14.723 -47.8456 -6.5363];

%% 3.1
CO = ctrb(A,B);
OB = obsv(A,C);
rank(CO)
rank(OB)
% rank = 4 means controllable and observable

%% 3.2.1
% dimension of L should be : LC = 4x4, C = 2x4, -> L = 4x2;

%% 3.2.2
P = [-10+15j -10-15j -12+17j -12-17j];
% eig of (A-LC) = eig of (A' - C'*L')
l = place(A',C',P);
L = l'
Cl = L*C;

%% 3.3.1
% x_hd = Ax_h + BK(r-x_h)+ LC(x-x_h);
% x_d = Akx + Bkr
ref = [0 0 0 0];
ic = [0.1 0 5*pi/180 0];

%% 4.1

figure;
plot(t,y(:,1),t,y_h(:,1),'-.');
legend('y','y_h');
title('position (m)');

figure;
plot(t,y(:,2),t,y_h(:,2),'-.');
legend('y','y_h');
title('angle (rad)');

%% 4.2

%save('zero ref','x','x_h')
%save('zero ref per','x','x_h');
save('sine ref','x','x_h');

figure;
plot(t,x(:,1),t,x_h(:,1),'-.');
legend('x','x_h');
title('position (m)');

figure;
plot(t,x(:,2),t,x_h(:,2),'-.');
legend('x','x_h');
title('velocity (m/s)');

figure;
plot(t,x(:,3),t,x_h(:,3),'-.');
legend('x','x_h');
title('angle (rad)');

figure;
plot(t,x(:,4),t,x_h(:,4),'-.');
legend('x','x_h');
title('angular velocity (rad/s)');
