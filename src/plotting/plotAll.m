function plotAll(covers, contours, z, a, b, infContour, SPs,HermiteInds, g_coeffs,V)

    set(0,'defaultTextInterpreter','latex');
%     f = figure();
    if nargin == 7
        HermiteInds = [];
    end
    fontSize = 18;
    %get your margins:
    marginSpace = 0.5;
    
    lightGrayColor = [.85 .85 .85];
    for S = covers
       marginSpace = max(marginSpace,S{1}.radius);
    end
    
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
%         plot(C);
        if C.radius>0 && ~ismember(C.index,HermiteInds)
           fillCircle(C.centre,C.radius,lightGrayColor);
           % plot(C.steepestExits,'ob','MarkerSize',18);
        end
        hold on;
    end
    grayColor = [.1 .1 .1];
    for count = 1:length(contours)
        C=contours(count);
        plot(C,'.:','Color',grayColor,'MarkerSize',4.5);
        hold on;
    end

    % now highlight used contours
%     for C=contours
%         plot(C);
%         hold on;
%     end
    
    % now plot no return regions
    theta = linspace(0,2*pi,100);
    grayColor = [.6 .6 .6];
    %plot(exp(1i*theta).*plot_no_return(theta,g_coeffs),'Color',grayColor,'LineWidth',2);
    R = zeros(length(theta),1);
    order = length(g_coeffs)-1;
    smidgin = 1/1000;
    min_R = inf;
    for v = angle(V)
        theta = linspace(v-pi/(2*order)+smidgin,v+pi/(2*order)-smidgin);
        for n=1:length(theta)
%         [~,v_index] = min(abs(exp(1i*angle(V))-exp(1i*theta(n))));
%         v = mod(angle(V(v_index)),2*pi);
        theta_diff = min(abs([theta(n)-v, theta(n)-v-2*pi theta(n)-v+2*pi]));
%         if theta_diff < pi/(2*order)
         R(n) = getRStar(g_coeffs,theta_diff);
%         else
%             R(n) = inf;
%         end
        end
         event_horizon = fliplr(exp(1i*theta).*R');
        big_arc = 15*(max(max_x-min_x,max_y-min_y)+2*marginSpace)*exp(1i*theta);
        X = [real(big_arc) real(event_horizon)];
        Y = [imag(big_arc) imag(event_horizon)];
        fill(X,Y,'k','EdgeColor','k','FaceAlpha',0.1,'EdgeAlpha',0.0);
        min_R = min(R);
    end
   
%     plot(exp(1i*theta).*R','Color',grayColor,'LineWidth',2);


    plot(z+eps*1i,'r.','MarkerSize',6.5);
    hold on;
    %plot stationary points:
    plot(SPs+eps*1i,'k*');
    
    %now adjust the margins a bit
    axis equal;
    xlim([min_x-marginSpace max_x+marginSpace]);
    ylim([min_y-marginSpace max_y+marginSpace]);
    
    xlabel('Real');
    ylabel('Imaginary');
    set(gca,'fontsize', fontSize);
    set(gcf, 'Position', [0 0 800 800]);
    if license('test','symbolic_toolbox')
        title(['$g(x)=',latex(poly2sym(g_coeffs)),'$'],'Interpreter','latex');
    end
    hold off;
    
end
