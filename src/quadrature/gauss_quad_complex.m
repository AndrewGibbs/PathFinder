function [z,w,dz] = gauss_quad_complex(a,b,N)
%computes standard Gauss quad along complex line, w are real weights but dz
%corresponds to z'(p) if p parametrises complex line segment
    if a == b
        z = a;
        w = 0;
        dz = 0;
        return;
    end
    L = abs(b-a);
    [s, w] = gauss_quad(0, L, N);
    s = flipud(s);
    dz = (b - a)/L;
    z = a + s*dz;
    dz = repmat(dz,size(z));
end

