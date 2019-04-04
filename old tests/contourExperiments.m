C = .8;

%g = @(z)  (z-1).*(z+1).*(z+1i);
g = @(z)  (z-.1).*(z+.1).*(z+1.8i);
x = linspace(-2.5,2.5,1000);
z = x + 1i*x.';
contour(x,x,abs(g(z)),[C C]);
c = contourc(x,x,abs(g(z)),[C C]);
c_split = contourdata(c);