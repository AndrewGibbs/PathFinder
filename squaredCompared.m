%PathFinder appears to have different accuracy for g(x)=x^2 for
%(a,b)=(-1,0) or (a,b)=(0,1)

g = [1 0 0];
freq = 100;
Npts = 100;

[~,wL]=PathFinderQuad(-1, 0, g, freq, Npts, 'plot');
IL = sum(wL);
JL = integral(@(x) exp(1i*freq*x.^2),-1, 0,'RelTol',1e-12);

figure(2);
[~,wR]=PathFinderQuad(0, 1, g, freq, Npts, 'plot');
IR = sum(wR);
JR = integral(@(x) exp(1i*freq*x.^2),0, 1,'RelTol',1e-12);