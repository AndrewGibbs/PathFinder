function [A, clumpOut, clumpEndpoints] = ballOverlap(balls)
%returns matrix of logical values, if a given ball overlaps with another
%ball
    numBalls = length(balls);
    
    %construct adjacency matrix for ma balls
    for m = 1:numBalls
        for n = 1:numBalls
            if abs(balls(n).centre - balls(m).centre) < balls(n).radius + balls(m).radius
                A(n,m) = max(balls(m).diameter,balls(n).diameter);
            else
                A(n,m) = 0;
            end
        end
    end
    
    %now determine clusters of balls, (as equivalence classes)
    clump = cell(length(balls),1);
    clumpIndex = 1:length(balls);
    m_clumped = [];

    for n = 1:numBalls
        if ~(ismember(n,m_clumped))
            clump{n} = n;
        end
        for m = n+1:numBalls
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
            if balls(clumpOut{n}(m)).radius == 0
                clumpEndpoints{n} = [clumpEndpoints{n} balls(clumpOut{n}(m)).centre];
            end
        end
    end
end

