%% Prelab 4
m = 0.94;
r = 6.36*10^-3;
Rm = 2.6;
Kt = 7.67*10^-3;
Km = 7.67*10^-3;
Kg = 3.71;
Jm = 3.9*10^-7;

a = m*r*r*Rm + Kg*Kg*Jm*Rm;
b = Kg*Kg*Kt*Km;
c = Kg*Kt*r;

K = 15;

%% 4.1.1
Mos = 8/100;
tr = 0.16;

e_array = linspace(0,0.9,1000);
m = @(ep) exp(-pi.*ep./sqrt(1-ep.^2));
M = m(e_array);
index = find((Mos-M) < 0.0005);
e_approx = e_array(index(end))

wn = (1.76*e_approx^3 - 0.417*e_approx^2 + 1.039*e_approx +1)/tr

%% 4.1.2

k_array = linspace(10,60,6);
figure;
i = 1;
info = 0;
for K = k_array
    sim('pl4_p');
%     if i == 1
%         plot(simin.Time, simin.Data,'-.');
%         i = 0;
%     end
    hold on
    plot(simout.Time, simout.Data);
%     info = stepinfo(simout.Time, simout.Data);
%     disp(['Rise Time for K=', num2str(K), ' is:',num2str(info.RiseTime)])
%     disp(info.Overshoot)
    cfinal = simout.Data(end);
    percent_os = (max(simout.Data) - cfinal)/ cfinal * 100;
    time1_index = find(simout.Data >= 0.1*cfinal,1);
    time1 = simout.Time(time1_index);
    time9_index = find(simout.Data >= 0.9*cfinal,1);
    time9 = simout.Time(time9_index);
    rise_time = time9 - time1;
    
    disp(['Rise Time for K=', num2str(K), ' is:',num2str(rise_time)])
    disp(['Percent Overshoot for K=', num2str(K), ' is:', num2str(percent_os), '%'])

end
title('Proportional Controller Step Response with Varying K');
xlabel('Time (s)');
legend('K = 10','K = 20','K = 30', 'K = 40', 'K = 50', 'K = 60');
close_system('pl4_p');

%% 
k_array = linspace(30,40,500);
for K = k_array
    sim('pl4_p');
    
    %info = stepinfo(simout.Time, simout.Data);
    %disp(['Rise Time for K:', num2str(K), ' is:',num2str(info.RiseTime)])
    %disp(info.Overshoot)
    cfinal = simout.Data(end);
    percent_os = (max(simout.Data) - cfinal)/ cfinal * 100;
    time1_index = find(simout.Data >= 0.1*cfinal,1);
    time1 = simout.Time(time1_index);
    time9_index = find(simout.Data >= 0.9*cfinal,1);
    time9 = simout.Time(time9_index);
    rise_time = time9 - time1;
    
    if rise_time <= tr
        %plot(simin.Time, simin.Data,'-.');
        %hold on
        figure;
        plot(simout.Time, simout.Data);
        disp(['Meet RT criteria at K = ', num2str(K)])
        disp(['Rise Time for K=', num2str(K), ' is:',num2str(rise_time)])
        disp(['Percent Overshoot for K=', num2str(K), ' is:', num2str(percent_os), '%'])
        title('Min K for Rise Time Requirement');
        xlabel('Time (s)');
        ylabel('Position (m)');
        break
    end
end
close_system('pl4_p');

%% 
h_p = tf([c/a],[1 b/a 0]);
figure;
rlocus(h_p)

%% 4.1.3
h_pd = tf([1 12],[1/250 1]);
figure;
rlocus(h_pd)

%%
kd_array = linspace(4,5,100);
for kd = kd_array
    sim('pl4_pd');
    cfinal = simout.Data(end);
    percent_os = (max(simout.Data) - cfinal)/ cfinal * 100;
    time1_index = find(simout.Data >= 0.1*cfinal,1);
    time1 = simout.Time(time1_index);
    time9_index = find(simout.Data >= 0.9*cfinal,1);
    time9 = simout.Time(time9_index);
    rise_time = time9 - time1;

    if rise_time <= tr && percent_os/100 <= Mos
        figure;
        plot(simout.Time, simout.Data);
        disp(['Rise Time for Kd=', num2str(kd), ' is:',num2str(rise_time)])
        disp(['Percent Overshoot for Kd=', num2str(kd), ' is:', num2str(percent_os), '%'])
        title('Min Kd for Rise Time and Percent OverShoot Requirement');
        xlabel('Time (s)');
        ylabel('Position (m)');
        break;
    end
end
close_system('pl4_pd');

%%
kd_array = linspace(4,50,100);
kd_pass = [];
figure;
for kd = kd_array
    sim('pl4_pd');
    cfinal = simout.Data(end);
    percent_os = (max(simout.Data) - cfinal)/ cfinal * 100;
    time1_index = find(simout.Data >= 0.1*cfinal,1);
    time1 = simout.Time(time1_index);
    time9_index = find(simout.Data >= 0.9*cfinal,1);
    time9 = simout.Time(time9_index);
    rise_time = time9 - time1;

    if rise_time <= tr && percent_os/100 <= Mos
%         hold on
%         plot(simout.Time, simout.Data);
%         disp(['Rise Time for Kd=', num2str(kd), ' is:',num2str(rise_time)])
%         disp(['Percent Overshoot for Kd=', num2str(kd), ' is:', num2str(percent_os), '%'])
        kd_pass = [kd_pass kd];
    end
end

disp(['The range of acceptable kd values are from:', num2str(kd_pass(1)),' to:', num2str(kd_pass(end))])

for q = 1:4
    kd = kd_pass(floor(length(kd_pass)/ 4 * q));
    hold on
    plot(simout.Time, simout.Data);
    disp(['Rise Time for Kd=', num2str(kd), ' is:',num2str(rise_time)])
    disp(['Percent Overshoot for Kd=', num2str(kd), ' is:', num2str(percent_os), '%'])
end

title('Valid Kd for Rise Time and Percent OverShoot Requirement');
xlabel('Time (s)');
ylabel('Position (m)'); 
close_system('pl4_pd');

%%
kd_array = linspace(0,10,100);
for kd = kd_array
    sim('pl4_pd15');
    cfinal = simout.Data(end);
    percent_os = (max(simout.Data) - cfinal)/ cfinal * 100;
    time1_index = find(simout.Data >= 0.1*cfinal,1);
    time1 = simout.Time(time1_index);
    time9_index = find(simout.Data >= 0.9*cfinal,1);
    time9 = simout.Time(time9_index);
    rise_time = time9 - time1;

    if rise_time <= tr && percent_os/100 <= Mos
        figure;
        plot(simout.Time, simout.Data);
        disp(['Rise Time for Kd=', num2str(kd), ' is:',num2str(rise_time)])
        disp(['Percent Overshoot for Kd=', num2str(kd), ' is:', num2str(percent_os), '%'])
        title('Min Kd for Rise Time and Percent OverShoot Requirement');
        xlabel('Time (s)');
        ylabel('Position (m)');
        break;
    end
end
disp('Cannot fullfill both requirements with a zero at 15');
close_system('pl4_pd15');

