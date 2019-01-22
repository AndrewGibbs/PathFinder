function contourSeq = shortestInfinitePath(contours, covers, coverOverlaps, valleys, a, b)
    %chooses shortest (in the sense of fewest contours) infinite (each
    %contour is infinite) sequence of paths from valley_a to valley_b
    
    numValleys = length(valleys);
    numCovers = length(covers);
    
    totalNodes = numCovers + numValleys;
    
    %network matrix will consist of nodes corresponding to covers, then
    %valleys.
    network = zeros(totalNodes);
    edgeContourIndices = zeros(totalNodes);
    
    %determine which covers are connected to valleys (or covers)
    contourIndex = 0;
    for contour = contours
        contourIndex = contourIndex + 1;
        if isinf(contour.length) %cover to valley
            network(contour.startCoverIndex, numCovers + find(valleys==contour.endValley)) = covers(contour.startCoverIndex).diameter;
            edgeContourIndices(contour.startCoverIndex, numCovers + find(valleys==contour.endValley)) = contourIndex;
        else %cover to cover
            network(contour.startCoverIndex, find((1:numCovers)==contour.endCoverIndex)) = covers(contour.startCoverIndex).diameter;
            edgeContourIndices(contour.startCoverIndex, find((1:numCovers)==contour.endCoverIndex)) = contourIndex;
        end
    end
    %make edge matrix symmetric:
    edgeContourIndices = edgeContourIndices + edgeContourIndices.';
    network = network + network.';
    
    for m = 1:numCovers
        for n=1:numCovers
            if network(m,n)==0
                network(m,n) = coverOverlaps(m,n);
            end
        end
    end
    
    %set valleys to 'exact' values
    for n = 1:length(valleys)
        if abs(valleys(n)-a)<1e-12
            valleys(n) = a;
        elseif  abs(valleys(n)-b)<1e-12
            valleys(n) = b;
        end
    end
    startValleyInd = find(valleys==a) + numCovers;
    endValleyInd = find(valleys==b) + numCovers;
    if isempty(startValleyInd) || isempty(endValleyInd)
        error('Couldnt find valleys');
    end
    
    Gr = graph(network,'upper');
    [seq, cost] =shortestpath(Gr,startValleyInd,endValleyInd);
    if isinf(cost)
        error('Unable to determine shortest path');
    end
    
    %now convert seequence of nodes to sequence of edges
    contourSeq = [];
    for n = 2:length(seq)
        if edgeContourIndices(seq(n-1),seq(n))==0
            if coverOverlaps(seq(n-1),seq(n))==0
                error('Contour sequence doesnt make sense');
            end
        else
            contourSeq = [contourSeq edgeContourIndices(seq(n-1),seq(n))];
        end
    end
end