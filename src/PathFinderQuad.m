function [z,w] = PathFinderQuad(a, b, phaseIn, freq, Npts, infContour)
%returns weights and nodes for efficient evaluation of oscillatory integral
    
    %get info about stationary points:
    [phase, stationaryPoints, ~, valleys] = getInfoFromPhase(phaseIn);
    
    %cover each stationary point:
    [covers, intersectionMatrix, clusters, clusterEndpoints] = getCovers(phase{1},freq,stationaryPoints,infContour,a,b);
    
    %make the contours from each cover:
    contours = getContours(phase, covers, infContour, valleys, clusters, clusterEndpoints);
    
    %now do the complicated stuff:
    contourSeq = shortestInfinitePathV2(contours, covers, intersectionMatrix, valleys, a, b, infContour);
    contoursInSeq = contours(contourSeq);
    
    if infContour
        [z, w] = makeQuad(contoursInSeq, freq, Npts, phase);
    else
        [z, w] = makeQuad(contoursInSeq, freq, Npts, phase, false, [a b]);
    end
    
end