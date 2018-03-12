%initial conditions
R = 2; %[ohm]
L = 10^-3; %[H]
c = 10^-3; %[F]
V = 1; %[V]
x0 = [0; 0];
tspan = [0 4*10^-2];
A = [0, -1/L; 1/c, -1/(R*c)];
B = [1/L; 0]; C = [0 1]; D = 0;

RLCdynamics = @(t,x) [0, -1/L; 1/c, -1/(R*c)]*x + [1/L; 0]*V;
[t,x] = ode45(RLCdynamics,tspan,x0);

%4.1
figure(1);
plot(t,x(:,1),'b',t,x(:,2),'r');
xlabel('Time, t (s)'); ylabel('States, x');
legend('Current','Capacitor Voltage','Location','best')
title('Current i and Capacitor Voltage v_c vs. Time t')

%4.2
figure(2);
RLCss = ss(A,B,C,D);
step(RLCss);
title('Step Response with State Space Model')

%4.3
figure(3);
RLCtf = tf(1,[L*c,L/R,1]);
hold on;
step(RLCtf); %step(ss2tf(RLCss));
title('Step Response with Transfer Function')

%4.4
K1 = 1/L; K2 = 1/c; K3 = 1/(R*c);
sim('RLC');
