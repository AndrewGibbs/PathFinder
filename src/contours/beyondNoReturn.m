function [value,v_index] = beyondNoReturn(h,Cnr,argBeta,V)
%function corresponding to an event which would halt ODE solve, because SD
%path is at 'point of no return'.

wiggle_room = 0.95;

    % the 'no return test'
    order = length(V);
    R = abs(h);
    theta = mod(angle(h),2*pi);
%     theta_diff = wiggle_room*pi/(2*order);

    [~,v_index] = min(abs(exp(1i*angle(V))-exp(1i*angle(h))));
    v = mod(angle(V(v_index)),2*pi);

    theta_in_diff = min(abs([theta-v, theta-v-2*pi theta-v+2*pi]));
    theta_diff = max(theta_in_diff,pi/(4*order));
    % if theta_diff is less than this optimal value, truncate it there

%     for v = mod(angle(V),2*pi)
%         first check if theta_end is pointing sufficiently close to valley
    theta_L = mod(v-theta_diff-10*eps,2*pi);
    theta_R = mod(v+theta_diff+10*eps,2*pi);
    in_arc = false;
    if theta_L<theta_R
        if theta_L<theta && theta< theta_R
            in_arc = true;
        end
    else % arc endpoints are either side of zero=2pi
        if theta_L<theta % case where theta_L is to left of zero=2pi
            in_arc = true;
        elseif theta<theta_R % case where theta_L is to right of zero=2pi
            in_arc = true;
        end
    end

    if in_arc && ...
        R>1 && R*min([sin(order*(v+theta_diff+argBeta/order)) cos(order*(v-theta_diff+argBeta/order))])>Cnr...
        && theta_diff<pi/(2*order)
        value = true;
    else
        value = false;
    end
%     end
end

