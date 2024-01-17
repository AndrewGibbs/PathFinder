function [isInBall, outputIndex] = inAball(h, ballCentres, ballRadii)
% determines if the point h is inside any of the balls

    % assume not, until we know otherwise
    isInBall = false;
    % default index for the case where not in ball
    outputIndex = 0;

    % loop over all balls
    for iBall = 1:length(ballCentres)
        % check if inside a ball
        if abs(h-ballCentres(iBall))<ballRadii(iBall)
            isInBall = true;
            outputIndex = iBall;
            % break loop here, as we only care about being inside of one
            % ball
            break;
        end
    end
end