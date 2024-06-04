function plotAll(balls, contours, quadPoints, a, b, infContour, stationaryPoints, polyCoeffs, valleys)

    %% Formatting
    % use LaTeX fonts
    set(0,'defaultTextInterpreter','latex');
    fontSize = 18;
    
    % choose a shade of grey for the balls
    grayColor = [.1 .1 .1];
    lightGrayColor = [.85 .85 .85];

    % determine the space required around the edges
    marginSpace = 0.5;
    for S = balls
       marginSpace = max(marginSpace,S{1}.radius);
    end
    
    % initialise axis limits
    minX = 0;
    minY = 0;
    maxX = 0;
    maxY = 0;

    % delete endpoint data if they are infinite and cannot be plotted
    if infContour(1)
        a = [];
    end
    if infContour(2)
        b = [];
    end
    
    % make sure all of these points are included in the plot:
    for x = [a b stationaryPoints quadPoints.']
        maxX = max(real(x), maxX);
        maxY = max(imag(x), maxY);
        minX = min(real(x), minX);
        minY = min(imag(x), minY);
    end

    %% plot all balls and contours

    % loop over all balls
    for iBall = balls
        if iscell(iBall)
            iBall = iBall{1};
        end

        % draw grey circle for balls with positive radii
        if iBall.radius > 0
           fillCircle(iBall.centre, iBall.radius, lightGrayColor);
           hold on;
        end
    end

    % loop over all contours and plot
    for iContour = 1:length(contours)
        plot(contours(iContour), '.:', 'Color', grayColor, 'MarkerSize', 4.5);
        hold on;
    end
    
    %% plot no return regions
    theta = linspace(0, 2*pi, 100);
    R = zeros(length(theta), 1);
    order = length(polyCoeffs)-1;
    smidgin = 1/1000;

    % loop over all valleys
    for v = angle(valleys)
        % get angular region around valley
        theta = linspace(v - pi/(2*order) + smidgin, ...
                            v + pi/(2*order) - smidgin);
        for n=1:length(theta)
            % get distance from each point theta to the valley
            thetaDiff = min(abs([theta(n) - v ...
                                    theta(n)-v-2*pi ...
                                    theta(n)-v+2*pi]));
            % get the radius of the segment for each angle theta
            R(n) = getRStar(polyCoeffs, thetaDiff);
        end
        % create the boundary of this segment of the no return region
        eventHorizon = fliplr(exp(1i*theta).*R');

        % now stretch this region way larger than the plot will be, so it
        % appears to go on forever, and plot
        bigArc = 15*(max(maxX - minX, maxY - minY) ...
                    +2*marginSpace)*exp(1i*theta);
        X = [real(bigArc) real(eventHorizon)];
        Y = [imag(bigArc) imag(eventHorizon)];
        fill(X, Y, 'k', 'EdgeColor', 'k', 'FaceAlpha', 0.1, 'EdgeAlpha', 0.0);
        hold on;
    end

    %% Plot some of the key points

    % mark the quadrature points in red
    plot(quadPoints + eps*1i, 'r.', 'MarkerSize', 6.5);
    hold on;

    % mark stationary points in black:
    plot(stationaryPoints+eps*1i, 'k*');
    
    %% Final formatting adjustments

    % adjust the margins a bit
    axis equal;
    xlim([minX-marginSpace maxX+marginSpace]);
    ylim([minY-marginSpace maxY+marginSpace]);
    
    xlabel('Real');
    ylabel('Imaginary');
    set(gca,'fontsize', fontSize);
    set(gcf, 'Position', [0 0 800 800]);

    % if symbolic toolbox is installed, add the phase to the title
    if checkForPackage('Symbolic Math Toolbox')
        title(['$g(x)=',latex(poly2sym(polyCoeffs)),'$'],'Interpreter','latex');
    end
    hold off;
    
end
