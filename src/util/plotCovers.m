function plotCovers(covers)
    %plots all contours and covers
    for C=covers
        if iscell(C)
            C=C{1};
        end
        plot(C);
        if C.radius>0
           fillCircle(C.centre,C.radius);
        end
        hold on;
    end
    
end
