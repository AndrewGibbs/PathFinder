
name = 'gausLegHC';
FID = fopen(strcat(name,'.m'),'w');
N = 100;
ab = r_jacobi(N, 0, 0);
[x,w] = compute_gauss(N, ab(:,1), ab(:,2));

fprintf(FID,'function [x,w] = %s(n)\n',name);

fprintf(FID,'switch n\n');

for n=1:N
    fprintf(FID,'case %d\n',n);
    [x,w] = compute_gauss(n, ab(:,1), ab(:,2));
    fprintf(FID,'\tx = [');
    for m = 1:length(x)
        fprintf(FID,'%.16f ',x(m));
    end
    fprintf(FID,"].';\n");
    fprintf(FID,'\tw = [');
    for m = 1:length(x)
        fprintf(FID,'%.16f ',w(m));
    end
    fprintf(FID,"].';\n");
end
fprintf(FID,'otherwise\n');
fprintf(FID,'ab = r_jacobi(n, 0, 0);\n');
fprintf(FID,'[x,w] = compute_gauss(n, ab(:,1), ab(:,2));\n');
fprintf(FID,'end');