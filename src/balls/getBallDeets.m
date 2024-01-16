function [cover_centres, cover_radii, SPs, SPs_radii] = getBallDeets(otherCovers)
    L=length(otherCovers);
    cover_centres = zeros(L,1);
    cover_radii = zeros(L,1);
    for n=1:L
        cover_radii(n) = otherCovers{n}.radius;
        cover_centres(n) = otherCovers{n}.centre;
    end
    SPs = cover_centres(cover_radii>0);
    SPs_radii = cover_radii(cover_radii>0);
%     [cover_centres, cover_radii] = getBallDeets(startCover, otherCovers)
%     L=length(otherCovers);
%     cover_centres = zeros(L+1,1);
%     cover_radii = zeros(L+1,1);
%     cover_radii(1) = 0.99*startCover.radius;
%     cover_centres(1) = startCover.centre;
%     for n=2:(L+1)
%         cover_radii(n) = otherCovers{n-1}.radius;
%         cover_centres(n) = otherCovers{n-1}.centre;
%     end
end