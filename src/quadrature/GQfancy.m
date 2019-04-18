function [z,w,dz] = GQfancy(covers,a,b,a_index,b_index,intersectionMatrix,N)
% returns a sequence of Gaussian quadrature rules which avoid cutting
% corners of non-convex covers
    [z,w,dz] = gauss_quad_complex(a,b,N);
    
    % solve the shortest path problem
    Gr = graph(intersectionMatrix,'upper');
    seq =shortestpath(Gr,a_index,b_index);
    
    %check that z is totally inside covered region
    inCover = false(size(z));
    nodes = [];
    for n = seq
        inCover = max(inCover , covers{n}.isIn(z));
        nodes = [nodes covers{n}.pseudoCentre];
    end
    
    if min(inCover) % z fully inside covered region
        return;
    else
        nodes = [a nodes b];
        z = [];
        for x = nodes(2:end)
            [z_,w_,dz_] = gauss_quad_complex(a,b,N);
            z = [z; z_];
            w = [w; w_];
            dz = [dz; dz_];
        end
    end
end