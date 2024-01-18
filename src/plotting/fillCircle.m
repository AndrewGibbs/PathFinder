% Plots a solid circle.
% This function is used to produce the PathFinder plots, which show the
% balls around the stationary points.
function fillCircle(c,r,colour)
    % default to this shade of grey
    if nargin ==2
        colour = [0.8 0.8 0.8];
    end

    % create the complex circle
    numCircPts = 1000;
    theta = linspace(0, 2*pi, numCircPts);
    z = c+r*exp(1i*theta);

    % draw the circle and fill the interior
    fill(real(z), imag(z),colour,'EdgeColor',colour);
end

