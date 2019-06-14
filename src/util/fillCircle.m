function fillCircle(c,r)
    N = 1000;
    %x = linspace(-r,r,N);
    theta = linspace(0,2*pi,N);
    z = c+r*exp(1i*theta);
%     z = c + x + 1i*x.';
%     circlePixels = (real(z) - real(c)).^2 ...
%     + (imag(z) - imag(c)).^2 < r.^2;
%     image(real(c)+x,imag(c)+x,circlePixels);
    fill(real(z), imag(z),[0.8 0.8 0.8],'EdgeColor',[0.8 0.8 0.8]);
    %set(h,'EdgeColor','none');
    %colormap([1 1 1; 0.7 0.7 0.7;]);
end

