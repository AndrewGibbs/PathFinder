function plotAll(covers,contours)
%plots all contours and covers
    for C=covers
        plot(C);
        hold on;
    end
    for C=contours
        plot(C);
        hold on;
    end
    hold off;
end

