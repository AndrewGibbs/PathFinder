function r = plot_no_return(theta,gCoeffs)

    Cnr = getNoReturnConstant(gCoeffs);
    order = length(gCoeffs)-1;
    arg_beta = angle(gCoeffs(1));
    r = zeros(size(theta));
    valleyRotate = exp(-1i*angle(gCoeffs(1))/order);
    V = valleyRotate*exp(2i*pi*(1/4 + (1:order))/order);
    for n = 1:length(r)
        [~,v_index] = min(abs(exp(1i*angle(V))-exp(1i*theta(n))));
        v = mod(angle(V(v_index)),2*pi);
        theta_in_diff = min(abs([theta(n)-v, theta(n)-v-2*pi theta(n)-v+2*pi]));
        if theta_in_diff < pi/(4*order)
            denom = 1/sqrt(2);
        else
            denom = min(sin(order*(v+theta_in_diff+arg_beta/order)),-cos(order*(v+theta_in_diff+arg_beta/order)));
        end
        r(n) = max(Cnr/denom,1);
        if theta_in_diff>=pi/(2*order)
            r(n) = inf;
        end
    end
end