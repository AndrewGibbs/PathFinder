C = 1; % constant scale factor. leave this as one for now.
k = 10;
esp = .3;
preSPs = [-esp 0 esp]; %this should be chosen to be as nasty as possible, to test the code.
domainWidth = 1*max(real(preSPs))-min(real(preSPs));
% - - - - - - - - - - - - - - - - - -

order = length(preSPs)+1;

dgCoeffs = poly(preSPs);

gCoeffs = [dgCoeffs./(order:-1:1) 0];

dgRoots = roots(dgCoeffs);

g = @(z)  polyval(gCoeffs,z);

theta = linspace(0,2*pi);
Z = linspace(min(real(preSPs))-domainWidth,max(real(preSPs))+domainWidth);
z = Z + 1i*Z.';

R = C/sqrt(k);

plot(dgRoots+eps*1i,'x');
hold on;
for n = 1:length(dgRoots)
   x = dgRoots(n);
   condish = k*abs(g(z) - g(x));
   contour(Z,Z,condish,[C C]);
   hold on;
   plot(x + R*exp(1i*theta),'.');
end
hold off;

% x = linspace(-2,2);
% z = x + 1i*x.';
% contour(x,x,abs(g(z)),[R R]);
% c = contourc(x,x,abs(g(z)),[R R]);
% c_split = contourdata(c);