function [value,isterminal,direction] = noReturn(h,Cnr,argBeta,V)
%function corresponding to an event which would halt ODE solve, because SD
%path is at 'point of no return'.

    %event parameters:
    value = 1;
    isterminal = 1;
    direction = 0;

    % the 'no return test'
    order = length(V);
    R = abs(h(end));
    theta_end = mod(angle(h(end)),2*pi);
    theta_diff = 0.95*pi/(2*order);
    
    for v = mod(angle(V),2*pi)
        %first check if theta_end is pointing sufficiently close to valley
        theta_L = mod(v-theta_diff,2*pi);
        theta_R = mod(v+theta_diff,2*pi);
        in_arc = false;
        if theta_L<theta_R
            if theta_L<theta_end && theta_end< theta_R
                in_arc = true;
            end
        else % arc endpoints are either side of zero=2pi
            if theta_L<theta_end % case where theta_L is to left of zero=2pi
                in_arc = true;
            elseif theta_end<theta_R % case where theta_L is to right of zero=2pi
                in_arc = true;
            end
        end

        if in_arc && R>1 && R*min(sin(order*(v+theta_diff+argBeta/order)),cos(order*(v-theta_diff+argBeta/order)))>Cnr && theta_diff<pi/(2*order)
            value = 0;
        end
    end
end

