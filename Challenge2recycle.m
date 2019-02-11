clear classes;
addPaths();

aValley = exp(9i*pi/10); %start of contour
bValley = exp(1i*pi/10); %end of contour
Pcoeffs = @(X,Y) [2/5 -X/2 0 -Y 0 0];

ballRad = 0.25;
Npts = 50;
degs = [5000 5000]; %Chebfun sample points in each direction
%[100 100] used to take 40 minutes, now it takes 12

%with latest speedup ran in four hours!!

%my estimations say that 12 hours should be enough time for 1000x10000
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