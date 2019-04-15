function [z,w,dz] = gauss_quad_complex(a,b,N)
%computes standard Gauss quad along complex line, w are real weights but dz
%corresponds to z'(p) if p parametrises complex line segment
    L = abs(b-a);
    [s, w] = gauss_quad(0, L, N);
    dz = (b - a)/L;
    z = a + s*dz;
end

