%%Lab2

%%4.1.2
K_array = 10:13;
figure;
for i = 1:length(K_array)
    K = K_array(i);
    sim('fig1');
    subplot(2,2,i);
    plot(simout.Time, simout.Data);
    hold on;
    plot(simin.Time, simin.Data,'.-');
    xlabel('Time (s)');
    legend('Step Response', 'Step Input');
    t = 'Oscillatory Response with K =  ';
    t = strcat(t, num2str(K));
    title(t);
    close_system('fig1');
end

%% 4.1.3
K_array = 13:2:19;
figure;
for i = 1:length(K_array)
    K = K_array(i);
    sim('fig1');
    if i == 1
        plot(simin.Time, simin.Data,'.-');
    end
    hold on;
    plot(simout.Time, simout.Data);
    
    close_system('fig1');
end

xlabel('Time (s)');
legend('Step Input','K = 13', 'K = 15', 'K = 17', 'K = 19');
t = 'Stable Step Response with variable K > 12';
title(t);

%% 4.1.4
K_array = 50:0.1:100;
done = 0;
Kos = 0;
for i = 1:length(K_array)
    K = K_array(i);
    tfk = tf([K 2*K],[1 K-12 2*K]);
    si = stepinfo(tfk);
    os = si.Overshoot;
    if os <= 25
        if ~done
            Kos = K;
            s = strcat('K:', num2str(K), ' has overshoot percentage of:', num2str(os));
            disp(s)
        end
        break
    end
end

K_array = [30, 40 ,59.8, 65, 80];
for i = 1:length(K_array)
    K = K_array(i);
    sim('fig1');
    if i == 1
        plot(simout.Time,1.25*ones(length(simout.Time)),'-.');
    end    
    hold on;
    plot(simout.Time, simout.Data);
    close_system('fig1');
end


xlabel('Time (s)');
legend('Bound at 1.25', 'K = 30', 'K = 40', 'K = 59.8', 'K = 65', 'K = 80');
t = 'Percent Overshoot <= 25% for variable K';
title(t);

%% 4.2.2 and 4.2.3
c = 0.25; %velocity damping term
g = 9.81; %gravity constant
m = 1; %mass
l = 2;

figure;
sim('fig2_sine');
plot(simout2.Time, simout2.Data);
hold on;
plot(simin2.Time, simin2.Data);
xlabel('Time (s)');
legend('Radians against vertical', 'Pulse Input');
close_system('fig2_sine');

%% 4.2.4 and 4.2.5
figure;
sim('fig2');
plot(simout2.Time, simout2.Data);
hold on;
plot(simin2.Time, simin2.Data);
xlabel('Time (s)');
legend('Radians against vertical', 'Pulse Input');
close_system('fig2');

