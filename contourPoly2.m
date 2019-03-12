function I = contourPoly2(aVal,bVal,polyCoeffs,freq, Npts)
%computes infinite contour integral from infiaVal to bVal of exp(i*freq*P(z)),
%where P is a polynomial with coefficients given by polyCoeffs
    [G, SPs_init, order] = NSDeetsFromPoly(polyCoeffs, 1e-16); %have set clumping to be the same
    contoursOut = getSDtopology(G,SPs_init,sum(order)+1,aVal,bVal,false,true,1);

    [~, w] = makeQuad(contoursOut,freq,Npts,G{1});
    I = sum(w);
 
%     R = monomialSettleRadius(polyCoeffs);
%     [ ~, W ] = PathFinder( aVal, bVal, freq, Npts, [], 'settleRad', R, 'ainf', 'binf', 'gpolycoeffs', polyCoeffs);
%     I_check = sum(W);
    
end