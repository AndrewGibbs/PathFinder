function [quadIngredients_out, max_val] = fliterPaths(quadIngredients,g,freq,thresh)
    used_points = [];
    quad_ingredient_index = [];
    count = 0;
    num_strln_samples = 15;
    for q = quadIngredients
        count = count + 1;
        if ~isempty(q{1})
            if strcmp(q{1}.type,'infSD')
                used_points = [used_points q{1}.contour.startPoint];
                quad_ingredient_index = [quad_ingredient_index count];
            elseif strcmp(q{1}.type,'finSD')
                % add both endpoints, as it's a finite path
                used_points = [used_points q{1}.contour.startPoint q{1}.contour.endPoint];
                quad_ingredient_index = [quad_ingredient_index count count];
            elseif strcmp(q{1}.type,'strLn')
                used_points = [used_points linspace(q{1}.a, q{1}.b, num_strln_samples)];
                quad_ingredient_index = [quad_ingredient_index count*ones(1,num_strln_samples)];
            end
        end
    end

    count = 0;
    max_val = max(abs(exp(1i*freq*g(used_points))));
    for n=1:length(quadIngredients)
        relevant_CPs = used_points(quad_ingredient_index==n);
        keep_bits = false;
        % if any bits of the quad ingredient are above the threshold, keep
        % the entire integreient
        for SP = relevant_CPs
            if max_val*thresh <= abs(exp(1i*freq*g(SP)))
                keep_bits = true;
            end
        end
        if keep_bits
            count = count + 1;
            quadIngredients_out{count} = quadIngredients{n};
        end
    end
end