function [a,b,params] = Jordan_rotate(a,b,valleys,params)
    J = length(valleys);
    safety_width = (1+100*eps)*pi/(2*J);
%rotates endpoints so they are exactly at valley
    if params.infContour(1)
        % swap back to old format
        a = exp(1i*a);
        [a_min_dist,a_mindex] = min(abs(exp(1i*angle(valleys))-exp(1i*angle(a))));
        a = valleys(a_mindex);
        if abs(a_min_dist)>safety_width
            error('First endpoint is in a complex hill');
        end
    end
    if params.infContour(2)
        % swap back to old format
        b = exp(1i*b);
        [b_min_dist,b_mindex] = min(abs(exp(1i*angle(valleys))-exp(1i*angle(b))));
        b = valleys(b_mindex);
       if abs(b_min_dist)>safety_width
            error('Second endpoint is in a complex hill');
        end
    end
end