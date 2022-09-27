function [covers, intersectionMatrix, clusters, clusterEndpoints, HermiteCandidates, endPointIndices, nonOscFlag]...
                = getInteriorBalls(g, freq, SPs, infContour, a, b, SPorders, Cosc, Hermite)

    coverIndex = 0;
    endPointBalls = [];
    endPointIndices = [];
    
    maybzEndpoints = [a b];
    for m = [1 2]
       if ~infContour(m)
           coverIndex = coverIndex + 1;
           endPointBalls = [endPointBalls Ball(0,maybzEndpoints(m),g,coverIndex,0)];
           endPointIndices = [endPointIndices coverIndex];
       end
    end
    
    if ~isempty(SPs)>0
        for n = 1:length(SPs)
            coverIndex = coverIndex + 1;
            coversInit(n) = Ball(getInteriorRadius(SPs(n)),SPs(n),g,coverIndex,SPorders(n));
            %coversInit(n) = ContourInterior(SPs(n),freq,g,coverIndex,Cosc,SPorders(n));
            %  ( ^^ only the above line of code actually changed from cover version ^^)
        end

        %delete exits inside a cover from another mother:

        covers = [num2cell(endPointBalls) num2cell(deleteRedundantExits(coversInit))];
    else
        covers = num2cell(endPointBalls);
    end

    %now determine which covers overlap:
    [intersectionMatrix, clusters, clusterEndpoints] = coverOverlapV2(covers);
    
    if Hermite
        HermiteCandidates = getHermiteCandidates(clusters, clusterEndpoints, covers);
    else
        HermiteCandidates = [];
    end

    nonOscFlag = false;
    if (~infContour(1)) && (~infContour(2))
        for n = 1:length(clusterEndpoints)
            if ismember(a,clusterEndpoints{n}) && ismember(b,clusterEndpoints{n})
                nonOscFlag = true;
                break;
            end
        end
    end
    
    function minR = getInteriorRadius(xi)
        Nangles = 32;
        Nrads = 32;
        scale = 2/freq;
        G = @(z) freq*abs(g(z)-g(xi)) - Cosc;
        
        crappyGuess = true;
        theta = 2*pi*(1:Nangles)/Nangles;
        
        count = 0;
        while crappyGuess == true
            r = scale*linspace(0,1,Nrads);
            %r = r(2:end);
            guess = xi + r.'*exp(1i*theta);
            isNegative = G(guess) < 0;
            if sum(sum(isNegative)) == Nangles*Nrads
                scale = scale*2;
            elseif sum(sum(isNegative)) == 0
                scale = scale/2;
            else
                crappyGuess = false;
            end
            count = count + 1;
            if count>100
                error('failed to find a ray');
            end
        end
        
        Rinds = 1:Nrads;
        minR = inf;
        minInd = 0;
        
        for nn = 1:Nangles
            firstPositive{nn} = Rinds(~isNegative(:,nn)); % (n,:) indices might be wrong way around here
            if ~isempty(firstPositive{nn})
                if r(firstPositive{nn}(1))<minR
                    minR = r(firstPositive{nn}(1));
                    minInd = nn;
                end
            end
        end
        if isinf(minR)
            error('failed to find ball inside of contour');
        end
    end
end
