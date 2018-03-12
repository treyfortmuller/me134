clear all

%% problem 2
syms s
g = 200*(s+9)*(s+13)*(s+10)/(s*(s+25)*(s^2+2*s+17));
t = 1/(1+g);
% r = 15/s; % input for (a)
% r = 35/(s^2); % input for (b)
r = 110/(s^3); % input for (c)
e = s*t*r; simplify(e)
limit(e, s, 0)

%% problem 3
syms s
g = (s+2)/((s+4)*(s+7)); % step input
% g = s*g; % ramp input
g = s^2*g; % parabolic input
limit(g, s, 0) % for static errors
e = 3/(limit(g, s, 0)) % for e(s)

%% problem 5
numg = poly([-1 -5]);
deng = [1 4 29];
G = tf(numg,deng)
rlocus(G)
% z = 0.5;
% sgrid(z,0)