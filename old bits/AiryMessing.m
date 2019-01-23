%doing some experiments with Dave's paper

A0=@(z) airy(z);
A1=@(z) exp(2i*pi/3)*airy(exp(2i*pi/3)*z);
A2=@(z) exp(-2i*pi/3)*airy(exp(-2i*pi/3)*z);


R=linspace(-1,1,1000);
figure(1);
plot(R,A0(R)./A1(R));
figure(2);
plot(R,abs(exp(exp(-1i*pi/6)*R)./(A0(R).^2)));

