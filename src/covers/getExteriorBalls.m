function [covers, endPointIndices]...
                = getExteriorBalls(g, freq, SPs, infContour, a, b, Cosc,g_coeffs,...
                    ball_clump_thresh,num_rays,int_balls_yn,imag_thresh, use_mex)

    coverIndex = 0;
    endPointBalls = [];
    endPointIndices = [];
    DH = 1;%(1/2);
    
    maybzEndpoints = [a b];
    ep_count = 0;
    for m = [1 2]
       if ~infContour(m)
           coverIndex = coverIndex + 1;
           ep_count = ep_count + 1;
           endPointBalls{ep_count} = Ball(0,maybzEndpoints(m),g,coverIndex,0);
%            endPointBalls = [endPointBalls Ball(0,maybzEndpoints(m),g,coverIndex,0)];
           endPointIndices = [endPointIndices coverIndex];
       end
    end
    
    if ~isempty(SPs)
        radii = zeros(length(SPs),1);
        centres = SPs;
        for n = 1:length(SPs)
%             coverIndex = coverIndex + 1;
%             radii(n) = get_interior_ball_mex(g_coeffs.', freq, SPs(n), uint32(SPorders(n)), Cosc);
            % DH wants factor of two...
            if use_mex
                radii(n) = DH*get_smallest_supset_ball_mex(g_coeffs.', freq, SPs(n), Cosc, num_rays,~int_balls_yn,imag_thresh);
            else
                radii(n) = DH*get_smallest_supset_ball(g_coeffs.', freq, SPs(n), Cosc, num_rays,~int_balls_yn,imag_thresh);
            end
        end

%             coversInit(n) = Ball(r_min,SPs(n),g_coeffs,coverIndex,sum(SPorders+1));
        % DH also wants a matrix here, instead of the below loop
        
        num_SP_balls = length(SPs);
        continue_loop = true;

        while num_SP_balls>1 && continue_loop

            D = zeros(num_SP_balls);
            min_m = 0;
            min_n = 0;
            min_val = inf;

            % construct DH's matrix
            for m=1:num_SP_balls
                for n=(m+1):num_SP_balls
                    D(m,n) = abs(centres(m)-centres(n))/max(radii(m),radii(n));
                    if D(m,n)<min_val
                        min_val = D(m,n);
                        min_m = m;
                        min_n = n;
                    end
                end
            end
    
            if min_val<=ball_clump_thresh
                if radii(min_m) < radii(min_n)
                    remove_index = min_m;
%                     keep_index = min_n;
                else
                    remove_index = min_n;
%                     keep_index = min_m;
                end
                % now remove this ball from the list
                radii = radii(1:num_SP_balls~=remove_index);
                centres = centres(1:num_SP_balls~=remove_index);
                num_SP_balls = num_SP_balls - 1;
            else
                continue_loop = false;
            end
        end

        % now loop over all balls and check they're not too close
%         sparse_balls = false;
%         num_SP_balls = length(SPs);
%         while sparse_balls == false
%             sparse_balls = true;
%             for m=1:num_SP_balls
%                 for m_ = (m+1):num_SP_balls
%                     if abs(centres(m)-centres(m_))<=ball_clump_thresh
%                         sparse_balls = false;
%                         mergeSP = (centres(m)+centres(m_))/2;
%                         merge_rad = (radii(m)+radii(m_))/2;
% 
%                         num_SP_balls = num_SP_balls - 1;
%                         radii(m_)= [];
%                         centres(m_) = [];
%                         radii(m)= merge_rad;
%                         centres(m) = mergeSP;
%                         break;
%                     end
%                     if ~sparse_balls
%                         break;
%                     end
%                 end
%             end
%         end

        for n=1:num_SP_balls
            coverIndex = coverIndex + 1;
            coversInit{n} = Ball(radii(n),centres(n),g_coeffs,coverIndex,length(g_coeffs)-1,use_mex);
        end

        %delete exits inside a cover from another mother:

        covers = [endPointBalls deleteRedundantExits(coversInit)];
    else
        covers = endPointBalls;
    end

%     %now determine which covers overlap:
%     [intersectionMatrix, clusters, clusterEndpoints] = coverOverlapV2(covers);
%     
%     if Hermite
%         HermiteCandidates = getHermiteCandidates(clusters, clusterEndpoints, covers);
%     else
%         HermiteCandidates = [];
%     end
% 
%     nonOscFlag = false;
%     if (~infContour(1)) && (~infContour(2))
%         for n = 1:length(clusterEndpoints)
%             if ismember(a,clusterEndpoints{n}) && ismember(b,clusterEndpoints{n})
%                 nonOscFlag = true;
%                 break;
%             end
%         end
%     end
    
%     function minR = getInteriorRadius(xi)
% 
%         Nangles = 32;
%         Nrads = 32;
%         scale = 2/freq;
%         G = @(z) freq*abs(g(z)-g(xi)) - Cosc;
%         
%         crappyGuess = true;
%         theta = 2*pi*(1:Nangles)/Nangles;
%         
%         count = 0;
%         while crappyGuess == true
%             r = scale*linspace(0,1,Nrads);
%             %r = r(2:end);
%             guess = xi + r.'*exp(1i*theta);
%             isNegative = G(guess) < 0;
%             if sum(sum(isNegative)) == Nangles*Nrads
%                 scale = scale*2;
%             elseif sum(sum(isNegative)) == 0
%                 scale = scale/2;
%             else
%                 crappyGuess = false;
%             end
%             count = count + 1;
%             if count>100
%                 error('failed to find a ray');
%             end
%         end
%         
%         Rinds = 1:Nrads;
%         minR = inf;
%         minInd = 0;
%         
%         for nn = 1:Nangles
%             firstPositive{nn} = Rinds(~isNegative(:,nn)); % (n,:) indices might be wrong way around here
%             if ~isempty(firstPositive{nn})
%                 if r(firstPositive{nn}(1))<minR
%                     minR = r(firstPositive{nn}(1));
%                     minInd = nn;
%                 end
%             end
%         end
%         if isinf(minR)
%             error('failed to find ball inside of contour');
%         end
%     end
end
