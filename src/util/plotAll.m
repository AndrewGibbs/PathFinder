function plotAll(covers, contours, z, a, b, infContour, SPs)

    marginSpace = 0.5;
    
    %get your margins:
    min_x = 0; min_y = 0; max_x = 0; max_y = 0;

    if infContour(1)
        a = [];
    end
    if infContour(2)
        b = [];
    end
    
    for x = [a b SPs z.']
        max_x = max(real(x),max_x);
        max_y = max(imag(x),max_y);
        min_x = min(real(x),min_x);
        min_y = min(imag(x),min_y);
    end

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
    plot(z,'x');
    
    %now adjust the margins a bit
    xlim([min_x-marginSpace max_x+marginSpace]);
    ylim([min_y-marginSpace max_y+marginSpace]);
    
    hold off;
    
end
