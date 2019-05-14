function [passFail, z, w] = quadraticPointsTest(freq,Npts)
%tests the actual positioning and weighting of the points for a quadratic
%phase,
%compared with values obtained by computing exact inverse of phase
    

    f = @(x) x.^4;
    
    %Do NSD as in Daan's book:

    %h0 = @(p) sqrt(1i*p.^2);
    h0m = @(p) -sqrt(1i*p.^2);
    hm1 = @(p) -sqrt(1+1i*p);
    hp1 = @(p) sqrt(1+1i*p);
    
    %dh0p = sqrt(1i);
    dhm1 = @(p) .5i./hm1(p);
    dhp1 = @(p) .5i./hp1(p);
    
    [xm1, wm1_] = quad_gauss_laguerre(Npts);
    [xp1, wp1_] = quad_gauss_laguerre(Npts);
    [x0, w0_] = quad_gauss_hermite(2*Npts);
    z = [hm1(xm1/freq); h0(x0/sqrt(freq)); hp1(xp1/freq);];
    w = [exp(1i*freq).*dhm1(xm1/freq)./freq.*wm1_; sqrt(1i/freq)*w0_; -exp(1i*freq).*dhp1(xp1/freq)./freq.*wp1_];
    
    passFail = true;
    
    Ibh = f(z).'*w;
    
    %now compute the PathFinder val:
    [zpf,wpf] = PathFinderQuad(-1, 1, [1 0 0], freq, Npts, 'numOscs', .1/freq, 'turbo on');
    Ipf = f(zpf).'*wpf;
    
    %the Matlab val:
    Iml = integral(@(x) f(x).*exp(1i*freq*x.^2),-1,1,'RelTol',eps);
    
    fprintf('\nBy-hand vs Matlab brute force: %e',abs(Ibh-Iml)/abs(Iml));
    fprintf('\nPathFinder vs Matlab brute force: %e\n',abs(Ipf-Iml)/abs(Iml));
    
    %hold off; plot(z,'x'); hold on; plot(zpf,'o'); hold off;
    
    hold off; semilogy(abs(w-wpf)./abs(w),'x'); hold on; semilogy(abs(z-zpf),'o');
    semilogy(exp(-[xm1; x0; xp1;]));
    ylim([eps max([abs(w-wpf)./abs(w); abs(z-zpf); 1])] );
    legend('weights diff', 'nodes diff', 'exp weight');
    
    passFail = true;
    
    function z = h0(p)
        z = [];
         for p_= p.'
            if p_<0
                z = [z; h0m(p_)];
            else
                z = [z; -h0m(p_)];
            end
         end
    end
end

