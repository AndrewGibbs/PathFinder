function contourSeq = shortestInfinitePathV2(contours, covers, coverOverlaps, valleys, a, b, infCountour)
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
        for coverIndex = contour.startClusterIndices
            if covers{coverIndex}.diameter ==0
                cost = 10*eps;
            else
                cost = covers{coverIndex}.diameter*length(contour.startClusterIndices);
            end
            if isinf(contour.length) %cover to valley
                %network(coverIndex, numCovers + find(valleys==contour.endValley)) = covers(coverIndex).diameter;
                network(coverIndex, numCovers + find(valleys==contour.endValley)) = cost;
                edgeContourIndices(coverIndex, numCovers + find(valleys==contour.endValley)) = contourIndex;
            else %cover to cover
                %network(coverIndex, find((1:numCovers)==contour.endCoverIndex)) = covers(coverIndex).diameter;
                network(coverIndex, find((1:numCovers)==contour.endCoverIndex)) = cost;
                edgeContourIndices(coverIndex, find((1:numCovers)==contour.endCoverIndex)) = contourIndex;
            end
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
    if infCountour
        for n = 1:length(valleys)
            if abs(valleys(n)-a)<1e-12
                valleys(n) = a;
            elseif  abs(valleys(n)-b)<1e-12
                valleys(n) = b;
            end
        end
        startInd = find(valleys==a) + numCovers;
        endInd = find(valleys==b) + numCovers;
        if isempty(startInd) || isempty(endInd)
            error('Couldnt find valleys');
        end
    else
        startInd = 1;
        endInd = 2;
    end
    
    Gr = graph(network,'upper');
    [seq, cost] =shortestpath(Gr,startInd,endInd);
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