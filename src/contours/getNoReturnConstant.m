function C = getNoReturnConstant(coeffs)
% computes the constant which determines how large / narrow the SD path
% must be before it cannot leave the complex segment
    deg = length(coeffs)-1;
    C = sum(fliplr(1:(deg-1)).*abs(coeffs(1:(deg-1))))/(deg*coeffs(1));
end

