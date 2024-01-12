function [z,w,dz,centres] = GQfancy(covers,a,b,a_index,b_index,intersectionMatrix,N)
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
        centres(n) = covers{n}.centre;
    end
    
%     if false%min(inCover) % z fully inside covered region
%         return;
    if length(seq) > 1
        z = []; w = []; dz = [];
        nodes = unique([a nodes b],'stable'); %can get endpoints of integration region appearing twice in here
        for n = 1:(length(nodes)-1)%x = nodes(2:end)
            [z_,w_,dz_] = gauss_quad_complex(nodes(n),nodes(n+1),N);
            z = [z; z_];
            w = [w; w_];
            dz = [dz; dz_];
        end
    end
end