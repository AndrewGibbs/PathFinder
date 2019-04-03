function [z, w] = makeQuad(contoursInSeq, freq, Npts, G, reuseThresh, contourInterval)

    if nargin <= 4
        recycleFlag = false;
    elseif isnan(reuseThresh) || ~reuseThresh
        recycleFlag = false;
    else
        recycleFlag = true;
    end
    
    if nargin <= 5
        infInterval = true;
    else
        infInterval = false;
        a = contourInterval(1);
        b = contourInterval(2);
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
           if ~infInterval && subseqCount==1 
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
    
    contourCount = 0;
    numSubSeqs = length(contourSubSeq);
    for n = 1:length(contourSubSeq)
        contourCount = contourCount + 1;
        
        if n == 1 && ~infInterval
            %initialise the endpoint vectors
            z_Ia = []; w_Ia = []; dh_Ia = [];
            
            %there'll be an endpoint of the original integration region 
            %here - check if it's half a ball away
            %from the start of the contour
            
            if isequal(contourSubSeq{n}(1).intervalEndpoint, a)
                if abs(contourSubSeq{n}(1).startPoint-contourSubSeq{n}(1).intervalEndpoint)>eps
                    [z_Ia, w_Ia, dh_Ia] = gauss_quad_complex(contourSubSeq{n}(1).intervalEndpoint, contourSubSeq{n}(1).startPoint, Npts);
                end
            elseif isequal(contourSubSeq{n}(1).endClusterIntervalEndpoints, a)
                if abs(contourSubSeq{n}(1).startPoint-contourSubSeq{n}(1).intervalEndpoint)>eps
                    [z_Ia, w_Ia, dh_Ia] = gauss_quad_complex(contourSubSeq{n}(1).endClusterIntervalEndpoints, contourSubSeq{n}(1).endPoint, Npts);
                end
            else
                error('Cannot decide on cover in which the first contour begins');
            end
            z = z_Ia; 
            w = w_Ia.*sgw(z_Ia)*dh_Ia;
        end
        
        %get first contour - assuming this can never be finite path of
        %ascent?
        if recycleFlag
            [z_I1, w_I1] = contourSubSeq{n}(1).reuseQuad(G,reuseThresh);
        else
            [z_I1, w_I1] = contourSubSeq{n}(1).getQuad(freq,Npts);
        end
        
        %for infinite endpoints, direction of first path is reversed
        if (infInterval || contourCount>1)
            w_I1 = -w_I1;
        
%         %for finite endpoints, direction of last path is reversed
%         elseif contourCount == length(contoursInSeq) && ~infInterval
%             w_I1 = -w_I1;
            
        end
        
        z = [z; z_I1]; w = [w; w_I1];
        
        if length(contourSubSeq{n})>1
                if ismember(contourSubSeq{n}(1).startCoverIndex,contourSubSeq{n}(2).startClusterIndices)
                    [z_I1j, w_I1j, dh_1Ij] = gauss_quad_complex(contourSubSeq{n}(1).startPoint, contourSubSeq{n}(2).startPoint, Npts);
                elseif ismember(contourSubSeq{n}(1).startCoverIndex,contourSubSeq{n}(2).endClusterIndices)
                    [z_I1j, w_I1j, dh_1Ij] = gauss_quad_complex(contourSubSeq{n}(1).startPoint, contourSubSeq{n}(2).endPoint, Npts);
                    %next two paths can only happen if first contour is
                    %finite (at both ends)
                elseif ismember(contourSubSeq{n}(1).endCoverIndex,contourSubSeq{n}(2).startClusterIndices)
                    [z_I1j, w_I1j, dh_1Ij] = gauss_quad_complex(contourSubSeq{n}(1).endPoint, contourSubSeq{n}(2).startPoint, Npts);
                elseif ismember(contourSubSeq{n}(1).endCoverIndex,contourSubSeq{n}(2).endClusterIndices)
                    [z_I1j, w_I1j, dh_1Ij] = gauss_quad_complex(contourSubSeq{n}(1).endPoint, contourSubSeq{n}(2).endPoint, Npts);
                else
                    error('cant work out how these contours connect');
                end
        
            z = [z; z_I1j];
            w = [w; w_I1j.*sgw(z_I1j)*dh_1Ij];

            finiteContours = contourSubSeq{n}(2:(end)); %last one isn't actually finite... but we won't go there
            prevCoverCluster = contourSubSeq{n}(1).startClusterIndices;
            for m = 1:length(finiteContours)-1 %finite contours inbetween
                %determine direction of finite path, is this coming into or going
                %from the previous cover?
                if ismember(finiteContours(m).startCoverIndex,prevCoverCluster)
                    pm=1;
                    coverStartPoint = finiteContours(m).endPoint;
                    nextClusterIndices = finiteContours(m).endClusterIndices;
                else %starts at next cover and descends back
                    pm=-1;
                    %finite contour starts in next cover, and descends towards
                    %this cover. So the join across the cover will start at the
                    %'start' of the contour (we're moving backwards along it)
                    coverStartPoint = finiteContours(m).startPoint;
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
                [z_f1j, w_f1j,dh_f1j] = gauss_quad_complex(coverStartPoint, coverEndPoint, Npts);
                z = [z; z_f1; z_f1j];
                w = [w; pm*w_f1; w_f1j.*sgw(z_f1j)*dh_f1j];
                prevCoverCluster = nextClusterIndices;
            end

            finiteFlag = 1;
            %initialise the endpoint (b) vectors
            if n == numSubSeqs && ~infInterval
                %if finite interval, direction is reversed:
                finiteFlag = -1;
                
                %initialise the endpoint vectors
                z_Ib = []; w_Ib = []; dh_Ib = [];

                if isequal(contourSubSeq{n}(end).intervalEndpoint, b)
                    if abs(contourSubSeq{n}(end).startPoint-contourSubSeq{n}(end).intervalEndpoint)>eps
                        [z_Ib, w_Ib, dh_Ib] = gauss_quad_complex(contourSubSeq{n}(end).intervalEndpoint, contourSubSeq{n}(end).startPoint, Npts);
                    end
                elseif isequal(contourSubSeq{n}(end).endClusterIntervalEndpoints, b)
                    if abs(contourSubSeq{n}(end).startPoint-contourSubSeq{n}(end).intervalEndpoint)>eps
                        [z_Ib, w_Ib, dh_Ib] = gauss_quad_complex(contourSubSeq{n}(end).endClusterIntervalEndpoints, contourSubSeq{n}(end).endPoint, Npts);
                    end
                else
                    error('Cannot decide on cover in which the last contour begins');
                end

                z = [z; z_Ib];
                w = [w; w_Ib.*sgw(z_Ib)*dh_Ib];
            end


            if recycleFlag
                [z_Iend, w_Iend] = contourSubSeq{n}(end).reuseQuad(G,reuseThresh);
            else
                [z_Iend, w_Iend] = contourSubSeq{n}(end).getQuad(freq,Npts);
            end
            z = [z; z_Iend];
            w = [w; finiteFlag*w_Iend];
            
        end
        %size(z)
    end
    
    
end