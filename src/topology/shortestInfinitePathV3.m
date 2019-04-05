function contourSeq = shortestInfinitePathV3(contours, covers, coverOverlaps, valleys, a, b, endPointIndex)
    %chooses shortest (in the sense of fewest contours) infinite (each
    %contour is infinite) sequence of paths from valley_a to valley_b
    
    if nargin < 7
        endPointIndex = NaN(2,1);
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
    
    for j = 1:length(seq)
        if seq(j) > numCovers %this is a valley, need to choose the contour
            if j<length(seq)
                %either:
                    %finite contour
                    %infinite contour
                %index = seq(j)-numCovers;
                index = edgeContourIndices(seq(j),seq(j+1));
            else
                index = edgeContourIndices(seq(j-1),seq(j));
            end
            C = contours(index);
            if isinf(C.length)
                Q{j}.type = 'infSD';
                Q{j}.inOut = inOut;
                inOut = inOut*-1;
            else
                Q{j}.type = 'finSD';
                Q{j}.inOut = inOut;
            end
            Q{j}.contour = C;
        else %this is a cover
            %either:
            % an endpoint in this cover/cluster
            % infinite contour starts here, need to deterime direction
            % finite contour & need to determine which endpoint/direction
            index = seq(j);
            if ismember(index,endPointIndex)
                error('still need to code these endpoint bits');
            else %previous and next contours start
                Q{j}.type = 'strLn';
%               prevContIndex = seq(j-1) - numCovers;
%               nextContIndex = seq(j+1) - numCovers;

                prevContIndex = edgeContourIndices(seq(j-1),seq(j));
                Q{j}.a = getCoverExit(index,prevContIndex);
                
                nextContIndex = edgeContourIndices(seq(j),seq(j+1));
                Q{j}.b = getCoverExit(index,nextContIndex);
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
end