function [quadIngredients_out, max_val] = fliter_paths(quadIngredients,covers,intersectionMatrix,g,freq,thresh)
    used_CPs = [];
    quad_ingredient_index = [];
    count = 0;
    for q = quadIngredients
        count = count + 1;
        if strcmp(q{1}.type,'infSD')
            used_CPs = [used_CPs q{1}.contour.startPoint];
            quad_ingredient_index = [quad_ingredient_index count];
        elseif strcmp(q{1}.type,'finSD')
            % add both endpoints, as it's a finite path
            used_CPs = [used_CPs q{1}.contour.startPoint q{1}.contour.endPoint];
            quad_ingredient_index = [quad_ingredient_index count count];
        elseif strcmp(q{1}.type,'strLn')
            % solve the shortest path problem
            Gr = graph(intersectionMatrix,'upper');
            %seq =shortestpath(Gr,quadIngredients{3}.a_coverIndex,quadIngredients{3}.b_coverIndex);
            seq =shortestpath(Gr,q{1}.a_coverIndex,q{1}.b_coverIndex);
            for n = seq
                used_CPs = [used_CPs covers{n}.centre];
                quad_ingredient_index = [quad_ingredient_index count];
            end
        end
    end

    count = 0;
    max_val = max(abs(exp(1i*freq*g(used_CPs))));
    for n=1:length(quadIngredients)
        relevant_CPs = used_CPs(quad_ingredient_index==n);
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