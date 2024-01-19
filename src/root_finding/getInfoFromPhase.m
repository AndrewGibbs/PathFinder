% computes stationary points, valleys and phase function handle,
% given phase coefficients.
function [phaseHandle, stationaryPoints, valleys] = getInfoFromPhase(phaseCoeffs)

    if ~isvector(phaseCoeffs)
        error('Phase input must be array of coefficients of polynomial');
    end

    % force coefficients vector into horizontal form
    phaseCoeffs = phaseCoeffs(:).';

    % determine the polynomial order/degree
    order = length(phaseCoeffs)-1;
    
    % get the coefficients of the derivative of the phase
    diffPhaseCoeffs = phaseCoeffs(1:(order)).*fliplr(1:(order));

    % determine the stationary points of the phase function, using Matlab's
    % companion matrix approach:
    stationaryPointsInit = sort(roots(diffPhaseCoeffs));
    stationaryPoints = stationaryPointsInit.';
    
    % create phase handle
    phaseHandle = @(z) polyval(phaseCoeffs,z);

    % create the valleys, as points on the unit circle
    valleyRotate = exp(-1i*angle(phaseCoeffs(1))/order);
    valleys = valleyRotate*exp(2i*pi*(1/4 + (1:order))/order);

end

