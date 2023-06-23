function col_roots = colleague(coeffs)

%% convert to Chebyshev basis
    cheb_coeffs = mon2cheb(coeffs);

%% construct colleague matrix
    a = flip(cheb_coeffs);
    N = length(cheb_coeffs)-1;
    A = zeros(N);

    % bottom row
    for j=1:N
        A(N,j) = -1*a(j)/(2*a(end));
    end

    % the halves
    for j=1:N
        if j<N
            A(j,j+1)=A(j,j+1) + 1/2;
        end

        if j>1
            A(j,j-1)= A(j,j-1) + 1/2;
        end
    end

    % the entry at (1,2)
    A(1,2) = 1;

%% solve the eigenvalue problem

    col_roots = eig(A);
end