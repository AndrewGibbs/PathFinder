% Get all non-vanishing derivatives of a polynomial, from its coefficients.
function polyDerivCoeffsCellArray = getHandlesFromCoeffs(polyCoeffs)
    % get the zeroth derivative
    polyDerivCoeffsCellArray{1}=@(x) polyval(polyCoeffs,x);

    % determine the order from the length of the coefficients vector
    order = length(polyCoeffs)-1;

    % get coefficients of derivative of polynomial
    diffPolyCoeffs=polyCoeffs(1:(order)).*fliplr(1:(order));

    for n = 2:2*(order+1)
        % store derivative coefficients in next cell array entry
        polyDerivCoeffsCellArray{n} = @(x) polyval(diffPolyCoeffs,x);
        % differentiate the derivative
        diffPolyCoeffs=diffPolyCoeffs(1:(order-n+1)).*fliplr(1:(order-n+1));
        % repeat iteratively
    end
end

