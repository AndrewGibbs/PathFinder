clear classes; 
addPaths();

Npts = 5; %number of quadrature points (for all types of quadrature)

preSPs = [-.5i .5i -1-1.7i 1-2i 2]; %this should be chosen to be as nasty as possible, to test the code.

% - - - - - - - - - - - - - - - - - -

order = length(preSPs)+1;

dgCoeffs = poly(preSPs);

gCoeffs = [dgCoeffs./(order:-1:1) 0];

order = length(gCoeffs)-1;

valleys = exp(2i*pi*(1/4 + (1:order))/order);

a = 1;
b = -1;
%G = { @(x)x.^3-a*x, @(x) 3*x.^2-a, @(x) 6*x, @(x) 6, @(x) 0};
[G, SPs_init, orders] = NSDeetsFromPoly(gCoeffs, 1e-16);
[contoursOut] = getSDtopology(G,SPs_init,sum(orders)+1,a,b,true,false);
xlim([-5 5]);
ylim([-5 5]);
[z, w] = makeQuad(contoursOut,1,Npts,G{1},false,[a b]);
hold on;
plot(z,'kx');
hold off;