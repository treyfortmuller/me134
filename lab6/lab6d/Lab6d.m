
M = 0.94;
m = 0.23;
Lp = 0.3302;
Rm = 2.6;
Kt = 7.67e-3;
Km = 7.67e-3;
Kg = 3.71;
Jm = 3.9e-7;
r = 6.36e-3;
g = 9.8;

a12 = 1;
a34 = 1;
a22 = -1/(M+m*0.25+Kg*Kg*Jm/r/r)*Kg*Kg*Kt*Km/r/r/Rm;
a23 = -1/(M+0.25*m+Kg*Kg*Jm/r/r)*0.75*m*g;
a42 = 0.75/Lp*Kt*Km*Kg*Kg/r/r/Rm/(Kg*Kg*Jm/r/r+M+0.25*m);
a43 = 3*g/4/Lp+0.75/Lp*3*m*g/4/(Kg*Kg*Jm/r/r+M+0.25*m);
b2 = 1/(Kg*Kg*Jm/r/r+M+0.25*m)*Kg*Kt/r/Rm;
b4 = -0.75/Lp*1/(Kg*Kg*Jm/r/r+M+0.25*m)*Kt*Kg/r/Rm;

A = [0 a12 0 0;0 a22 a23 0;0 0 0 a34;0 a42 a43 0];
B = [0;b2;0;b4];
C = [1 0 0 0;0 0 1 0];
C1 = [1 0;0 1];
D = [0;0];
sys = ss(A,B,C,D);
%% Calculate L
po = [-10 + 15j, - 10 - 15j, -12 - 17j, -12 + 17j ];
L = place(A',C',po)'

%% LQR
q1 = 1; %normalized values
q3 = 5;
r = 1;

R = r/6^2;
Q = [q1/(0.3)^2 0 0 0;
     0 0 0 0;
     0 0 q3/(0.05)^2 0;
     0 0 0 0];
 
 K = lqr(A,B,Q,R)
 
 a = A - B*K;
 b = B*K;
 Cl = L *C;
 ref = [0; 0; 0; 0];
 
 c_lp = 0.016;
 ang_thresh = 10*pi/180;
 SAT = 4;
 K_pump = 300;
 
%  sim('Lab6cPremodel')
%  
%  u = zeros(length(x.time),1);
% for n=1:length(x.time)
%     u = K * (r-xhat.data');
% end
%     

% %% Plot
% figure;
% plot(tout,u);
% title('control action over simulation');
% xlabel('Time (s)');
% ylabel('control action (u)');
% 
% figure;
% plot(tout,y);
% title('output over simulation');
% xlabel('Time (s)');
% ylabel('output (y)');
% 
% figure;
% plot(x);
% 
% xmax = max(abs(x.data(:,1)))
% thetamax = max(abs(x.data(:,3)))
% umax = max(abs(u))