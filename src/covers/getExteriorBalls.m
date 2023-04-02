function [covers, intersectionMatrix, clusters, clusterEndpoints, HermiteCandidates, endPointIndices, nonOscFlag]...
                = getExteriorBalls(g, freq, SPs, infContour, a, b, SPorders, Cosc, Hermite,g_coeffs,ball_clump_thresh)

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
        radii = zeros(length(SPs),1);
        centres = SPs;
        for n = 1:length(SPs)
%             coverIndex = coverIndex + 1;
%             radii(n) = get_interior_ball_mex(g_coeffs.', freq, SPs(n), uint32(SPorders(n)), Cosc);
            % DH wants factor of two...
            radii(n) = 2*get_smallest_supset_ball(g_coeffs, freq, SPs(n), Cosc);
        end

%             coversInit(n) = Ball(r_min,SPs(n),g_coeffs,coverIndex,sum(SPorders+1));

        % now loop over all balls and check they're not too close
        sparse_balls = false;
        num_balls = length(SPs);
        while sparse_balls == false
            sparse_balls = true;
            for m=(length(endPointIndices)+1):num_balls
                for m_ = (m+1):num_balls
                    if abs(centres(m)-centres(m_))<ball_clump_thresh
                        sparse_balls = false;
                        mergeSP = (centres(m)+centres(m_))/2;
                        merge_rad = (radii(m)+radii(m_))/2;

                        num_balls = num_balls - 1;
                        radii(m_)= [];
                        centres(m_) = [];
                        radii(m)= merge_rad;
                        centres(m) = mergeSP;
                    end
                end
            end
        end

        for n=1:num_balls
            coverIndex = coverIndex + 1;
            coversInit(n) = Ball(radii(n),centres(n),g_coeffs,coverIndex,sum(SPorders+1));
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
