function G = getHandlesFromCoeffs(polyCoeffs)
    G{1}=@(x) polyval(polyCoeffs,x);
    Dpolycoeffs=polyCoeffs(1:(order)).*fliplr(1:(order));
    for n = 2:2*(order+1)
        G{n} = @(x) polyval(Dpolycoeffs,x);
        Dpolycoeffs=Dpolycoeffs(1:(order-n+1)).*fliplr(1:(order-n+1));
    end
end

