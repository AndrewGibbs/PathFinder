function plotAll(covers,contours)
%plots all contours and covers
    hold on;
    for C=covers
        plot(C);
    end
    for C=contours
        plot(C);
    end
    hold off;
end

