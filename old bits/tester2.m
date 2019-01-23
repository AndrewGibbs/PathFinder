clear classes;
ballRad = 0.25;
lilbit = 1i;
Npts = 50;
G = {@(x) x.^3-lilbit*x, @(x) 3*x.^2 - lilbit, @(x) 6*x, @(x) 6, @(x) 0};
SPs_init = [sqrt(lilbit/3) -sqrt(lilbit/3)];

order = 3;
valleys = exp(2i*pi*(1/4 + (1:order))/order);
aValley = valleys(1); bValley = valleys(3);

contoursOut = getSDtopography(G,SPs_init,order,aValley,bValley,true);

[z, w] = makeQuad(contoursOut,1,Npts,G{1});
I = sum(w);
hold on;
plot(z,'x');
hold off;

[ ~, W ] = PathFinder( aValley, bValley, 1, Npts, [], 'settleRad', Npts, 'ainf', 'binf', 'gpolycoeffs', [1 0 -lilbit 0],'visuals on');
I_check = sum(W);

abs(I-I_check)/abs(I_check)