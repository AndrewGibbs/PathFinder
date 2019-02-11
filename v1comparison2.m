clear classes; 
addPaths();

% difference in results suggests an error in one of the routines.
% increasing RectTol in PathFinder to a big enough threshold such that it
% contains both stationary points appears to fix this.

%this suggests that the error is in the way the infinite path of PathFinder
%contains a finite path component

Npts = 100; %number of quadrature points (for all types of quadrature)
freq = 1;
gCoeffs = [1 0 .05 0];

order = 3;

valleys = exp(2i*pi*(1/4 + (1:order))/order);

aVal =valleys(2);
bVal =valleys(1);
        
[G, SPs_init, orders] = NSDeetsFromPoly(gCoeffs, 1e-16);

%old version
R = 10;
figure(1);
[zv1,wv1] = PathFinder( aVal, bVal, freq, 100, [], 'settleRad', R, 'ainf', 'binf', 'gpolycoeffs', gCoeffs, 'visuals on');
I1 = sum(wv1);

%new version
figure(2)
[contoursOut1] = getSDtopology(G,SPs_init,order,aVal,bVal,true);
[z1, w1] = makeQuad(contoursOut1,1,Npts,G{1});
hold on;
plot(z1,'x');
hold off;
I2 = sum(w1);
err = I1-I2