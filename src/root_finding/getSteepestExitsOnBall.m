% Determines the exits on a ball, by reformulating as a trigonometric polynomial
% rootfinding problem.

% In this code, a few standard Matlab coding conventions are broken, so
% that the code closely resembles the math in Boyd (1986, full reference
% given below) and the derivation in extra_notes /rootfinding_notes.pdf.
function SEs = getSteepestExitsOnBall(phaseCoeffs, centre, radius)
    imagThresh = 0.1; % anything with a larger imaginary part is discarded
    order = length(phaseCoeffs)-1; % order of g'(z)     
    A = complex(zeros(order+1)); % matrix of indices of double sum
    a = (zeros(order+1,1)); % cosine indices
    b = (zeros(order+1,1)); % sine indices
    da = (zeros(order+1,1)); % cosine indices, deriv
    db = (zeros(order+1,1)); % sine indices, deriv

    %%  compute Fourier indices (notation as in my notes)

    % calculate all terms in double sum, so that we can reorder the sum to
    % get coefficients for the trig polymomial
    for j=0:order
        for k=0:j
            A(j+1, k+1) = k*nchoosek(j,k)*radius^k*centre^(j-k)*phaseCoeffs(order-j+1);
        end
    end

    % filtering in this way isolates the imaginary part of g'(z):
    for k=0:order
        % reorder the sum by summing along the j terms
        d_jk = sum(A(:,k+1));
        % coefficient of cos(k\theta) in first derivative:
        a(k+1) = real(d_jk);
        % coefficieint of cos(k\theta) in second derivative
        da(k+1) = -k*imag(d_jk);
        if k>0
            % coefficient of sin(k\theta) in first derivative:
            b(k+1) = -imag(d_jk);
            % coefficient of sin(k\theta) in second derivative:
            db(k+1) = -k*real(d_jk);
        end
    end
 
    %%  now find zeros of Fourier series using colleague method

    % Follow the approach of, and match the notation of:
    % J. P. Boyd (1986) Computing the zeros, maxima and 
    % inflection points of Chebyshev, Legendre and Fourier series: solving 
    % transcendental equations by spectral interpolation and polynomial 
    % rootfinding}, . Eng. Math., 56 (2006), pp. 203–219.

    % construct Fourier-Frobenius matrix (with zeros in final row)
    B = complex([ zeros(2*order-1,1) eye(2*order-1,2*order-1) ; zeros(1,2*order)]);
    % now construct final row
    for k=1:(2*order)
        B(end,k) = -get_h_j(k-1)/(a(end) - 1i*b(end));
    end

    % convert eigenvalues to roots
    [~,E] = eig(B);
    eigenvals = diag(E);
    complexAngularRoots = angle(eigenvals) - 1i*log(abs(eigenvals));
    % now filter out real-valued roots
    turningPoints = real(complexAngularRoots(abs(imag(complexAngularRoots))<imagThresh));

    %% apply second derivative test to determine local maxima
    secondDerivValsAtTurningPoints = zeros(size(turningPoints));
    for k_=0:order
        secondDerivValsAtTurningPoints = ...
            secondDerivValsAtTurningPoints+(da(k_+1)*cos(k_*turningPoints));
        if k_>0
            secondDerivValsAtTurningPoints = ...
                secondDerivValsAtTurningPoints+(db(k_+1)*sin(k_*turningPoints));
        end
    end

    % filter turning points which are maxima
    SEs = centre+radius*exp(1i*turningPoints(secondDerivValsAtTurningPoints<0));

    %% indended function creates the coefficient (7) from Boyd's paper,
    % given the Fourier coefficients a_j and b_j
    function h_j = get_h_j(j)
        N = order; % copied just to be consistent with the paper
        if j<N
            h_j = a(N-j+1)+1i*b(N-j+1);
        elseif j==N
            h_j = 2*a(1);
        else
            h_j = a(j-N+1)-1i*b(j-N+1);
        end
    end
end