% R_LAGUERRE Recurrence coefficients for monic generalized 
% Laguerre polynomials.
%
%    ab=R_LAGUERRE(n,a) generates the first n recurrence
%    coefficients for the monic generalized Laguerre polynomials 
%    with parameter a. These are orthogonal on [0,Inf] relative 
%    to the weight function w(t)=t^a exp(-t). The n alpha- 
%    coefficients are stored in the first column, the n beta-
%    coefficients in the second column, of the nx2 array ab. The
%    call ab=R_LAGUERRE(n) is the same as ab=R_LAGUERRE(n,0).
%
%    Supplied by Dirk Laurie, 6-22-1998; edited by Walter
%    Gautschi, 4-4-2002.
%
function ab=r_laguerre(N,a)
if nargin<2, a=0; end
if((N<=0)|(a<=-1)) error('parameter(s) out of range'), end
nu=a+1; mu=gamma(a+1);
if N==1, ab=[nu mu]; return, end
N=N-1; n=1:N; na=2*n+a+1; nb=n.*(n+a);
A=[nu na]; B=[mu nb];
ab=[A' B'];
