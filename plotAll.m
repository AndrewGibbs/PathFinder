function plotAll(covers,contours)
%plots all contours and covers
    for C=covers
        if iscell(C)
            C=C{1};
        end
        plot(C);
        hold on;
    end
    for C=contours
        plot(C);
        hold on;
    end
    hold off;
end
