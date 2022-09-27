function quadIngredients_out = fliter_paths(quadIngredients,covers,intersectionMatrix,g,freq,thresh)
    used_SPs = [];
    quad_ingredient_index = [];
    count = 0;
    for q = quadIngredients
        count = count + 1;
        if strcmp(q{1}.type,'infSD')
            used_SPs = [used_SPs q{1}.contour.startPoint];
            quad_ingredient_index = [quad_ingredient_index count];
        elseif strcmp(q{1}.type,'finSD')
            used_SPs = [used_SPs q{1}.contour.startPoint q{1}.contour.endPoint];
            quad_ingredient_index = [quad_ingredient_index count count];
        elseif strcmp(q{1}.type,'strLn')
            % solve the shortest path problem
            Gr = graph(intersectionMatrix,'upper');
            seq =shortestpath(Gr,quadIngredients{3}.a_coverIndex,quadIngredients{3}.b_coverIndex);
            for n = seq
                used_SPs = [used_SPs covers{n}.centre];
                quad_ingredient_index = [quad_ingredient_index count];
            end
        end
    end

    count = 0;
    max_val = max(abs(exp(1i*freq*g(used_SPs))));
    for n=1:length(quadIngredients)
        relevant_SPs = used_SPs(quad_ingredient_index==n);
        keep_bits = false;
        for SP = relevant_SPs
            if max_val*thresh < abs(exp(1i*freq*g(SP)))
                keep_bits = true;
            end
        end
        if keep_bits
            count = count + 1;
            quadIngredients_out{count} = quadIngredients{n};
        end
    end
end