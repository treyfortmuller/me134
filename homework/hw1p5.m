syms m f k s F

% define matrices
A = [m*s^2+f*s+k, -f*s, 0; -f*s, m*s^2+3*f*s+k, -k-f*s; 0, -f*s+k, 2*f*s+k];
B = [0, -f*s, 0; F, m*s^2+3*f*s+k, -k-f*s; 0, -f*s+k, 2*f*s+k];
X1 = det(B)/det(A);

% substitute values to variables
m = 5; k = 7; f = 3;
subs(X1)
expand(3*s*(6*s + 7))