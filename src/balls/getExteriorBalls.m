function [covers, endPointIndices]...
                = getExteriorBalls(phaseFn, freq, stationaryPointArray, ...
                    isInfEndptArray, a, b, Cosc, phaseCoeffs, ...
                    ballMergeTol, numRays, isInteriorBalls, imagThresh, ...
                    useMex)
    
    %% put a ball of radius zero around the endpoints

    % initialise variables
    ballsIndex = 0;
    endPointBalls = [];
    endPointIndices = [];
    
    %not yet sure if endpoints are finite/infinite, found out here
    possibleFiniteEndpoints = [a b];
    numFiniteEndpoints = 0; % counter for number of infinite endpoints
    for iEndpoint = [1 2]
       % only put ball (or zero radius) around endpoint if finite
       if ~isInfEndptArray(iEndpoint)
           ballsIndex = ballsIndex + 1;
           numFiniteEndpoints = numFiniteEndpoints + 1;
           % construct the ball of radius zero
           endPointBalls{numFiniteEndpoints} = Ball(0, possibleFiniteEndpoints(iEndpoint), ...
                                                    phaseFn,ballsIndex);
           endPointIndices = [endPointIndices ballsIndex];
       end
    end
    
    %% add non-zero radius around stationary points
    % for the balls around the stationary points, we want to ensure there is
    % a bounded number of oscillations. This is the smallest ball inside of
    % which |g(z)-g(SP)|<numOscs, where g is the phase, z is any point in the
    % ball, SP is the stationary point.

    if ~isempty(stationaryPointArray)
        % initialise radius variable
        radii = zeros(length(stationaryPointArray),1);
        % initialise ball centres as stationary points
        centres = stationaryPointArray;
        for jEndpoint = 1:length(stationaryPointArray)
            % determine radius, so that there is a bounded number of
            % oscillations inside the complex ball
            if useMex
                radii(jEndpoint) = get_smallest_supset_ball_mex(phaseCoeffs.', ...
                            freq, stationaryPointArray(jEndpoint), Cosc, numRays, ...
                            ~isInteriorBalls,imagThresh);
            else
                radii(jEndpoint) = getSmallestSupsetBall(phaseCoeffs.', freq, ...
                                stationaryPointArray(jEndpoint), Cosc, numRays, ...
                                ~isInteriorBalls, imagThresh);
            end
        end
        

        %% merge balls which are close together
        numStatPointBalls = length(stationaryPointArray);
        continueLoop = true;

        % continue process until all balls are sufficiently far apart
        while numStatPointBalls>1 && continueLoop

            D = zeros(numStatPointBalls);

            % following two variables correspond to position of the minimum
            % value in the matrix of distances
            iMin = 0;
            jMin = 0;
            % and the minimum value
            minVal = inf;

            % construct matrix describing distances between SPs
            for iEndpoint=1:numStatPointBalls
                for jEndpoint=(iEndpoint+1):numStatPointBalls
                    % the condition for 'closeness' is the following:
                    D(iEndpoint,jEndpoint) = abs(centres(iEndpoint)-centres(jEndpoint))/max(radii(iEndpoint),radii(jEndpoint));
                    % possibly merge the balls which are closest in the
                    % above sense
                    if D(iEndpoint, jEndpoint) < minVal
                        minVal = D(iEndpoint,jEndpoint);
                        iMin = iEndpoint;
                        jMin = jEndpoint;
                    end
                end
            end
    
            % if closest balls are sufficiently close, merge them
            if minVal <= ballMergeTol
                % now remove extra index from the list
                if radii(iMin) < radii(jMin)
                    removeIndex = iMin;
                else
                    removeIndex = jMin;
                end
                % and remove relevant data from other variables
                radii = radii(1:numStatPointBalls ~= removeIndex);
                centres = centres(1:numStatPointBalls ~= removeIndex);
                numStatPointBalls = numStatPointBalls - 1;
            else
                % break loop if no balls need merging
                continueLoop = false;
            end
        end

        % now create a ball at each of the remaining 'centres'
        for jEndpoint = 1:numStatPointBalls
            ballsIndex = ballsIndex + 1;
            ballsInit{jEndpoint} = Ball(radii(jEndpoint), ...
                                centres(jEndpoint), phaseCoeffs, ballsIndex);
        end

        %% delete redundant exits
        % Some steepest exits will start inside another ball. This can be
        % deleted now, saving work later on.
        covers = [endPointBalls deleteRedundantExits(ballsInit)];
    else % case without stationary points
        covers = endPointBalls;
    end
end
