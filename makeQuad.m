function [z, w] = makeQuad(contoursInSeq, freq, Npts, G, reuseThresh, infContour)

    if nargin <= 4
        recycleFlag = false;
    else
        recycleFlag = true;
    end
    if isnan(reuseThresh)
        recycleFlag = false;
    end
    if nargin <= 5
        infContour = false;
    end
    
    if isa(G,'cell')
        g = G{1};
    else
        g = G;
    end
    
    z=[]; w=[];
    
    %make a corretion for standard Gauss, which has a different weight
    %function:
    sgw = @(z) exp(1i*freq*g(z));
    
    %idea of the below loop is to get all sequences of contours into
    %subsequences of the form (II), (IFI), (IFF---FFFI), i.e. two infinite
    %paths with finite paths between them
    subseqCount = 1;
    subseqIndex = 1;
    subseqInfPathCount =0;
    for n =1:length(contoursInSeq)
       contourSubSeq{subseqCount}(subseqIndex) = contoursInSeq(n);
       if isinf(contoursInSeq(n).length)
           subseqInfPathCount = subseqInfPathCount + 1;
           if ~infContour && n==1
               subseqInfPathCount = subseqInfPathCount + 1;
               %first contour in sequence, should be in its own subsequence
               %if it's infinte
           end
       end
       if subseqInfPathCount == 2
           subseqCount = subseqCount + 1;
           subseqIndex = 1;
           subseqInfPathCount = 0;
       else
           subseqIndex = subseqIndex+1;
       end
    end
    
    for n = 1:length(contourSubSeq)
        if recycleFlag
            [z_I1, w_I1] = contourSubSeq{n}(1).reuseQuad(G,reuseThresh);
        else
            [z_I1, w_I1] = contourSubSeq{n}(1).getQuad(freq,Npts);
        end
%         if ~isinf %first contour is outgoing, rather than incoming
%             w_I1 = -w_I1;
%         end
        if length(contourSubSeq{n})>1
            if contourSubSeq{n}(1).startCoverIndex == contourSubSeq{n}(2).startCoverIndex
                [z_I1j, w_I1j] = gauss_quad(contourSubSeq{n}(1).startPoint, contourSubSeq{n}(2).startPoint, Npts);
                dh_1Ij = (contourSubSeq{n}(2).startPoint - contourSubSeq{n}(1).startPoint)...
                        /abs(contourSubSeq{n}(2).startPoint - contourSubSeq{n}(1).startPoint);
            elseif contourSubSeq{n}(1).startCoverIndex == contourSubSeq{n}(2).endCoverIndex
                [z_I1j, w_I1j] = gauss_quad(contourSubSeq{n}(1).startPoint, contourSubSeq{n}(2).endPoint, Npts);
                dh_1Ij = (contourSubSeq{n}(2).endPoint - contourSubSeq{n}(1).startPoint)...
                        /abs(contourSubSeq{n}(2).endPoint - contourSubSeq{n}(1).startPoint);
            else %assume there are some overlapping balls, and that's how the two contours connect
                if ismember(contourSubSeq{n}(1).startCoverIndex,contourSubSeq{n}(2).startClusterIndices)
                    [z_I1j, w_I1j] = gauss_quad(contourSubSeq{n}(1).startPoint, contourSubSeq{n}(2).startPoint, Npts);
                    dh_1Ij = (contourSubSeq{n}(2).startPoint - contourSubSeq{n}(1).startPoint)...
                            /abs(contourSubSeq{n}(2).startPoint - contourSubSeq{n}(1).startPoint);
                elseif ismember(contourSubSeq{n}(1).startCoverIndex,contourSubSeq{n}(2).endClusterIndices)
                    [z_I1j, w_I1j] = gauss_quad(contourSubSeq{n}(1).startPoint, contourSubSeq{n}(2).endPoint, Npts);
                    dh_1Ij = (contourSubSeq{n}(2).endPoint - contourSubSeq{n}(1).startPoint)...
                            /abs(contourSubSeq{n}(2).endPoint - contourSubSeq{n}(1).startPoint);
                else
                    error('cant work out how these contours connect');
                end
            %*******%
            %it seems very likely that the above inner if statement can be merged
            %with the outer one!!!
            end
            z = [z; z_I1; z_I1j];
            w = [w; -w_I1; w_I1j.*sgw(z_I1j)*dh_1Ij];
        else
            z = [z; z_I1];
            w = [w; w_I1];
        end
        
        finiteContours = contourSubSeq{n}(2:(end)); %last one isn't actually finite... but we won't go there
        %prevCoverIndex = contourSubSeq{n}(1).startCoverIndex;
        prevCoverCluster = contourSubSeq{n}(1).startClusterIndices;
        for m = 1:length(finiteContours)-1 %finite contours inbetween
            %determine direction of finite path, is this coming into or going
            %from the previous cover?
            if ismember(finiteContours(m).startCoverIndex,prevCoverCluster)
                %finiteContours(m).startCoverIndex == prevCoverIndex
                pm=1;
                coverStartPoint = finiteContours(m).endPoint;
                %nextCoverIndex = finiteContours(m).endCoverIndex;
                nextClusterIndices = finiteContours(m).endClusterIndices;
            else %starts at next cover and descends back
                pm=-1;
                %finite contour starts in next cover, and descends towards
                %this cover. So the join across the cover will start at the
                %'start' of the contour (we're moving backwards along it)
                coverStartPoint = finiteContours(m).startPoint;
                %nextCoverIndex = finiteContours(m).startCoverIndex;
                nextClusterIndices = finiteContours(m).startClusterIndices;
            end

            if ismember(finiteContours(m+1).startCoverIndex,nextClusterIndices)
                coverEndPoint = finiteContours(m+1).startPoint;
            elseif ismember(finiteContours(m+1).endCoverIndex,nextClusterIndices)
                %end of contour is where it meets the current cover
                coverEndPoint = finiteContours(m+1).endPoint;
            else
                error('cannot connect path');
            end
            
            if recycleFlag
                [z_f1, w_f1] = finiteContours(m).reuseQuad(G,reuseThresh);
            else
                [z_f1, w_f1] = finiteContours(m).getQuad(freq,Npts);
            end
            %sum(w_f1)
            [z_f1j, w_f1j] = gauss_quad(coverStartPoint, coverEndPoint, Npts);
            dh_f1j = (coverEndPoint-coverStartPoint)/abs(coverEndPoint-coverStartPoint);
            %sum(w_f1j)
            z = [z; z_f1; z_f1j];
            w = [w; pm*w_f1; w_f1j.*sgw(z_f1j)*dh_f1j];
            %prevCoverIndex = finiteContours(m).startCoverIndex;
            prevCoverCluster = nextClusterIndices;
        end
        if recycleFlag
            [z_Iend, w_Iend] = contourSubSeq{n}(end).reuseQuad(G,reuseThresh);
        else
            [z_Iend, w_Iend] = contourSubSeq{n}(end).getQuad(freq,Npts);
        end
        z = [z; z_Iend];
        w = [w; w_Iend];
        %sum(w_Iend)
    end
    
    
end