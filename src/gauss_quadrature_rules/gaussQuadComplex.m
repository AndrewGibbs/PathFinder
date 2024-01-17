function [z,w,dz] = gaussQuadComplex(a,b,numPts)
% transplants standard Gauss quad along complex line, w are real weights,
% but dz corresponds to z'(p) if p parametrises complex line segment

    % deal with special case where endpoints are equal
    if a == b
        z = a;
        w = 0;
        dz = 0;
        return;
    end

    % get length of interval
    L = abs(b-a);

    % get Gauss Legendre nodes on [-1,1]
    [s,w] = gausLegHC(numPts);

    % get unit length complex direction
    dz = (b - a)/L;

    % map Gauss points to complex line segment from a to b
    z = a + L*(s+1)*dz/2;

    % scale Gauss weights so they correspond line segment
    w = L*w/2;
    dz = repmat(dz,size(z));
end

