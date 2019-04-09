% R_HERMITE Recurrence coefficients for monic generalized Hermite 
% polynomials.
%
%    ab=R_HERMITE(n,mu) generates the first n recurrence 
%    coefficients for the monic generalized Hermite polynomials 
%    with parameter mu. These are orthogonal on [-Inf,Inf] 
%    relative to the weight function w(t)=|t|^{2 mu} exp(-t^2).
%    The n alpha-coefficients are stored in the first column, the
%    n beta-coefficients in the second column, of the nx2 array
%    ab. The call ab=R_HERMITE(n) is the same as R_HERMITE(n,0).
%
%    Supplied by Dirk Laurie, 6-22-1998; edited by Walter
%    Gautschi, 4-4-2002
%
function ab=r_hermite(N,mu)
if nargin<2, mu=0; end
if N<=0|mu<=-1/2, error('parameter(s) out of range'), end
m0=gamma(mu+1/2);
if N==1, ab=[0 m0]; return, end
N=N-1; n=1:N; nh=.5*n; nh(1:2:N)=nh(1:2:N)+mu;
A=zeros(1,N+1); B=[m0 nh];
ab=[A' B'];
