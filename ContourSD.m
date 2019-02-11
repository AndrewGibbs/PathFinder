classdef ContourSD < handle
    %Steepest descent contour object
    
    properties
        startPoint
        endPoint
        startCoverIndex
        endCoverIndex = []
        startClusterIndices
        endClusterIndices = []
        coarsePath
        coarsePathGrad
        length
        endValley %may be unpopulated if finite length
        paramOrder
        ODEorder = 1
        phaseDerivs
        %some parameters with default settings:
        coarseTol = 1e-3;
        fineTol = 1e-13;
        paramPathLength = 100000;
        minArgDist = pi;
        ICs %intiial conditions
        %quad bits:
        P0
        h = []
        dhdp
        Wgauss
        quadFreq
    end
    
    methods
        function self = ContourSD(startPoint,paramOrder,phaseDerivs,startCover,otherCovers,valleys,clusterIndices)
            %construct an instance of this class
            self.startPoint = startPoint;
            self.paramOrder = paramOrder;
            self.phaseDerivs = phaseDerivs;
            self.startCoverIndex = startCover.index;
            self.startClusterIndices = getClusterBuddies(clusterIndices, self.startCoverIndex);
            
            self.ICs = [startPoint; zeros(paramOrder-1,1)];
            %solve ODE to approximate contour
            %ODEorder = self.paramOrder;
            [p,H] = ode45(@(t,y) NSDpathODE(t,y,self.ODEorder-1,phaseDerivs, self.ICs, false, 0), [0 self.paramPathLength], self.ICs, odeset('RelTol', self.coarseTol) );
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
                self.endClusterIndices = getClusterBuddies(clusterIndices, self.endCoverIndex);
                %contourEndIndex = max(contourEndIndex-1,1); %take one off, to be sure of ending before it hits
                contourEndIndex = max(contourEndIndex,2);
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
%             if nargin <= 4
%                 G = self.phaseDerivs;
%             end
%             if isempty(self.h) %if quadrature hasn't been created already, then create it
            self.quadFreq = freq;
            if isinf(self.length)
                %get relevant weighted Gauss quad rule:
                [p, self.Wgauss] = quad_gauss_exp(self.ODEorder, Npts);
                %scale by frequency and add zero
                self.P0=[0; (p/(freq^(1/self.ODEorder)))];
            else
                [p, self.Wgauss] = gauss_quad(0,self.length,Npts);
                self.P0=[0; flipud(p)];
            end
            [~,H] = ode45(@(t,y) NSDpathODE(t,y,self.ODEorder-1,self.phaseDerivs, self.ICs, false, 0),...
                    self.P0, self.ICs, odeset('RelTol', self.fineTol) );
            self.h = H(2:end,1);
            self.dhdp = 1i./self.phaseDerivs{2}(self.h);
            %this adjusts for small deviations from the path:
            weightWatchers = exp(1i*freq*(self.phaseDerivs{1}(self.h)-1i*self.P0(2:end).^self.ODEorder - self.phaseDerivs{1}(self.startPoint)));
            if isinf(self.length)
                %absorb h'(p) and other constants into weights.
                W= (1/(freq^(1/self.ODEorder)))*exp(1i*freq*self.phaseDerivs{1}(self.startPoint))...
                    .*self.dhdp.*self.Wgauss.*weightWatchers;
            else
               W = self.dhdp.*self.Wgauss.*exp(1i*freq*self.phaseDerivs{1}(self.h)) ;
            end
            Z=self.h; 
%             else
%                 [Z, W] = self.reuseQuad(G, errThresh);
%             end
        end
         
        function [Z, W] = reuseQuad(self, G, errThresh)
            if nargin == 2
                errThresh = inf;
            end
            if ~isinf(errThresh) %tweak old SD path using Newton iteration
                Zold=self.h;
                p = self.P0(2:end);
                Z = NaN(size(Zold));
                dZdp = Z;
                for n = 1:length(Zold) %#ok<CPROPLC> %iterate over all quad points
                    [success, z_new] = NewtonSD(Zold(n),G,p(n),1,self.startPoint,errThresh);
                    if success
                        Z(n) = z_new;
                        dZdp(n) =  1i./G{2}(Z(n));
                    else
                        Z = Zold;
                        dZdp = self.dhdp;
                        warning('Failed to iterate to true SD path');
                        n = length(Zold) +1;
                        break;
                    end
                    clear z_new;
                end
            else
                Z = self.h;
                dZdp = self.dhdp;
            end
            g = G{1};
            if isinf(self.length)
                weightWatchers = exp(1i*self.quadFreq*(g(Z)-1i*self.P0(2:end).^self.ODEorder - g(self.startPoint)));
                %absorb h'(p) and other constants into weights.
                W = (1/(self.quadFreq^(1/self.ODEorder)))*exp(1i*self.quadFreq*g(self.startPoint))...
                    .*dZdp.*self.Wgauss.*weightWatchers;
            else
                W = dZdp.*self.Wgauss.*exp(1i*self.quadFreq*g(Z)) ;
            end
            
        end
    end
end

