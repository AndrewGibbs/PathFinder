function [p, h, dhdp] = SDpathODE(pMax, dg, k, h0, tol)
    pMax = pMax(:).';
    %computes NSD path h(p) and h'(p)

    %ODE for path of steepest descent:
    ODEh = @(p,h) 1i./(k*dg(h)); 
    
    %solve using ODE45 at a given tolerance:
    [p,h] = ode45(ODEh, [0 pMax], h0, odeset('RelTol', tol));
    p = p(2:end);
    h = h(2:end);
    
    %reconstruct h'(p) using ODE
    dhdp = ODEh(p,h);
   
end