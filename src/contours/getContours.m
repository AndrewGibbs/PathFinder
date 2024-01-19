function contours = getContours(phase_coeffs, balls, valleys, params)
% given the coefficients vector, and the balls, compute the steepest 
% descent contours from each steepest exit.

    % reduced struct, specifically for path computation:
    GlobalContourParams = struct( ...
        'stepSize', params.globalStepSize, 'maxNumODEsteps',...
        params.maxNumODEsteps,'NewtonThresh',params.NewtonThresh,...
        'NewtonIts', params.NewtonIts,'rStar',params.rStar,...
        'NewtonBigThresh',params.NewtonBigThresh,'log',params.log,...
        'mex',params.useMex) ;

    numContours = 0;
    % loop over all balls
    for iCovers = 1:length(balls)
        % loop over all steepest exits on each ball
        for isteepestExit = balls{iCovers}.steepestExits
            % get details of other balls, so we can detect when the contour
            % enters one of those
            [critPointArray, critPointsRadiiArray] = ...
                getBallDeets(ballsComplement(iCovers));
            % filter out those which are stationary points
            % (recall convention that endpoint balls have zero radius)
            statPointArray = critPointArray(critPointsRadiiArray>0);
            cover_radii = critPointsRadiiArray(critPointsRadiiArray>0);

            % check that steepest exit isn't in another ball
            if ~inAball(isteepestExit, statPointArray, cover_radii)
                % if not, compute the steepest descent contour from this
                % endpoint
                numContours = numContours + 1;
                contours(numContours) = ContourSD(isteepestExit,phase_coeffs,balls{iCovers},...
                    ballsComplement(iCovers),valleys,GlobalContourParams);
            end
       end
    end
     
    % indepdened function, for getting all balls not in cell array
    function ballsOut = ballsComplement(n)
        numBalls = length(balls);
        ballsOut = [];
        % add balls before index to cell array
        for m=1:(n-1)
            ballsOut{m}=balls{m};
        end
        %add balls after index to cell array
        for m=(n+1):numBalls
            ballsOut{m-1}=balls{m};
        end
     end

end

