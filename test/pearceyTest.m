function maxErr = pearceyTest(numQuadPts, outputText)
    if nargin == 1
        outputText = false;
    end

    %clear classes; %clear all variables
    if outputText
        disp('Testing against N.P. Kirk et al. approximations of Pearcey integral');
    end
    
    if nargin == 0
        numQuadPts = 20;
    end

    % get the horizontal and vertical coordintes
    xArray = [-8 -6 -4 -2 0 2 4 6 8];
    yArray = [0 2 4 6 8];

    %get endpoints
    valleys = 2*pi*(1/4 + (1:4))/4;
    a = valleys(2);
    b = valleys(4);

    % frequency parameter can be considered to be one here
    freq = 1;

    % preallocate errors matrix
    err = zeros(length(xArray),length(yArray));

    xCount = 0;
    for x = xArray
        xCount = xCount+1;
        if outputText
            fprintf('x=%d\n', x);
        end
        yCount = 0;   
        for y = yArray
            yCount = yCount+1;
            if outputText
                fprintf('\ty=%d ',y);
            end

            % polynomial coefficients depend on (x,y)
            polyCoeffs = [1 0 x y 0];

            % get PathFinder estimate
            I_GHH = PathFinder(a, b, [], polyCoeffs, freq, numQuadPts,...
                                'infcontour', [true true]);

            % get Conor-Hobbs-Kirk estimate
            I_CHK=KirkPearceyData(x,y);

            % record relative error
            err(xCount,yCount) = abs(I_CHK-I_GHH)/abs(I_CHK);

            if outputText
                fprintf('\trel err=%e\n', err(xCount,yCount));
            end
        end
    end
    maxErr = max(max(err));
end

function I = KirkPearceyData(x,y)
%values taken from N.P. Kirk et al. p159 approximations of Pearcey
%integral. Hard-coded.

    xyVals=[-8.0 0.0 
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

    realVals = [-0.33744 0.15928 -0.64756 2.38566 1.67481 0.92403 0.64698 ...
                0.52085 0.44792 1.00422 0.96527 1.96341 0.35455 1.12475 ...
                0.99372 0.74010 0.58773 0.49582 0.75372 0.29478 0.14360 ...
                0.08086 -0.38592 0.59648 0.76660 0.68391 0.58882 -0.12839 ...
                1.17888 0.04838 0.02399 -0.23537 -0.47683 0.22551 0.51590 ...
                0.56595 1.06930 -1.10157 -0.49013 -0.18003 0.51018 -0.30892 ...
                -0.56703 -0.09657 0.22986];

    imagVals = [-0.87636 -1.48342 -0.60962 -1.08551 0.69373 0.72901 0.59370 ...
                0.50005 0.43762 -0.11480 0.46413 -0.73419 -0.05184 -0.17608 ...
                0.31273 0.41332 0.40353 0.37668 -0.23933 -0.84373 0.90244 ...
                0.89242 -0.54514 -0.56516 -0.13266 0.08129 0.16933 0.34848 ...
                1.08442 0.24046 -0.53796 0.59203 -0.50921 -0.66816 -0.40573 ...
                -0.19254 0.22585 0.58229 0.02199 0.46915 -0.26097 0.54515 ...
                -0.30814 -0.61455 -0.53241];

    % find the hard-coded estimate, given (x,y)
    [~, xyIndex] = ismember([x y], xyVals, 'rows');

    if xyIndex==0
        error(['Value not found in Kirk Pearcey data, ',...
            'Must be x in {-8,-6,-4,-2,0,2,4,6,8}, y in {0,2,4,6,8}']);
    end

    % get estimate of integral by combining real and imag part
    I = realVals(xyIndex)+1i*imagVals(xyIndex);

end