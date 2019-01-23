
Npts=30;
h=.1;
visuals = false;
a=exp(1i*9*pi/10);
b=1i;
X=-10:h:10;
Y=-10:h:10;
% -----------------------------------
A31 = @(x,y) A(x,y,a,b,Npts,visuals);

tic;
xCount = 0;
u=zeros(length(X),length(Y));
parfor xCount = 1:length(X)
    for yCount = 1: length(Y)
        U{xCount}(yCount)= A31(x,y);
    end
end

%now piece it together:
for xCount = 1:length(X)
    u(xCount,:)=U{xCount};
end

T=toc;
fprintf('\n Time = %f\n',T);
surf(X,Y,abs(u).');
view([0 90]); colorbar; %shading interp;