function I = contourPoly(aVal,bVal,polyCoeffs,freq, Npts)
%computes infinite contour integral from infiaVal to bVal of exp(i*freq*P(z)),
%where P is a polynomial with coefficients given by polyCoeffs
    R = monomialSettleRadius(polyCoeffs);
    [ ~, W ] = PathFinder( aVal, bVal, freq, Npts, [], 'settleRad', R, 'ainf', 'binf', 'gpolycoeffs', polyCoeffs);
    I = sum(W);
    
end