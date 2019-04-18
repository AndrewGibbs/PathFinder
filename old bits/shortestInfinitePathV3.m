function Q = shortestInfinitePathV3(contours, covers, coverOverlaps, valleys, a, b, endPointIndex, HermiteCandidates)
    %chooses shortest (in the sense of fewest contours) infinite (each
    %contour is infinite) sequence of paths from valley_a to valley_b
    
    if nargin < 7
        endPointIndex = NaN(2,1);
    end
    
    if ~isnan(endPointIndex(1)) && ~isnan(endPointIndex(2))
        if coverOverlaps(endPointIndex(1),endPointIndex(2))
            %both endpoints are contained inside a non-oscillatory region -
            %can skip the complicated stuff and just use standard
            %quadrature
            Q{1}.type =  'strLn';
            Q{1}.a = a;
            Q{1}.b = b;
            return;
        end
    end
    
    numValleys = length(valleys);
    numCovers = length(covers);
    
    totalNodes = numCovers + numValleys;
    
    %network matrix will consist of nodes corresponding to covers, then
    %valleys.
    network = zeros(totalNodes);
    edgeContourIndices = zeros(totalNodes);
    quadInfoMatrix = struct([]);
    
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
                
%                 quadInfoMatrix(coverIndex, numCovers + find(valleys==contour.endValley)).type = 'infSD';
%                 quadInfoMatrix(coverIndex, numCovers + find(valleys==contour.endValley)).contour = contour;
%                 quadInfoMatrix( numCovers + find(valleys==contour.endValley),coverIndex) = ...
%                     quadInfoMatrix(coverIndex, numCovers + find(valleys==contour.endValley));
                
            else %cover to cover
                %network(coverIndex, find((1:numCovers)==contour.endCoverIndex)) = covers(coverIndex).diameter;
                network(coverIndex, find((1:numCovers)==contour.endCoverIndex)) = cost;
                edgeContourIndices(coverIndex, find((1:numCovers)==contour.endCoverIndex)) = contourIndex;
%                 
%                 quadInfoMatrix(coverIndex, find((1:numCovers)==contour.endCoverIndex)).type = 'finSD';
%                 quadInfoMatrix(coverIndex, find((1:numCovers)==contour.endCoverIndex)).contour = contour;
%                 quadInfoMatrix(quadInfoMatrix(coverIndex, find((1:numCovers)==contour.endCoverIndex))) = ...
%                     quadInfoMatrix(quadInfoMatrix(coverIndex, find((1:numCovers)==contour.endCoverIndex)));
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
    if isnan(endPointIndex)
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
    
    %unit scalar to determine if SD path is incoming or outgoing
    if isnan(endPointIndex(1))
        inOut = -1;
    else
        inOut = 1;
    end
    
    n = 1;
    for j = 1:(length(seq)-1)
        if seq(j) > numCovers %this is a valley, need to choose the contour
                contIndex = edgeContourIndices(seq(j),seq(j+1));
            C = contours(contIndex);
            Q{n} = assignQuadInfo(C);
            n = n + 1;
            
        else %this is a cover
            coverIndex = seq(j);
            if ismember(coverIndex,endPointIndex)
                contourIndex = edgeContourIndices(seq(j),seq(j+1));
                %if cover contains an enpoint of integral
                if length(contours(contourIndex).startClusterIndices)>1 && coverIndex==endPointIndex(1)
                    %contour starts on edge of a cluster, not just an
                    %endpoint - need a straight line before the contour
                    Q{n}.type = 'strLn';
                    Q{n}.Hermite = false;
                    Q{n}.a = contours(contourIndex).intervalEndpoint;
                    Q{n}.b = getCoverExit(coverIndex,contourIndex);%contours(contourIndex).startPoint;
                    n = n + 1;
                end
                
                Q{n} = assignQuadInfo(contours(contourIndex));
                n = n + 1;
                
                if length(contours(contourIndex).startClusterIndices)>1 && coverIndex==endPointIndex(2)
                    %contour starts on edge of a cluster, not just an
                    %endpoint - need a straight line after the contour
                    Q{n}.type = 'strLn';
                    Q{n}.Hermite = false;
                    Q{n}.a = getCoverExit(coverIndex,contourIndex);
                    Q{n}.b = contours(contourIndex).intervalEndpoint;
                    n = n + 1;
                end
                %need a special case for if the two enpoints are in the
                %same bubble!
            else %previous and next contours start
                Q{n}.type = 'strLn';
                Q{n}.Hermite = false;

                prevContIndex = edgeContourIndices(seq(j-1),seq(j));
                Q{n}.a = getCoverExit(coverIndex,prevContIndex);
                
                nextContIndex = edgeContourIndices(seq(j),seq(j+1));
                Q{n}.b = getCoverExit(coverIndex,nextContIndex);
                
                if ismember(coverIndex,HermiteCandidates) && isinf(contours(prevContIndex).length) && isinf(contours(nextContIndex).length)
                    Q{n}.Hermite = true;
                    Q{n}.h0 = covers{coverIndex}.pseudoCentre;
                    Q{n}.dh0m = contours(prevContIndex).ICs(2);
                    Q{n}.dh0p = contours(nextContIndex).ICs(2);
                end
                
                n = n + 1;
                %now add the contour after the cover in the sequence
                
                C = contours(nextContIndex);
                Q{n} = assignQuadInfo(C,coverIndex);
                n = n + 1;
            end
        end        
    end
    
    %now convert seequence of nodes to sequence of edges
%     contourSeq = [];
%     for n = 2:length(seq)
%         if edgeContourIndices(seq(n-1),seq(n))==0
%             if coverOverlaps(seq(n-1),seq(n))==0
%                 error('Contour sequence doesnt make sense');
%             end
%         else
%             contourSeq = [contourSeq edgeContourIndices(seq(n-1),seq(n))];
%         end
%     end
    
    function x = getCoverExit(covIndex,contIndex)
        cont = contours(contIndex);
        if isinf(cont.length)
            x = cont.startPoint;
        elseif ismember(covIndex,cont.startClusterIndices)
            x = cont.startPoint;
        elseif ismember(covIndex,cont.endClusterIndices)
            x = cont.endPoint;
        end
    end
        
    function x = assignQuadInfo(C, startCoverIndex)
        if isinf(C.length)
            x.type = 'infSD';
            x.inOut = inOut;
            inOut = inOut*-1;
        else
            x.type = 'finSD';
            if ismember(startCoverIndex, C.startClusterIndices)
                x.inOut = 1;
            elseif ismember(startCoverIndex, C.endClusterIndices)
                x.inOut = -1;
            else
                error('cannot decide where finite contour begins/ends');
            end
        end
        x.contour = C;
    end
end