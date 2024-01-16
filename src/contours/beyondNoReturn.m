function [value, vIndex] = beyondNoReturn(h,valleys,phaseCoeffs,rStar)
%function corresponding to an event which would halt ODE solve, because SD
%path is at 'point of no return'.

    % the 'no return test'.

    % output value 'true' if in no return region, 'false' otherwise
    value = false;
    % index of output valley to which h is closest
    vIndex = [];
    % order of polynomial phase is same as number of valleys
    order = length(valleys);
    % get radius of point on SD path
    radius = abs(h);
    if radius > rStar % first test, based on length of z

        % now check that path is sufficiently close to monomial SD path
        [~, vIndex] = min(abs(exp(1i*angle(valleys))-exp(1i*angle(h))));
        v = mod(angle(valleys(vIndex)),2*pi);

        % get angular distance from closest valley
        theta = mod(angle(h),2*pi);
        thetaDiff = min(abs([theta-v theta-v-2*pi theta-v+2*pi]),[],2);

        if thetaDiff < pi/(2*order)
            % first part of polynomial condition
            G = order*abs(phaseCoeffs(1))*radius^(order-1)*min(1/sqrt(2),cos(order*thetaDiff));
            for iCoeffs = 1:(order-1)
                % subtract off remaining parts of polymomial condition
                G = G - iCoeffs*abs(phaseCoeffs(end-iCoeffs))*radius^(iCoeffs-1);
                if G <= 0
                    % G isn't getting any bigger, if condition is broken,
                    % end now.
                    break;
                end
            end
            if G > 0
                % if condition is satisfied, we are in 'no return' region
                value = true;
            end
        end
    end

end

