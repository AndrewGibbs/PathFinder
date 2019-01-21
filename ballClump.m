function balls = ballClump(ballsInit,g)
%clumps together balls if they overlap

    clump = cell(length(ballsInit),1);
    clumpIndex = 1:length(ballsInit);
    m_clumped = [];

    for n = 1:length(ballsInit)
        if ~(ismember(n,m_clumped))
            clump{n} = ballsInit(n);
        end
        for m = n+1:length(ballsInit)
            if abs(ballsInit(n).centre-ballsInit(m).centre)<ballsInit(n).radius+ballsInit(m).radius
                %balls overlap, need to be clumped                
                clumpIndex(m) = clumpIndex(n);
                clump{clumpIndex(m)} = [clump{clumpIndex(m)} ballsInit(m)];
                m_clumped = [m_clumped m];
            end
        end
    end
    
    ballCount = 0;
    for n=1:length(clump)
       if ~isempty(clump{n})
           ballCount = ballCount + 1;
           if length(clump{n})>1
               %find two balls which are farthest apart:
               maxDist = 0;
               for m_=1:length(clump{n})
                   for n_=m_:length(clump{n})
                       ballDist = abs(clump{n}(n_).centre-clump{n}(m_).centre);
                       if ballDist>maxDist
                           maxDist = ballDist;
                           maxPair = [m_ n_];
                       end
                   end
               end
               
               %now make a new ball which contains all balls in the clump
%                sumCentre = 0;
%                sumRadii = 0;
%                for clumpedBall = clump{n}
%                     sumCentre = sumCentre + clumpedBall.centre;
%                     sumRadii = sumRadii + 2*clumpedBall.radius;
%                end
               newCentre = mean([clump{n}(maxPair(1)).centre clump{n}(maxPair(2)).centre]);
               newRadius = maxDist/2 + max([clump{n}(maxPair(1)).radius  clump{n}(maxPair(2)).radius]);
               %balls(ballCount) = Ball(sumRadii, sumCentre/length(clump{n}), g, ballCount, 1); %arithmetic mean
               balls(ballCount) = Ball(newRadius, newCentre, g, ballCount, 1); 
           else
               balls(ballCount) = Ball(clump{n}.radius, clump{n}.centre, g, ballCount, 1); 
           end
       end
    end
end