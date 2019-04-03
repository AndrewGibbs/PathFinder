function [A, clumpOut, clumpEndpoints] = coverOverlapV2(covers)
%returns matrix of logical values, if a given ball overlaps with another
%ball
    numCovers = length(covers);
    
    %construct adjacency matrix for ma balls
    for m = 1:numCovers
        for n = 1:numCovers
            if overlapping(m,n)
                A(n,m) = 1;%max(covers(m).diameter,covers(n).diameter);
            else
                A(n,m) = 0;
            end
        end
    end
    
    %now determine clusters of balls, (as equivalence classes)
    clump = cell(length(covers),1);
    clumpIndex = 1:length(covers);
    m_clumped = [];

    for n = 1:numCovers
        if ~(ismember(n,m_clumped))
            clump{n} = n;
        end
        for m = n+1:numCovers
            if A(n,m)>0
                %balls overlap, need to be clumped                
                clumpIndex(m) = clumpIndex(n);
                clump{clumpIndex(m)} = [clump{clumpIndex(m)} m];
                m_clumped = [m_clumped m];
            end
        end
    end
    
    %now delete empty entries of clump vector
    m=1;
    for n=1:length(clump)
        if ~isempty(clump{n})
            clumpOut{m}=clump{n};
            m=m+1;
        end
    end
    
    %now, incase we are deforming a finite interval [a,b], log any finite
    %enpoints (a or b) which are inside of any cluster
    for n=1:length(clumpOut)
        clumpEndpoints{n} = [];
        for m=1:length(clumpOut{n})
            if covers{clumpOut{n}(m)}.diameter == 0
                clumpEndpoints{n} = [clumpEndpoints{n} covers{clumpOut{n}(m)}.centre];
            end
        end
    end
    
    %subroutine to deterine if covers overlap
    function yn = overlapping(m,n)
        yn = max(covers{m}.isIn(covers{n}.boundaryComplex));
    end
end

