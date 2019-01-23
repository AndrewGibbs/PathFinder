%must have Chebfun and PathFinder added to Matlab path before running this
%code:
clear;
%example parameters:
aValley = exp(9i*pi/10); %start of contour
bValley = exp(1i*pi/10); %end of contour
Pcoeffs = @(X,Y) [2/5 -1/2*X 0 -Y 0 0]; %coeffs of polynomial phase
Npts = 12; % quad points used for NSD
degs = [200 200]; %Chebfun sample points in each direction
range = [-10 10 -10 10]; %(xMin, xMax)x(yMin,yMax) in R2
freq = 1; %frequency of wave, set to one for these problems

% - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - %
      
%run and time/profile:
%profile on; 
tic;
A31 = Aij(aValley, bValley, Pcoeffs, freq, Npts, degs, range); 
T = toc; 
%profile viewer; profile off;
%(profiler is pretty useless when running in parallel!)
fprintf('\nRan in %f secs',T);

% - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - %

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
%rescaled result (x0,y0):
k = 20;
figure(2);
imagesc(x/sqrt(k),(x)/(k^(3/4)),real(exp(1i*k*X/sqrt(k)).'.*A31(X,Y)).');
xlabel('x_0');
ylabel('y_0');
set(gca,'Ydir','normal');
colorbar;
colormap jet;
title('Re[A_{31}(x_0,y_0)exp(ikx_0)]');

beep;