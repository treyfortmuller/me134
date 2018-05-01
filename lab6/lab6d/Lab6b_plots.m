%%Plots for Lab6b
load('new-lab6d-data')

figure;
plot(tout,x(:,1))
title('Position vs. Time')
xlabel('Time (s)')
ylabel('Position (m)')

figure;
plot(tout,x(:,3))
hold on
plot(tout,ang_thresh*ones(size(tout)))
title('Angle vs. Time')
xlabel('Time (s)')
ylabel('Angle (rad)')

figure;
plot(tout,u)
title('Control Voltage vs. Time')
xlabel('Time (s)')
ylabel('Control Voltagec (V)')

figure;
plot(tout,xhat(:,1))
title('Observer Position vs. Time')
xlabel('Time (s)')
ylabel('Position (m)')

figure;
plot(tout,xhat(:,2))
title('Observer Velocity vs. Time')
xlabel('Time (s)')
ylabel('Velocity (m/s)')

figure;
plot(tout,xhat(:,3))
title('Observer Angle vs. Time')
xlabel('Time (s)')
ylabel('Angle (rad)')

figure;
plot(tout,xhat(:,4))
title('Observer Angular Velocity vs. Time')
xlabel('Time (s)')
ylabel('Angular Velocity (rad/s)')

E = 0.5.*Jm.*x(:,4).^2 - m.*g.*Lp.*(1-cos(x(:,3)));
figure;
plot(tout,E)
title('Energy vs. Time')
xlabel('Time (s)')
ylabel('Energy (J)')

