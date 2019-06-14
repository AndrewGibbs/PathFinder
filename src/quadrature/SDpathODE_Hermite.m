function [z, W] = SDpathODE_Hermite(Npts, g, dg, ddg, dddg, k, h0, dh0m_est, tol, turbo)

    ODEthresh = 1e-8;
    turboThresh = 1e-10;

    %first, determine ICS, based on estimates of previous and next h'(p)
    
    dh0 = sqrt(2*1i/(k*ddg(h0)))*[-1 1];
    
    [~, minDex] = min(abs(dh0m_est/norm(dh0m_est)-dh0/norm(dh0)));
    
    if minDex == 2
        dh0 = fliplr(dh0);
    end
    
    [p_init,w] = quad_gauss_hermite(Npts);
    
    if mod(Npts,2) == 0 % Npts even
       NptsEven = true;
       p_minus = p_init(1:Npts/2);
       p_plus = [0; p_init((1+Npts/2):end)];
    else % Npts odd
       NptsEven = false;
       p_minus = p_init(1:(Npts-1)/2);
       p_plus = p_init((Npts+1)/2:end);
    end
    
    %solve using ODE45 at a given tolerance:
    [Pminus,Hminus] = ode45(@(p,H) ODE_dH(p,H), p_plus, [h0 dh0(1)], odeset('RelTol', tol));
    
    %solve using ODE45 at a given tolerance:
    [Pplus,Hplus] = ode45(@(p,H) ODE_dH(p,H), p_plus, [h0 dh0(2)], odeset('RelTol', tol));
    
    %now mash the plus & minus bis together:
    P = p_init;
    if NptsEven
        z = [flipud(Hminus(2:end,1)); Hplus(2:end,1)];
        dhdp = [-flipud(Hminus(2:end,2)); Hplus(2:end,2)];
    else
        z = [flipud(Hminus(2:end,1)); h0; Hplus(2:end,1)];
        dhdp = [-flipud(Hminus(2:end,2)); dh0(2); Hplus(2:end,2)];
    end
    
    %z = h; % = h(p_j)
    
    %if this doesn't work - could formulate the Halley problem using
    % g(h(p)) = g(\xi) + ip, over p\in(-inf,inf) and rescale the p quad points to match this.
    % This only has one local minimum. Then, can use the same eqn for h'(p)
    % as currently, as this is not singular so more stable for small p.
    
    if turbo
       %turboThresh = 1e-10;
            Zold=z;
            ZnewMaybe = NaN(size(Zold));
            dZdp = ZnewMaybe;
            HalleySuccess = true;
            for n = 1:length(Zold) %iterate over all quad points
                [success, z_new] = HalleySD(Zold(n),{g, dg, ddg},P(n),2,h0,k,turboThresh);
                if success
                    ZnewMaybe(n) = z_new;
                    dZdp(n) =  2*1i*P(n)/(k*dg(ZnewMaybe(n)));
                else
                    HalleySuccess = false;
                    break;
                end
                clear z_new;
            end
            if HalleySuccess
                z = ZnewMaybe;
                dhdp = dZdp;
            end 
    else
        HalleySuccess = false;
    end
    
    if HalleySuccess == false
        weightWatchers = exp(1i*(k*g(z) - 1i*P.^2 - k*g(h0)));
    else
        weightWatchers = 1;
    end
    
    W= w.*exp(1i*k*g(h0)).*dhdp.*weightWatchers;
    
    function LH = ODE_dH(p,H)
        %Theoretical ODE becomes numerically unstable for small p. However,
        %the ODE can be approximated for small p by a stable ODE.
        
        %ODE for path of steepest descent:
        %efine H(p) = [h(p); h'(p)], with the ODE
        if p>ODEthresh
            LH = [H(2); (2i/k - (H(2).^2*ddg(H(1))))./dg(H(1))]; 
        else
            LH = [H(2); -dddg(H(1))*(H(2)).^2./(3*ddg(H(1)))];
        end
    end
   
end