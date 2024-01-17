% a script to produce the 'hard-coded' Gauss Legendre (function) file.
% Matlab code which creates Matlab code.

% change to the quadrature directory to save function file here
cd(fileparts(which('hardCodeQuadratureGauleg')));

% name of function file to be created
name = 'gausLegHC';
% create file with this name, and open it
FID = fopen(strcat(name,'.m'),'w');

% max number of hard-coded values to go inside function file
maxNumHardCodedPts = 100;
ab = rJacobi(maxNumHardCodedPts, 0, 0);
[x,w] = computeGauss(maxNumHardCodedPts, ab(:,1), ab(:,2));

% write some comments explaining the function
fprintf(FID, "%% Hard-coded values of Gauss Legendre quadrature.\n\n");

% write function heading in function file
fprintf(FID,'function [x,w] = %s(n)\n',name);

% write start of switch statement
fprintf(FID,'\n\tswitch n\n\n');

% now loop over different quadrature orders, hard-coding the outputs into
% the new file
for numGaussPts=1:maxNumHardCodedPts
    fprintf(FID,'\tcase %d\n',numGaussPts);

    % actually get the weights and nodes
    [x,w] = computeGauss(numGaussPts, ab(:,1), ab(:,2));

    % now hard-code them
    fprintf(FID,'\t\tx = [');
    for m = 1:length(x)
        fprintf(FID,'%.16f ',x(m));
    end
    fprintf(FID,"].';\n");
    fprintf(FID,'\t\tw = [');
    for m = 1:length(x)
        fprintf(FID,'%.16f ',w(m));
    end
    fprintf(FID,"].';\n");
end

% address the case where the user asks for too many points, more than have
% been hard-coded. The below will write code which computes these using the
% same algorithm as above, Golub-Welsch etc.
fprintf(FID,'\totherwise\n');
fprintf(FID,'\t\tab = rJacobi(n, 0, 0);\n');
fprintf(FID,'\t\t[x,w] = computeGauss(n, ab(:,1), ab(:,2));\n');
fprintf(FID,'\tend\n');
fprintf(FID,'end');