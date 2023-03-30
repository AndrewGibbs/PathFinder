function [SEn, P, err] = get_stepest_entrances_on_ball(g_coeffs, centre, radius, start_point, SEn_guess)
    rho = length(g_coeffs)-1; % order of g'(z)
%     
    A = complex(zeros(rho+1)); % matrix of indices of double sum
    a = (zeros(rho+1,1)); % cosine indices
    b = (zeros(rho+1,1)); % sine indices

    %%  compute Fourier indices (notation as in my notes)
    for n=0:rho
        for k=0:n
            main_coeff = nchoosek(n,k)*radius^k*centre^(n-k)*g_coeffs(rho-n+1);
            A(n+1, k+1) = main_coeff;
        end
    end

    % filtering in this way isolates the imaginary part of g'(z):
    for k=0:rho
        c_nk = sum(A(:,k+1));
        a(k+1) = real(c_nk);
        if k>0
            b(k+1) = -imag(c_nk);
        end
    end

    % subtract off the constant part
    a(1) = a(1) - real(polyval(g_coeffs,start_point));
 
    %%  now find zeros of Fourier series using colleague method
    %( notation as in Boyd)
    % construct Frobenius matrix (with zeros in final row)
    B = complex([ zeros(2*rho-1,1) eye(2*rho-1,2*rho-1) ; zeros(1,2*rho)]);
    % now construct final row
    for k=1:(2*rho)
        B(end,k) = -get_h_j(k-1)/(a(end) - 1i*b(end));
    end

    % convert eigenvalues to roots
    [~,E] = eig(B);
    eig_vals = diag(E);
    complex_angular_roots = angle(eig_vals) - 1i*log(abs(eig_vals));
    % now filter out real-valued roots
%     turning_points = real(complex_angular_roots(abs(imag(complex_angular_roots))<imag_thresh));
%     turning_points = complex_angular_roots;

    possible_SEns = centre + radius*exp(1i*complex_angular_roots);
    [err, SEn_index] = min(abs(possible_SEns-SEn_guess));
    SEn = possible_SEns(SEn_index);
    P = real((polyval(g_coeffs,SEn)-polyval(g_coeffs,start_point))/1i);

    function h_j = get_h_j(j)
        N = rho;
        if j<N
            h_j = a(N-j+1)+1i*b(N-j+1);
        elseif j==N
            h_j = 2*a(1);
        else
            h_j = a(j-N+1)-1i*b(j-N+1);
        end
    end
end