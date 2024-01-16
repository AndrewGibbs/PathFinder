function [a,b,Params] = JordanRotate(a,b,valleys,Params)
    % here (a,b) are the original endpoints, before deformation

    % calculate the angular width that an infinite endpoint can deviate
    % from the true valley, such that the integral has the same value
    numValleys = length(valleys);
    deformableWidth = (1+100*eps)*pi/(2*numValleys);

    %rotates endpoints so they are exactly at valley
    if Params.infContour(1)
        % convert to point on unit circle
        aOnCircle = exp(1i*a);

        % get index of closest valley
        [~, aMinDistIndex] = min(abs(exp(1i*angle(valleys)) - exp(1i*angle(aOnCircle))));

        % get anglular distance to closest valley
        aPreModAngleDist = angle(valleys(aMinDistIndex)) - a;
        aMinAngleDist = min(abs([aPreModAngleDist aPreModAngleDist-2*pi aPreModAngleDist+2*pi]));

        % check deformation doesn't start in a hill
        if abs(aMinAngleDist)>deformableWidth
            error('First endpoint is in a complex hill');
        else
            % if not, overwrite a with the value at the valley
            a = valleys(aMinDistIndex);
        end
        
    end
    if Params.infContour(2)
        % convert to point on unit circle
        bPreModAngleDist = exp(1i*b);

        % get anglular distance to closest valley
        [~, bMinDistIndex] = min(abs(exp(1i*angle(valleys)) - exp(1i*angle(bPreModAngleDist))));
        
        % get anglular distance to closest valley
        bPreModAngleDist = angle(valleys(bMinDistIndex)) - b;
        bMinAngleDist = min(abs([bPreModAngleDist bPreModAngleDist-2*pi bPreModAngleDist+2*pi]));

       % check deformation doesn't start in a hill
       if abs(bMinAngleDist)>deformableWidth
            error('Second endpoint is in a complex hill');
       else
           % if not, overwrite b with the value at the valley
            b = valleys(bMinDistIndex);
       end
    end
end