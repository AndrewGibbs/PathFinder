% produces a visual representation of the planar PathFinder graph

function plotGraph(graphData, ballsArray, finiteEndpoints)

    %% First set formats
    % use LaTeX fonts
    set(0,'defaultTextInterpreter','latex');
    fontSize = 18;
    markerSize = 35;
    thickWidth = 3.0;

    % determine where the graph should be centred, and the size needed to
    % contain all of the balls
    rStretch = 1.25;
    centre = mean(graphData.CPs);
    r = rStretch*max(abs(centre - graphData.CPs));

    % the colours for the different nodal components
    cols = {[0 0.4470 0.7410],[0.8500 0.3250 0.0980],[0.9290 0.6940 0.1250],...
        [0.4940 0.1840 0.5560], [0.4660 0.6740 0.1880], [0.3010 0.7450 0.9330],...
                [0.6350 0.0780 0.1840]};

    % colour for the balls
    lightGrayColor = [.8 .8 .8];


    %% Fill balls in first, so everything else gets drawn on top.
    for iBall = ballsArray
        % convert cell to correct cell format
        if iscell(iBall)
            iBall=iBall{1};
        end

        % only fill balls with positive radius
        if iBall.radius>0
           fillCircle(iBall.centre, iBall.radius, lightGrayColor);
           hold on;
        end
    end
    
    %% Next, plot the edges.
    % double loop over all nodes on graph:
    for n = 1:length(graphData.points)
        for m=1:length(graphData.points)
            % check if these nodes are connected
             if graphData.adj_mat(m,n)
                if isOnShortestPath(m,n)
                    % if they correspond to the deformation, use a thick
                    % line
                    drawThickLine(graphData.points(m), graphData.points(n));
                else
                    % otherwise, use a regular line
                    drawLine(graphData.points(m), graphData.points(n));
                end
             end
        end
    end

    %% Now plot the nodes.

    % create finite nodal points for the valleys.
    valleyNodes = centre + r*graphData.valleys;

    % double loop over all nodes and all valleys on graph
    for n = 1:length(graphData.points)
        for m_ = 1:length(graphData.valleys)
            % shift to the valley index range, which is after the 'points'
            m = m_ + length(graphData.points);

            % check if point connects to valley
            if graphData.adj_mat(m, n)
                % if they correspond to the deformation, use a thick
                % line
                if isOnShortestPath(m, n)
                    drawThickLine(graphData.points(n), valleyNodes(m_));
                else
                % otherwise, use a regular line
                    drawLine(graphData.points(n), valleyNodes(m_));
                end
            end
        end
    end
    
    %% Add nodes to the graph
    % mark finite points representing valleys
    plot(valleyNodes,'.k','MarkerSize',markerSize, 'Color',cols{1});

    % mark exits
    plot(graphData.SExs,'.b','MarkerSize',markerSize, 'Color',cols{4});
    % mark entrances
    plot(graphData.SEns,'.g','MarkerSize',markerSize, 'Color',cols{5});
    % mark critical points
    plot(graphData.CPs,'.r','MarkerSize',markerSize,'Color', cols{2});

    %% Workaround to get Matlab to plot the legend
    legend('','Location', 'eastoutside');
    plot(NaN,NaN,'.k','MarkerSize',markerSize,'DisplayName','Valleys','Color', cols{1});
    plot(NaN,NaN,'.r','MarkerSize',markerSize,'DisplayName','Stationary points','Color', cols{2});
    if length(finiteEndpoints)>1
        plot(finiteEndpoints,'.m','MarkerSize',markerSize,'DisplayName','Finite endpoints','Color', cols{3});
    end
    plot(NaN,NaN,'.b','MarkerSize',markerSize,'DisplayName','Exits','Color', cols{4});
    plot(NaN,NaN,'.g','MarkerSize',markerSize,'DisplayName','Entrances','Color', cols{5});
    plot(NaN,NaN,'-k','DisplayName','Edges')
    plot(NaN,NaN,'-k','LineWidth',thickWidth,'DisplayName','Edges in shortest path')

    %% Some final formatting
    % stretch axis limits by a little
    xlim(1.1*[min(real(valleyNodes)) max(real(valleyNodes))]);
    ylim(1.1*[min(imag(valleyNodes)) max(imag(valleyNodes))]);

    set(gca,'fontsize', fontSize);
    set(gcf, 'Position', [0 0 800 800]);
    axis equal;
    axis off;
    hold off;

    %% indented functions

    function drawLine(a,b)
        hold on;
        plot([a b]+1i*eps,'-k');
    end

    function drawThickLine(a,b)
        hold on;
        plot([a b]+1i*eps,'-k','LineWidth',thickWidth);
    end
    
    function yn = isOnShortestPath(m,n)
        % returns true of false, if nodal indices m and n are on the shortest
        % path, corresponding to the contour deformation
        yn = false;
        % loop over all indices in shortest path sequence
        for j=1:(length(graphData.shortest_path)-1)
            % check if m and n are neighbours in sequence
            if (m==graphData.shortest_path(j) && n==graphData.shortest_path(j+1))...
               || (n==graphData.shortest_path(j) && m==graphData.shortest_path(j+1))
               yn = true;
               break;
            end
        end
    end
end