function SEs = get_stepest_exits_on_ball(g_coeffs,centre,radius)
    imag_thresh = 0.1;
    rho = length(g_coeffs)-1; % order of g'(z)
%     
    A = complex(zeros(rho+1)); % matrix of indices of double sum
    dA = complex(zeros(rho+1)); % matrix of indices of double sum, deriv
    a = (zeros(rho+1,1)); % cosine indices
    b = (zeros(rho+1,1)); % sine indices
    da = (zeros(rho+1,1)); % cosine indices, deriv
    db = (zeros(rho+1,1)); % sine indices, deriv

    %%  compute Fourier indices (notation as in my notes)
    for j=0:rho
        for k=0:j
            main_coeff = nchoosek(j,k)*radius^k*centre^(j-k)*g_coeffs(rho-j+1);
            A(j+1, k+1) = k*main_coeff;
            dA(j+1, k+1) = k^2*main_coeff;
        end
    end

    % filtering in this way isolates the imaginary part of g'(z):
    for k=0:rho
        d_jk = sum(A(:,k+1));
        a(k+1) = real(d_jk);
        da(k+1) = -imag(d_jk);
        if k>0
            b(k+1) = -imag(d_jk);
            db(k+1) = -real(d_jk);
        end
    end

%     binomial_check;
%       imag_check();
% binomial_check();
 
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
    turning_points = real(complex_angular_roots(abs(imag(complex_angular_roots))<imag_thresh));
%     dg_coeffs = diff_coeffs(g_coeffs);
%     ddg_coeffs = diff_coeffs(dg_coeffs);

    tp_vals = zeros(size(turning_points));
    for k_=0:rho
        tp_vals = tp_vals+(da(k_+1)*cos(k_*turning_points));
        if k_>0
            tp_vals = tp_vals+(db(k_+1)*sin(k_*turning_points));
        end
    end

    SEs = centre+radius*exp(1i*turning_points(tp_vals<0));

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
 
%     function binomial_check()
%         theta = linspace(0,2*pi);
%         dg_coeffs = diff_coeffs(g_coeffs); % coefficients of dg/dz
%         plot(theta,real(polyval(dg_coeffs,centre+radius*exp(1i*theta))),'b:');
%         val = zeros(size(theta));
%         for k_=0:rho
%             c_k = sum(A(:,k_+1));
%             val = val+c_k*exp(1i*k_*theta);
%         end
%         hold on;
%         plot(theta,real(val),'rx');
%     end
% % 
%     function imag_check()
%         theta = linspace(0,2*pi);
%         dg_coeffs = diff_coeffs(g_coeffs); % coefficients of dg/dz
%         plot(theta,imag(polyval(g_coeffs,centre+radius*exp(1i*theta))),'b');
%         val = zeros(size(theta));
%         for k_=0:rho
%             val = val+a(k_+1)*cos(k_*theta);
%             if k_>0
%                 val = val+b(k_+1)*sin(k_*theta);
%             end
%         end
%         hold on;
%         plot(theta,val,'r');
%         legend('g(z)','Im g(z)');
%     end
end