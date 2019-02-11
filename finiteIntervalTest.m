gCoeffs = [1 0 0];
Npts = 5;
freq = 1;
addPaths();
[G, SPs_init, orders] = NSDeetsFromPoly(gCoeffs, 1e-16);
[contoursInSeq] = getSDtopology(G,SPs_init,sum(orders)+1,-1,1,true,false);
xlim([-2.1 2.1]);
ylim([-2 2]);
[z, w] = makeQuad(contoursInSeq, freq, Npts, G, NaN, false);
hold on;
plot(z,'x');
hold off;