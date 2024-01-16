% Extends steepest descent contour into the region of no return. This may
% be required to allocate a sufficiently large number of quadrature points.

function [pArrayOut, hArrayOut, success] = ...
    SDpathODEuler_extend_coarse_path(pIn, hIn, phaseCoeffs, SPs, ...
    baseStepSize, maxPts, pNewMax)

    % get polynomial order of phase from length of coefficients
    order = length(phaseCoeffs)-1;

    % get coefficients of derivatives of phase function
    diffPhaseCoeffs = phaseCoeffs(1:(end-1)).*(order:-1:1);
    doubleDiffPhaseCoeffs = diffPhaseCoeffs(1:(end-1)).*((order-1):-1:1);

    % main loop

    % start extension at the end of the previous contour approx:
    contourEndpoint = hIn(end);

    % initialise h(p) and p approx arrays
    pArray = zeros(maxPts,1);
    hArray = zeros(maxPts,1)+eps*1i;
    numPts = length(pIn);
    % initialise with previous contour approx
    pArray(1:numPts) = pIn;
    hArray(1:numPts) = hIn;
    success = true;

    % continue to extend contour until parametrisation value p is
    % sufficiently large
    while pArray(numPts)<pNewMax
        numPts = numPts+1;

        % get value of derivatives h'(p), h''(p) at this point on approx SD
        % path:
        diffPhaseAtContourEndpoint = polyval(diffPhaseCoeffs,contourEndpoint);
        doubleDiffPhaseAtContourEndpoint = polyval(doubleDiffPhaseCoeffs,contourEndpoint);

        % get value of ODE for this value of h and p
        odeVal = 1i/diffPhaseAtContourEndpoint;

        % determine step size based on standard estimate and distance to
        % the nearest stationary point, as explained in the paper
        p_step_size = baseStepSize*min(...
                    abs(diffPhaseAtContourEndpoint^2/doubleDiffPhaseAtContourEndpoint),...
                    min(abs(SPs-contourEndpoint))/abs(odeVal));

        % step along approx contour
        contourEndpoint = contourEndpoint + p_step_size*odeVal;

        % increase value of p as required
        pArray(numPts) = pArray(numPts-1)+p_step_size;

        % update endpoint of contour
        hArray(numPts) = contourEndpoint;

        % break while look if max number of points is reached
        if numPts==maxPts
            success = false;
            break
        end
    end

    % truncate output arrays so that they only contain meaningful data
    pArrayOut = pArray(1:numPts);
    hArrayOut = hArray(1:numPts);

end