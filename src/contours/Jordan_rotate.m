function [a,b,params] = Jordan_rotate(a,b,valleys,params)
%rotates endpoints so they are exactly at valley
    if isinf(a) || params.infContour(1)
        [~,a_mindex] = min(abs(exp(1i*angle(valleys))-exp(1i*angle(a))));
        a = valleys(a_mindex);
        params.infContour(1) = true;
        if isinf(a) % map back to unit circle
            a = exp(1i*angle(a));
        end
    end
    if isinf(b) || params.infContour(2)
        [~,b_mindex] = min(abs(exp(1i*angle(valleys))-exp(1i*angle(b))));
        b = valleys(b_mindex);
        params.infContour(2) = true;
        if isinf(a) % map back to unit circle
            b = exp(1i*angle(b));
        end
    end
end