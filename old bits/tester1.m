clear classes;
ballRad = .2;
G = {@(x) x.^3-x, @(x) 3*x.^2 - 1, @(x) 6*x, @(x) 6, @(x) 0};
SPs_init = [sqrt(1/3) -sqrt(1/3)];
order = 3;
valleys = exp(2i*pi*(1/4 + (1:order))/order);
aValley = valleys(1); bValley = valleys(2);

contoursOut = getSDtopography(G,SPs_init,order,aValley,bValley,true);

[z, w] = makeQuad(contoursOut,1,15,G{1});
hold on;
plot(z,'x');