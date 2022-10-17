function C = getNoReturnConstant(coeffs)
% computes the constant which determines how large / narrow the SD path
% must be before it cannot leave the complex segment
    deg = length(coeffs)-1;
    C = 0;
    for j=1:(deg-1)
        C = C + abs(j*coeffs(end-j));
    end
    C = C/(deg*abs(coeffs(1)));
    % C = norm(sum(fliplr(1:(deg-1)).*abs(coeffs(1:(deg-1))))/(deg*abs(coeffs(1))));
end

