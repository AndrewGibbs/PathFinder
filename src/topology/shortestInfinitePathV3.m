function Q = shortestInfinitePathV3(contours, covers, coverOverlaps, valleys, a, b, endPointIndices, infContour, HermiteCandidates, clusters)
    %chooses shortest (in the sense of fewest contours) infinite (each
    %contour is infinite) sequence of paths from valley_a to valley_b
    
    if nargin < 7
        endPointIndices = NaN(2,1);
    end
    
    if length(endPointIndices) == 2
        for n = 1:length(clusters)
            if min(ismember(endPointIndices,clusters{n}))%coverOverlaps(endPointIndices(1),endPointIndices(2))
                %both endpoints are contained inside a non-oscillatory region -
                %can skip the complicated stuff and just use standard
                %quadrature
                Q{1}.type =  'strLn';
                Q{1}.a = a;
                Q{1}.b = b;
                Q{1}.a_coverIndex = endPointIndices(1);
                Q{1}.b_coverIndex = endPointIndices(2);
                Q{n}.Hermite = false;
                return;
            end
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
                
            else %cover to cover
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
    
    % adjust indices for finite/infinite endpoints
    if infContour(1)
        startInd = findValleyIndex(a) + numCovers;
    else
        startInd = endPointIndices(1);
    end
    
    if infContour(2)
        endInd = findValleyIndex(b) + numCovers;
    else
        endInd = endPointIndices(end);
    end
        
    % solve the shortest path problem
    Gr = graph(network,'upper');
    [seq, cost] =shortestpath(Gr,startInd,endInd);
    if isinf(cost)
        error('Unable to determine shortest path');
    end
    
    % unit scalar to determine if SD path is incoming or outgoing
    if infContour(1)
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
            %join up final edge of ball to endpoint, if required
            if infContour(2)
                if (ismember(endInd,C.startClusterIndices) && C.startCoverIndex~=endInd) ...
                        || (ismember(endInd,C.endClusterIndices) && C.endCoverIndex~=endInd)
                        Q{n}.type = 'strLn';
                        Q{n}.Hermite = false;
                        [Q{n}.a, Q{n}.a_coverIndex] = getCoverExit(seq(end-1),contIndex);
                        Q{n}.b = b;
                        Q{n}.b_coverIndex = endPointIndices(2);
                        break;
                end
            end
            
        else %this is a cover
            coverIndex = seq(j);
            if ismember(coverIndex,endPointIndices)
                contourIndex = edgeContourIndices(seq(j),seq(j+1));
                %if cover contains an enpoint of integral
                if length(contours(contourIndex).startClusterIndices)>1 && coverIndex==endPointIndices(1)
                    %contour starts on edge of a cluster, not just an
                    %endpoint - need a straight line before the contour
                    Q{n}.type = 'strLn';
                    Q{n}.Hermite = false;
                    %[Q{n}.a, Q{n}.a_coverIndex]  = contours(contourIndex).intervalEndpoint;
                    Q{n}.a  = contours(contourIndex).intervalEndpoint;
                    Q{n}.a_coverIndex = endPointIndices(1);
                    [Q{n}.b, Q{n}.b_coverIndex] = getCoverExit(coverIndex,contourIndex);
                    n = n + 1;
                end
                
                Q{n} = assignQuadInfo(contours(contourIndex),seq(j));
                n = n + 1;
                
                if length(contours(contourIndex).startClusterIndices)>1 && coverIndex==endPointIndices(2)
                    %contour starts on edge of a cluster, not just an
                    %endpoint - need a straight line after the contour
                    Q{n}.type = 'strLn';
                    Q{n}.Hermite = false;
                    [Q{n}.a, Q{n}.a_coverIndex] = getCoverExit(coverIndex,contourIndex);
                    %[Q{n}.b, Q{n}.b_coverIndex] = contours(contourIndex).intervalEndpoint;
                    Q{n}.b = contours(contourIndex).intervalEndpoint;
                    Q{n}.b_coverIndex = endPointIndices(2);
                    n = n + 1;
                end
                %need a special case for if the two enpoints are in the
                %same bubble!
            else %previous and next contours start
                Q{n}.type = 'strLn';
                Q{n}.Hermite = false;

                prevContIndex = edgeContourIndices(seq(j-1),seq(j));
                [Q{n}.a, Q{n}.a_coverIndex] = getCoverExit(coverIndex,prevContIndex);
                
                nextContIndex = edgeContourIndices(seq(j),seq(j+1));
                [Q{n}.b, Q{n}.b_coverIndex] = getCoverExit(coverIndex,nextContIndex);
                
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
    
%     if seq(end-1)<=numCovers && (~infCountour(2))
%         n = length(Q)+1;
%         Q{n}.type = 'strLn';
%         Q{n}.Hermite = false;
%         prevContIndex = edgeContourIndices(seq(end-1),seq(end));
%         [Q{n}.a, Q{n}.a_coverIndex] = getCoverExit(seq(end-1),prevContIndex);
%         Q{n}.b = b;
%         Q{n}.b_coverIndex = endPointIndices(2);
%     end
    
    % - - - - indented functions : 
    
    function [x,n]= getCoverExit(covIndex,contIndex)
        cont = contours(contIndex);
        if isinf(cont.length)
            x = cont.startPoint;
            n = cont.startCoverIndex;
        elseif ismember(covIndex,cont.startClusterIndices)
            x = cont.startPoint;
            n = cont.startCoverIndex;
        elseif ismember(covIndex,cont.endClusterIndices)
            x = cont.endPoint;
            n = cont.endCoverIndex;
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

    function n = findValleyIndex(v)
        valleyNotFound = false;
         for n_ = 1:length(valleys)
            if abs(valleys(n_)-v)<1e-12
                n = n_;
                %valleys(m) = v;
                valleyNotFound = false;
            end
         end
        if valleyNotFound
            error('valley not found');
        end
    end
end