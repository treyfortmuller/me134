clear all

%% problem 2
syms s K
A = [3 2;-2 -4];
B = [2;1];
C = [1 1];
X0 = [1;2];
U = s/(s^2+4); %cos(2t)
I = [1 0;0 1];
X = ((s*I-A)^-1)*(X0+B*U);
Y = C*X;Y = simplify(Y);
y = ilaplace(Y); pretty(y);
eig(A)

%% problem 3
syms s K
A = [0 1;-1 0];
B = [1;0];
C = [3 2];
X0 = [0;0];
U = 1/s; %unit step
I = [1 0;0 1];
X = ((s*I-A)^-1)*(X0+B*U);
Y = C*X;Y = simplify(Y);
x = ilaplace(X); pretty(x)
y = ilaplace(Y); pretty(y)
eig(A)

%% problem 4
syms s K
g = (K*(s+1)/(s*(s-2)*(s+5)));
G = g/(1+g); G = simplify(G)

%% problem 5
syms s K
g = 100/(s^4 + 2*s^3 + 20*s^2 + 5*s + 50);
h = 1/s;
G = g/(1+h*g); G = simplify(G)
