function passTest = PearceyPig(Npts)

    %clear classes; %clear all variables
    
    disp('Testing against N.P. Kirk et al. approximations of Pearcey integral');
    
    if nargin == 0
        Npts = 20;
    end

    X=[-8 -6 -4 -2 0 2 4 6 8]; Y=[0 2 4 6 8];

    %get endpoints
    valleys = exp(2i*pi*(1/4 + (1:4))/4);
    a=valleys(2); b=valleys(4);

    freq=1;

    xCount=0;
    for x=X
        xCount=xCount+1;
        fprintf('x=%d\n',x);
        yCount=0;   
        for y=Y
            yCount=yCount+1;
            fprintf('\ty=%d ',y);
            polyCoeffs = [1 0 x y 0];
            [~,W]=PathFinderQuad(a, b, polyCoeffs, freq, Npts, 'infContour', [true true]);
            I_GHH=sum(W); %Gibbs-Hewett-Huybrechs estimate
            I_CHK=KirkPearceyData(x,y); %Conor-Hobbs-Kirk estimate
            err(xCount,yCount)=abs(I_CHK-I_GHH)/abs(I_CHK);
            fprintf('\tabs err=%e\n',err(xCount,yCount));
        end
    end
    maxErr = max(max(err));
    if maxErr < 2e-5
        passTest = true;
    else
        passTest = false;
    end
end

function I = KirkPearceyData(x,y)
%values taken from N.P. Kirk et al. p159 approximations of Pearcey integral
    XY=[-8.0 0.0 
    -6.0 0.0 
    -4.0 0.0 
    -2.0 0.0
    0.0 0.0 
    2.0 0.0 
    4.0 0.0 
    6.0 0.0 
    8.0 0.0
    -8.0 2.0 
    -6.0 2.0 
    -4.0 2.0 
    -2.0 2.0
    0.0 2.0 
    2.0 2.0 
    4.0 2.0 
    6.0 2.0 
    8.0 2.0
    -8.0 4.0 
    -6.0 4.0
    -4.0 4.0
    -2.0 4.0
    0.0 4.0 
    2.0 4.0 
    4.0 4.0 
    6.0 4.0 
    8.0 4.0
    -8.0 6.0
    -6.0 6.0 
    -4.0 6.0
    -2.0 6.0
    0.0 6.0 
    2.0 6.0 
    4.0 6.0 
    6.0 6.0 
    8.0 6.0
    -8.0 8.0
    -6.0 8.0
    -4.0 8.0
    -2.0 8.0
    0.0 8.0 
    2.0 8.0 
    4.0 8.0 
    6.0 8.0 
    8.0 8.0];
    RealBits=[-0.33744 0.15928 -0.64756 2.38566 1.67481 0.92403 0.64698 0.52085 0.44792 1.00422 0.96527 1.96341 0.35455 1.12475 0.99372 0.74010 0.58773 0.49582 0.75372 0.29478 0.14360 0.08086 -0.38592 0.59648 0.76660 0.68391 0.58882 -0.12839 1.17888 0.04838 0.02399 -0.23537 -0.47683 0.22551 0.51590 0.56595 1.06930 -1.10157 -0.49013 -0.18003 0.51018 -0.30892 -0.56703 -0.09657 0.22986];
    ImagBits=[-0.87636 -1.48342 -0.60962 -1.08551 0.69373 0.72901 0.59370 0.50005 0.43762 -0.11480 0.46413 -0.73419 -0.05184 -0.17608 0.31273 0.41332 0.40353 0.37668 -0.23933 -0.84373 0.90244 0.89242 -0.54514 -0.56516 -0.13266 0.08129 0.16933 0.34848 1.08442 0.24046 -0.53796 0.59203 -0.50921 -0.66816 -0.40573 -0.19254 0.22585 0.58229 0.02199 0.46915 -0.26097 0.54515 -0.30814 -0.61455 -0.53241];

    [~, XYindex]=ismember([x y], XY, 'rows');
    if XYindex==0
        error(['Value not found in Kirk Pearcey data, ',...
            'Must be x in {-8,-6,-4,-2,0,2,4,6,8}, y in {0,2,4,6,8}']);
    end
    I=RealBits(XYindex)+1i*ImagBits(XYindex);

end