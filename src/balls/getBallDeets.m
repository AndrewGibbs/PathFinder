% This function extracts relevant data from a cell array of type Ball,  in 
% terms of numerical arrays, so that it can be passed to a mex function
function [ballCentres, ballRadii, nonEndpointBallCentres, ...
                nonEndpointBallRadii] = getBallDeets(BallCellArray)

    % initialise arrays
    numBalls = length(BallCellArray);
    ballCentres = zeros(numBalls,1);
    ballRadii = zeros(numBalls,1);

    % get the radius and centre from each ball
    for iBall = 1:numBalls
        ballRadii(iBall) = BallCellArray{iBall}.radius;
        ballCentres(iBall) = BallCellArray{iBall}.centre;
    end

    % make new arrays which exclude the endpoints (these can be filtered
    % out using the fact that endpoint balls have zero radius).
    nonEndpointBallCentres = ballCentres(ballRadii>0);
    nonEndpointBallRadii = ballRadii(ballRadii>0);
end