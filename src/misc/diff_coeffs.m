function dG_ = diff_coeffs(G_)
    dG_ = G_.*((length(G_)-1):-1:0);
    dG_ = dG_(1:(end-1));
end