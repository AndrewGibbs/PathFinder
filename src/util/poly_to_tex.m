function tex = poly_to_tex(g_coeffs)
    N = length(g_coeffs);
    tex = '$';
    if N>2
        n = 1;
        tex = [tex,coeff2tex(g_coeffs(n),2),'x^',num2str(N-n+1)];
        for n=2:(N-2)
            if sign(g_coeffs(n))>0
                tex = [tex,'+',coeff2tex(g_coeffs(n),2),'x^',num2str(N-n+1)];
            elseif sign(g_coeffs(n))<0
                tex = [tex,coeff2tex(g_coeffs(n),2),'x^',num2str(N-n+1)];
            end
        end
        n = N-1;
        if sign(g_coeffs(n))>0
            tex = [tex,'+',coeff2tex(g_coeffs(n),2),'x'];
        elseif sign(g_coeffs(n))<0
            tex = [tex,coeff2tex(g_coeffs(n),2),'x'];
        end
        
        n = N;
        if sign(g_coeffs(n))>0
            tex = [tex,'+',coeff2tex(g_coeffs(n),2)];
        elseif sign(g_coeffs(n))<0
            tex = [tex,coeff2tex(g_coeffs(n),2)];
        end
    end
    tex = [tex,'$'];
    function num_tex = coeff2tex(n,dps)
        if n==1 && n<N
            num_tex = '';
        elseif n==-1 && n<N
            num_tex = '-';
        elseif n~=0
            num_tex = num2str(n,dps);
        end
    end
end