C1 = 1.5; % constant scale factor. leave this as one for now.
C2 = 1;
k = 100;

colors = {'b','g','r','c'};

vidLength = 20; %second
esps = [fliplr(logspace(-2,0))];
for esp = esps
    preSPs = [-esp  0 (2i+1)*esp esp]; %this should be chosen to be as nasty as possible, to test the code.
    
    domainWidth = 1/k^(1/(1+length(preSPs)))*(max(real(preSPs))-min(real(preSPs)))/esp;
    
    autoPower = 1/(length(preSPs)+1);

    order = length(preSPs)+1;

    dgCoeffs = poly(preSPs);
    
    dggCoeffs_step1 = ((length(dgCoeffs)-1):-1:1);
    ddgCoeffs = dggCoeffs_step1.*dgCoeffs(1:(end-1));
    
    gCoeffs = [dgCoeffs./(order:-1:1) 0];

    dgRoots = roots(dgCoeffs);
    ddgRoots = roots(ddgCoeffs);

    g = @(z)  polyval(gCoeffs,z);
    dgdz = @(z)  polyval(dgCoeffs,z);
    ddg = @(z)  polyval(ddgCoeffs,z);

    theta = linspace(0,2*pi);
    Z = linspace(min(real(preSPs))-domainWidth,max(real(preSPs))+domainWidth);
    z = Z + 1i*Z.';

    R = C1/(k^autoPower);

    
    %hold on;
    for n = 1:length(dgRoots)
       x = dgRoots(n);
       condish1 = k*abs(g(z) - g(x));
       condish2 = k*abs(dgdz(z));
       condish3 = k*abs(ddg(z))/10;
       contour(Z,Z,condish3,[C2 C2],colors{n});
       hold on;
       contour(Z,Z,condish2,[C2 C2],'r');
       %plot(x + R*exp(1i*theta),strcat(colors{n},'.'));
       plot(dgRoots(n)+eps*1i,strcat(colors{n},'x'));
       plot(ddgRoots+eps*1i,strcat(colors{n},'^'));
    end
    title(sprintf('k = %d, K = %f',round(k),esp));
    hold off;
    pause(vidLength/length(esps));
end