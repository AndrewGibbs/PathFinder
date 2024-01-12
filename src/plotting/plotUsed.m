function plotUsed(covers, coverinds, contours,z)

   
    

    %plots all contours and covers
    for cind = coverinds%C=covers
        C = covers{cind};
        if iscell(C)
            C=C{1};
        end
        plot(C);
        if C.radius>0
            fillCircle(C.centre,C.radius);
           % plot(C.steepestExits,'ob','MarkerSize',18);
        end
        hold on;
    end
    for C=contours
        plot(C);
        hold on;
    end
plot(z+eps*1i,'r.','MarkerSize',10);
    
    %plot stationary points:
%     plot(SPs+eps*1i,'r*','MarkerSize',fontSize);
    
    %now adjust the margins a bit
%     xlim([min_x-marginSpace max_x+marginSpace]);
%     ylim([min_y-marginSpace max_y+marginSpace]);
%     
%     xlabel('Real');
%     ylabel('Imaginary');
%     set(gca,'fontsize', fontSize)
    
    hold off;
    
end
