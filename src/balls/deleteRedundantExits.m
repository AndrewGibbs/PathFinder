% Sometimes, the exit from a ball will start off inside of another
%ball. These lead to creation of uneccesay short contours, and needless
% computations later on. This function deletes the steepest exits,
% before contours are created.

function ballsOut = deleteRedundantExits(ballsIn)
    
    % if no balls are passed in, return no balls
    if isempty(ballsIn)
        ballsOut = [];
        return;
    end

    % initialise the cell array of balls by copying the input
    ballsOut = ballsIn;
    
    % loop over all balls
    numBalls = length(ballsIn);
    for iBall=1:numBalls
        % loop over each exit on each ball
        for x = ballsIn{iBall}.steepestExits
            % now loop over all *other* balls
            for jBall=[1:(iBall-1) (iBall+1):numBalls]
                % and check if the exit 'x' is inside any of them
                if ballsIn{jBall}.isIn(x)
                    %delete this exit if it's in another ball
                    ballsOut{iBall}.steepestExits(ballsOut{iBall}.steepestExits==x) = [];
                end
            end
        end
    end
end

