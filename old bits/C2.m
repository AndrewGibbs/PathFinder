
Npts=30;
h=.2;
visuals = false;
a=exp(1i*9*pi/10);
b=exp(1i*pi/10);
X=-10:h:10;
Y=-10:h:10;
% -----------------------------------
A31 = @(x,y) A(x,y,a,b,Npts,visuals);

tic;
xCount = 0;
for x = X
    xCount = xCount + 1;
    yCount = 0;
    fprintf('\nx=%.2f',x)
    for y = Y
        yCount = yCount + 1;
        u(xCount,yCount) = A31(x,y);
        fprintf('\n\ty=%2.2f\t%.2f %%', y, 100*(length(Y)*(xCount-1)+yCount)/(length(X)*length(Y)));
        if visuals
            title(sprintf('x=%d, y=%d', x, y));
            imPathName=sprintf('PearceyImages\\x%dy%d',x,y);
            imPathNamJHPG=sprintf('x%dy%d.jpg',x,y);
            savefig(imPathName);
            saveas(gcf,imPathNamJHPG);
            close;
        end
    end
end

T=toc;
fprintf('\n Time = %f\n',T);
surf(X,Y,abs(u).');
view([0 90]); colorbar; %shading interp;