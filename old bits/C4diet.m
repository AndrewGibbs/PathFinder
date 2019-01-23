clear;
Npts=20;
h=1;
visuals = false;
a=exp(1i*17*pi/10);
b=1i;
X=-10:h:10;
Y=-10:h:10;
% -----------------------------------
%A31 = @(x,y) A(x,y,a,b,Npts,visuals);
load('C4');

tic;
xCount = 0;
for x = X
    xCount = xCount + 1;
    yCount = 0;
    %fprintf('\nx=%.2f',x)
    for y = Y
        yCount = yCount + 1;
        if y>-4*abs(x)^3/27
            uDiet(xCount,yCount) = u(xCount,yCount);
        else
            uDiet(xCount,yCount)=NaN;
        end
    end
end

T=toc;
fprintf('\n Time = %f\n',T);
surf(X,Y,abs(uDiet).');
xlabel('x');
ylabel('y');
view([0 90]); colorbar; shading interp;