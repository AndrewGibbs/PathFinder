function [value,v_index] = beyondNoReturn_v2(h,V,g_coeffs,r_star)
%function corresponding to an event which would halt ODE solve, because SD
%path is at 'point of no return'.

    % the 'no return test'
    value = false;
    v_index = [];
    order = length(V);
    R = abs(h);
    if R>r_star % first test, based on length of z

        % now check that path is sufficiently close to monomial SD path
        [~,v_index] = min(abs(exp(1i*angle(V))-exp(1i*angle(h))));
        v = mod(angle(V(v_index)),2*pi);
    
        theta = mod(angle(h),2*pi);
        theta_diff = min(abs([theta-v theta-v-2*pi theta-v+2*pi]),[],2);
%         theta_diff = max(theta_in_diff,pi/(4*order));

        if theta_diff < pi/(2*order)
            % now check Dave's refined polynomial condition
            G = order*abs(g_coeffs(1))*R^(order-1)*min(1/sqrt(2),cos(order*theta_diff));
            for j=1:(order-1)
                G = G - j*abs(g_coeffs(end-j))*R^(j-1);
                if G<=0 % G isn't getting any bigger
                    break;
                end
            end
            if G>0
                value = true;
            end
        end
    end

end

