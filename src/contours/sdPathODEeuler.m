function [pArrayOut, hArrayOut, valleyIndex, ballIndex] = ...
    sdPathODEeuler(pathStartPoint, phaseCoeffs, stationaryPointArray, ...
        ballRadiiArray, valleysArray, baseStepSize, pointCacheSize, rStar,...
        newtonSmallThreshold, newtonBigThreshold)

    % initialise the indices of the valley and ball where the SD path ends
    valleyIndex = [];
    ballIndex = [];

    % account for the fact when there are no (other) stationary points, by
    % adding a ficticious SP at infinity
    if isempty(stationaryPointArray)
        stationaryPointArray = inf;
        ballRadiiArray = 0;
    end

    % similarly, we don't want endpoints to be treated like SPs, as they do
    % not affect ODE stability. So move the location of any endpoints to
    % infinity. These can be detected because their radius is zero.
    for numPts=1:length(stationaryPointArray)
        if ballRadiiArray(numPts)==0%
            stationaryPointArray(numPts) = inf;
        end
    end

    % get value of phase function at steepest exit, start of path
    phaseValAtSteepestExit = polyval(phaseCoeffs,pathStartPoint);

    % get the polynomial order from the length of the coefficients
    order = length(phaseCoeffs)-1;

    % get the coefficients of the derivatives of the polynomial phase
    % function
    dPhaseCoeffs = phaseCoeffs(1:(end-1)).*(order:-1:1);
    ddPhaseCoeffs = dPhaseCoeffs(1:(end-1)).*((order-1):-1:1);

    % initialise variables for main loop
    h = pathStartPoint;
    % intialise with zeros
    pArray = zeros(pointCacheSize,1);
    hArray = zeros(pointCacheSize,1)+eps*1i;
    % fill in first value with information about start point
    pArray(1) = 0;
    hArray(1) = pathStartPoint;

    % initiliase iterator variable / counter for array
    numPts = 1;
    continueLoop = true;

    %% main ODE stepping loop
    while continueLoop
        numPts = numPts+1;

        % get deriv values at the front of the SD contour
        ddPhaseAt_h = polyval(ddPhaseCoeffs,h);
        dPhaseAt_h = polyval(dPhaseCoeffs,h);

        % Forward Euler step

        % get value of ODE given p and h(p)
        odeAt_h = 1i/dPhaseAt_h;

        % compute step size based on distance to stationary points
        pStepSize = baseStepSize*min(2*abs(dPhaseAt_h^2/ddPhaseAt_h),...
                    min(abs(stationaryPointArray-h))/abs(odeAt_h));

        % increment contour
        h = h + pStepSize*odeAt_h;
        
        % update phase and deriv vals again
%         phaseAt_h = polyval(phaseCoeffs,h);
%         dPhaseAt_h = polyval(dPhaseCoeffs,h);

        % update cumulative value of p
        p = pArray(numPts-1)+pStepSize;

        % get value of Newton step here
        newtonStep = getNewtonStep();

        % do Newton iteration of the size of step is sufficiently small
        while abs(newtonStep)>newtonBigThreshold
            h = h-newtonStep;
            newtonStep = getNewtonStep();
        end

        % might as well apply Newton once more, as we have the value
        h = h - newtonStep;

        % update arrays of p and h values
        pArray(numPts) = p;
        hArray(numPts) = h;

        % determine if the process should be halted, because we are either
        % in a ball or region of no return
        [isInBall, isInNoReturn, endIndex] = haltEuler();

        % only continue the loop if in neither
        continueLoop = ~(isInBall || isInNoReturn);

        if isInBall

            % if we are in a ball, we need the endpoint to be very accurate. So
            % apply Newton refinement at the finer level here.
            newtonStep = getNewtonStep();
            while abs(newtonStep) > newtonSmallThreshold
                h = h - newtonStep;
                newtonStep = getNewtonStep();
            end

            % might as well apply Newton once more, as we have the value
            hArray(numPts) = h - newtonStep;

            % get index of the ball
            ballIndex = endIndex;
        else
            % get index of the valley
            valleyIndex = endIndex;
        end

        % if we are at the limit of the cache size, increase the array size
        % further
        if mod(int64(numPts), int64(pointCacheSize)) == 0 % need to add more points
            pArrayCopy = pArray;
            hArrayCopy = hArray;
            pArray = zeros(pointCacheSize+numPts, 1);
            hArray = zeros(pointCacheSize+numPts, 1);
            pArray(1:numPts) = pArrayCopy;
            hArray(1:numPts) = hArrayCopy;
        end
    end

    % truncate output arrays to only contain worthwhile data
    pArrayOut = pArray(1:numPts);
    hArrayOut = hArray(1:numPts);

    %% indented functions

    function step = getNewtonStep()
        % update the phase and its derivative
        phaseAt_h = polyval(phaseCoeffs,h);
        dPhaseAt_h = polyval(dPhaseCoeffs,h);
        % apply Newton iteration
        step = (phaseAt_h-phaseValAtSteepestExit-1i*p)/dPhaseAt_h;
    end

    function [isInBall, inInNoReturn, index] = haltEuler()
        % check if h is in a ball
        [isInBall, index] = inAball(h, stationaryPointArray, ballRadiiArray);
        if isInBall
            inInNoReturn = false;
        else
            % check if in region of no return
            [inInNoReturn, index] = beyondNoReturn(h, valleysArray, phaseCoeffs, rStar);
        end
    end
end