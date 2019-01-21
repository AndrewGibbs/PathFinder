classdef ContourSD < handle
    %Steepest descent contour object
    
    properties
        startPoint
        endPoint
        startCoverIndex
        endCoverIndex = []
        coarsePath
        coarsePathGrad
        length
        endValley %may be unpopulated if finite length
        paramOrder
        phaseDerivs
        %some parameters with default settings:
        coarseTol = 1e-3;
        fineTol = 1e-13;
        paramPathLength = 100000;
        minArgDist = pi;
        ICs %intiial conditions
        %quad bits:
        P0
        h
        dhdp
        Wgauss
    end
    
    methods
        function self = ContourSD(startPoint,paramOrder,phaseDerivs,startCover,otherCovers,valleys)
            %construct an instance of this class
            self.startPoint = startPoint;
            self.paramOrder = paramOrder;
            self.phaseDerivs = phaseDerivs;
            self.startCoverIndex = startCover.index;
            
            self.ICs = [startPoint; zeros(paramOrder-1,1)];
            %solve ODE to approximate contour
            [p,H] = ode45(@(t,y) NSDpathODE(t,y,self.paramOrder-1,phaseDerivs, self.ICs, false, 0), [0 self.paramPathLength], self.ICs, odeset('RelTol', self.coarseTol) );
            self.coarsePath = H(:,1);
            self.coarsePathGrad = 1i/phaseDerivs{2}(self.coarsePath);
            %check if path isin any of the covers, truncate it if it is
            
            contourInCover = zeros(size(self.coarsePath));
            contourNaNcover = zeros(size(self.coarsePath));
            
            for cover = otherCovers
                contourInCover_yn = zeros(size(self.coarsePath));
                contourInCover_yn = contourInCover_yn + cover.isIn(self.coarsePath);
                contourInCover = contourInCover + contourInCover_yn.*cover.index;
                contourNaNcover = contourNaNcover + isnan(self.coarsePath);
                %NaNs are typically a sign of passing through another
                %stationary point, although this should only happen if
                %inside another ComplexCover anyway
            end
            contourEndIndex = min([find(contourInCover,true),find(contourNaNcover,1)]);
            
            if isempty(contourEndIndex) %infinite contour
                self.length = inf;
                [endValleyArgDist, endValleyIndex] = min(abs( angle(self.coarsePath(end)) - angle(valleys)));
                [endValleyArgDistGrad, endValleyIndexGrad] = min(abs( angle(self.coarsePathGrad(end)) - angle(valleys)));
                if endValleyArgDistGrad < self.minArgDist/length(valleys)
                    self.endValley = valleys(endValleyIndexGrad);
                elseif endValleyArgDist < self.minArgDist/length(valleys) %second choice if the first fails...
                    self.endValley = valleys(endValleyIndex);
                else
                    error('too far from a valley...');
                    self.endValley = [];
                end
            else    %finite contour
                self.endCoverIndex = contourInCover(contourEndIndex); %the cover which the contour hits
                contourEndIndex = max(contourEndIndex-1,1); %take one off, to be sure of ending before it hits
                self.length = p(contourEndIndex);
                self.coarsePath = self.coarsePath(1:contourEndIndex);
                self.endValley = [];
                self.endPoint = self.coarsePath(contourEndIndex);
            end
        end
        
        function plot(self)
            plot(self.coarsePath);
        end
        
        function [Z, W] = getQuad(self,freq,Npts)
            if isinf(self.length)
                %get relevant weighted Gauss quad rule:
                [p, self.Wgauss] = quad_gauss_exp(self.paramOrder, Npts);
                %scale by frequency and add zero
                self.P0=[0; (p/(freq^(1/self.paramOrder)))];
            else
                [p, self.Wgauss] = gauss_quad(0,self.length,Npts);
                self.P0=[0; flipud(p)];
            end
            [~,H] = ode45(@(t,y) NSDpathODE(t,y,self.paramOrder-1,self.phaseDerivs, self.ICs, false, 0),...
                    self.P0, self.ICs, odeset('RelTol', self.fineTol) );
            self.h = H(2:end,1);
            self.dhdp = 1i./self.phaseDerivs{2}(self.h);
            %this adjusts for small deviations from the path:
            weightWatchers = exp(1i*freq*(self.phaseDerivs{1}(self.h)-1i*self.P0(2:end).^self.paramOrder - self.phaseDerivs{1}(self.startPoint)));
            if isinf(self.length)
                %absorb h'(p) and other constants into weights.
                W= (1/(freq^(1/self.paramOrder)))*exp(1i*freq*self.phaseDerivs{1}(self.startPoint))...
                    .*self.dhdp.*self.Wgauss.*weightWatchers;
            else
               W = self.dhdp.*self.Wgauss.*exp(1i*freq*self.phaseDerivs{1}(self.h)) ;
            end
            %sum(W.*self.dhdp)
            Z=self.h; 
        end
         
        function [Z, W] = reuseQuad(self, g)
            if isinf(self.length)
                weightWatchers = exp(1i*freq*(g(self.h)-1i*self.P0(2:end).^self.paramOrder - g(self.startPoint)));
                %absorb h'(p) and other constants into weights.
                W= (1/(freq^(1/self.paramOrder)))*exp(1i*freq*g(self.startPoint))...
                    .*self.dhdp.*self.Wgauss.*weightWatchers;
            else
                W = self.Wgauss.*exp(1i*freq*g(self.h)) ;
            end
            Z=self.h; 
        end
    end
end

