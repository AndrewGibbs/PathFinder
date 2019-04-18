function Z = levelSetFailsafe(xi,C,g,freq,N)
%slow but reliable approach to computing the level sets
    contourFix = @(z) freq*abs(g(xi)-g(z));
    radGuess = .2*C/freq;
    foundOurGuy = false;
    
    while ~foundOurGuy
        x = linspace(-radGuess,radGuess,N^2);
        Z = xi + x + 1i*x.';
        c = contourc(real(xi) + x, imag(xi) + x, contourFix(Z), [C C]);
        
        if ~isempty(c)
            c_split = contourdata(c);

            for n = 1:length(c_split)
               if inpolygon(real(xi),imag(xi),c_split(n).xdata,c_split(n).ydata)...
                        && ~c_split(n).isopen
                   C_out = c_split(n);
                   foundOurGuy = true;
               end
            end
        end
        
        radGuess = radGuess*2;
            
    end
    Z = C_out.xdata + 1i*C_out.ydata;
end

