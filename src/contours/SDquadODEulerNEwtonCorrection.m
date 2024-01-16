% This routine linearly interpolates the coarse solve, and applies a Newton
% iteration to accurately compute the quadrature nodes along the steepest
% descent path.

function [hQuadArray, dhdpQuadArray, newtonStepsToConverge] = ...
            SDquadODEulerNEwtonCorrection(pQuad, pCoarse, h0, ...
            hCoarse, phaseCoeffs, freq, newtonThresh, maxNumNewtonIts)

    % initialise quadrature points along contour
    hQuadArray = zeros(size(pQuad))+1i*eps;
    newtonStepsToConverge = ones(size(pQuad));
    freqTimesPhaseAtExit = freq*polyval(phaseCoeffs,h0);

    % get order from length of phase coefficients
    order = length(phaseCoeffs)-1;

    % get coefficients of derivative of phase function
    dPhaseCoeffs = phaseCoeffs(1:(end-1)).*(order:-1:1);

    % get function for (frequency-dependent) ODE at h
    odeAt_h = @(h) 1i./(polyval(dPhaseCoeffs,h))/freq;

    for iQuad=1:length(pQuad)
        % linearly interpolate coarse solve for initial guess
        [pBelow, coarseIndex] = max(pCoarse(pCoarse<=pQuad(iQuad)));

        % here pBelow is the largest value of pCoarse that is below pQuad.
        %pCoarse should always contain a zero at the first entry, so the
        %above code cannot return an empty vector.
        
        % get intermediate step size
        pWidth = pQuad(iQuad)-pBelow;

        % linearly interpolate to get initial guess
        hQuadArray(iQuad) = hCoarse(coarseIndex) ...
                            + pWidth*odeAt_h(hCoarse(coarseIndex));

        % apply Newton corrector to this initial guess
        for iNewton = 1:maxNumNewtonIts

            % update current value of h'_j
            currentDiffAtQuadPoint = polyval(dPhaseCoeffs, hQuadArray(iQuad));

            % ... which is needed for the Newton step below
            newtonStep = getNewtonStep();

            % adjust the quadrature point using the Newton step
            hQuadArray(iQuad) = hQuadArray(iQuad) - newtonStep;

            % calculate the error using the Newton step
            err = abs(newtonStep);
            if err < newtonThresh
                newtonStepsToConverge(iQuad) = iNewton;
                break;
            elseif iNewton == maxNumNewtonIts
                newtonStepsToConverge(iQuad) = iNewton+1;
                break;
            end
        end
    end

    % now get Jacobian at each quadrature point, also needed for quadrature
    dhdpQuadArray = odeAt_h(hQuadArray);

    % indented function to compute the Newton step
    function s = getNewtonStep()
        s = ((-freqTimesPhaseAtExit + ...
                freq*polyval(phaseCoeffs,hQuadArray(iQuad)))...
                - 1i*pQuad(iQuad))/(freq*currentDiffAtQuadPoint);
    end
    % note the difference between these Newton steps and those earlier in
    % the code - here things depend on the frequency parameter
end