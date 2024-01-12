function plotContours(contours,CPs,quadIngredients)

    for C=contours
        plot(C);
        hold on;
    end

    % now highlight used contours
    for n=1:length(quadIngredients)
        if strcmp(quadIngredients{n}.type,'infSD')
            plot(quadIngredients{n}.contour,'k',2);
            hold on;
        end
    end
    
    %plot stationary points:
    plot(CPs+eps*1i,'k.','MarkerSize',30);
    
    %now adjust the margins a bit
%     xlim([min_x-marginSpace max_x+marginSpace]);
%     ylim([min_y-marginSpace max_y+marginSpace]);
%     
%     xlabel('Real');
%     ylabel('Imaginary');
%     set(gca,'fontsize', fontSize)
    
    hold off;
    
end
