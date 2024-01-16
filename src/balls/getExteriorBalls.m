function [covers, endPointIndices]...
                = getExteriorBalls(g, freq, SPs, infContour, a, b, Cosc,g_coeffs,...
                    ball_clump_thresh,num_rays,int_balls_yn,imag_thresh, use_mex)
    
    %% put a ball of radius zero around the endpoints

    % initialise variables
    coverIndex = 0;
    endPointBalls = [];
    endPointIndices = [];
    
    %not yet sure if endpoints are finite/infinite
    maybzEndpoints = [a b];
    ep_count = 0; %endpoint count, for number of infinite endpoints
    for m = [1 2]
       if ~infContour(m)
           coverIndex = coverIndex + 1;
           ep_count = ep_count + 1;
           % construct the ball of radius zero
           endPointBalls{ep_count} = Ball(0,maybzEndpoints(m),g,coverIndex);
           endPointIndices = [endPointIndices coverIndex];
       end
    end
    
    %% add non-zero radius around stationary points
    % for the balls around the stationary points, we want to ensure there is
    % a bounded number of oscillations. This is the smallest ball inside of
    % which |g(z)-g(SP)|<numOscs, where g is the phase, z is any point in the
    % ball, SP is the stationary point.

    if ~isempty(SPs)
        % initialise radius variable
        radii = zeros(length(SPs),1);
        % initialise ball centres as stationary points
        centres = SPs;
        for n = 1:length(SPs)
            % determine radius, so that it has a bounded number of
            % oscillations
            if use_mex
                radii(n) = get_smallest_supset_ball_mex(g_coeffs.', freq, SPs(n), Cosc, num_rays,~int_balls_yn,imag_thresh);
            else
                radii(n) = getSmallestSupsetBall(g_coeffs.', freq, SPs(n), Cosc, num_rays,~int_balls_yn,imag_thresh);
            end
        end
        

        %% merge balls which are close together
        num_SP_balls = length(SPs);
        continue_loop = true;

        % continue process until all balls are sufficiently far apart
        while num_SP_balls>1 && continue_loop

            D = zeros(num_SP_balls);
            min_m = 0;
            min_n = 0;
            min_val = inf;

            % construct matrix describing distances between SPs
            for m=1:num_SP_balls
                for n=(m+1):num_SP_balls
                    % the condition for 'closeness' is the following:
                    D(m,n) = abs(centres(m)-centres(n))/max(radii(m),radii(n));
                    % possibly merge the balls which are closest in the
                    % above sense
                    if D(m,n)<min_val
                        min_val = D(m,n);
                        min_m = m;
                        min_n = n;
                    end
                end
            end
    
            % if closest balls are sufficiently close, merge them
            if min_val<=ball_clump_thresh
                % now remove extra index from the list
                if radii(min_m) < radii(min_n)
                    remove_index = min_m;
                else
                    remove_index = min_n;
                end
                % and remove relevant data from other variables
                radii = radii(1:num_SP_balls~=remove_index);
                centres = centres(1:num_SP_balls~=remove_index);
                num_SP_balls = num_SP_balls - 1;
            else
                continue_loop = false;
            end
        end

        for n=1:num_SP_balls
            coverIndex = coverIndex + 1;
            coversInit{n} = Ball(radii(n),centres(n),g_coeffs,coverIndex);
        end

        %% delete redundant exits
        % Some steepest exits will start inside another ball. This can be
        % deleted now, saving work later on.
        covers = [endPointBalls deleteRedundantExits(coversInit)];
    else
        covers = endPointBalls;
    end
end
