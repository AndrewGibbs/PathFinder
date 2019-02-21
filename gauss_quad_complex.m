function [z,w,dz] = gauss_quad_complex(a,b,N)
%computes standard Gauss quad along complex line, w are real weights but dz
%corresponds to z'(p) if p parametrises complex line segment
    [z, w] = gauss_quad(a, b, N);
        dz = (b - a)/abs(b - a);
end

