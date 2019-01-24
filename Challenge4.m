%note from Dave:
%Re challenge 4, the A52 integral. 
%Yes I should have warned you that the integral is exp large in certain regions of the complex plane. 
%I've done the basic qualitative steepest descent analysis for this integral
%But if you were able to restrict evaluation and plotting to the region y>-4x^3/27 you should avoid any exp large contributions. 
%(In particular the point (1,-10) is a bad one.) 

clear classes;
addPaths();

aValley = exp(17i*pi/10); %start of contour
bValley = exp(1i*pi/2); %end of contour
Pcoeffs = @(X,Y) [2/5 -X/2 0 -Y 0 0];%?yt2?xt4/2+2t5/5

ballRad = 0.25;
Npts = 50;
degs = [100 100]; %Chebfun sample points in each direction
%[100 100] used to take 40 minutes, now it takes 12

%my estimations say that 12 hours should be enough time for 1000x10000
range = [-10 10 -10 10];
%?yt?xt^2/2+t^4/4

includeRegion = @(x,y) y>-4*x.^3/27;

tic;
A52 = Aij2(aValley, bValley, Pcoeffs, 1, Npts, degs, range, includeRegion); 
T = toc;

%plot results.
%unscaled plot (x,y):
x = linspace(-10,10,1000);
[X, Y] = meshgrid(x,x);
figure(1);
imagesc(x,(x),abs(A52(X,Y)).');
xlabel('x');
ylabel('y');
set(gca,'Ydir','normal');
colorbar;
colormap jet;
title('|A_{52}(x,y)|');