clear classes;
addPaths();

aValley = exp(9i*pi/8); %start of contour
bValley = exp(1i*pi/8); %end of contour
Pcoeffs = @(X,Y) [1/4 0 -X/2 -Y 0];

ballRad = 0.25;
Npts = 15;
degs = [100 100]; %Chebfun sample points in each direction
%[100 100] used to take 40 minutes, now it takes 12
range = [-10 10 -10 10];
%?yt?xt^2/2+t^4/4

tic;
A31 = Aij3(aValley, bValley, Pcoeffs, 1, Npts, degs, range); 
T = toc;

%plot results.
%unscaled plot (x,y):
x = linspace(-10,10,1000);
[X, Y] = meshgrid(x,x);
figure(1);
imagesc(x,(x),abs(A31(X,Y)).');
xlabel('x');
ylabel('y');
set(gca,'Ydir','normal');
colorbar;
colormap jet;
title('|A_{31}(x,y)|');