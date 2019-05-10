function coeffs = getCoeffsFromRoots(roots)
%just for testing
    roots = roots(:).';
    width = length(roots);
    powers = (width-1):-1:0;
    for j = 1:width
       M(j,:) = roots(j).^powers; 
    end
    coeffs = [1; -M\(roots.'.^width)];
end

