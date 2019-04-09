function [z, w] = makeQuadV2(quadInfo, freq, Npts, g)

    %make a corretion for standard Gauss, which has a different weight
    %function:
    sgw = @(z) exp(1i*freq*g(z));
    z = []; w = [];
    for n = 1:length(quadInfo)
       switch quadInfo{n}.type
           case {'infSD','finSD'}
               [z_, w__] = quadInfo{n}.contour.getQuad(freq,Npts);
               w_ = w__*quadInfo{n}.inOut;
           case 'strLn'
               [z_, w__, dh_] = gauss_quad_complex(quadInfo{n}.a, quadInfo{n}.b, Npts);
               w_ = w__.*sgw(z_)*dh_;
           otherwise
               error('Do not recognise quad type');
       end
       
       %add to the total quadrature
        z = [z; z_]; 
        w = [w; w_];
    end
end