clear classes; 
addPaths();

Npts = 100; %number of quadrature points (for all types of quadrature)
freq = 1;
P = @(x,y) [1 0 x y 0];

order = 4;

valleys = exp(2i*pi*(1/4 + (1:order))/order);

aVal =valleys(2);
bVal =valleys(4);
        

errs = zeros(9,5);
I1vals = errs;
xCount = 0;
for x = -8:2:8
    xCount = xCount+1;
    yCount = 1;
    for y = 0:2:8
        yCount = yCount +1;
        gCoeffs = P(x,y);
        [G, SPs_init, orders] = NSDeetsFromPoly(gCoeffs, 1e-16);

        %old version
        R = 10;
        [zv1,wv1] = PathFinder( aVal, bVal, freq, 25, [], 'settleRad', R, 'ainf', 'binf', 'gpolycoeffs', gCoeffs);
        I1 = sum(wv1);
        
        %new version
        [contoursOut1] = getSDtopology(G,SPs_init,order,aVal,bVal,false);
        [z1, w1] = makeQuad(contoursOut1,1,Npts,G{1});
        hold on;
        plot(z1,'x');
        hold off;
        I2 = sum(w1);
        fprintf('x = %f, y = %f, err = %f\n',x,y,norm(I1-I2));
        errs(xCount,yCount) = norm(I1-I2);
        % I1
        % I2
        %norm(I1-I2)/norm(I1)
        I1vals(xCount,yCount) = I1;
    end
end