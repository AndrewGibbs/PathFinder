classdef ContourSD < handle
    %Steepest descent contour object
    
    properties
        startPoint
        endPoint
        startCoverIndex
        endCoverIndex = []
        startClusterIndices
        endClusterIndices = []
        intervalEndpoint = []
        endClusterIntervalEndpoints = []
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
        function self = ContourSD(startPoint,phaseDerivs,startCover,otherCovers,valleys,clusterIndices,clusterEndpoints)
            %construct an instance of this class
            self.startPoint = startPoint;
            self.paramOrder = startCover.orderSum;
            self.phaseDerivs = phaseDerivs;
            self.startCoverIndex = startCover.index;
            [self.startClusterIndices, self.intervalEndpoint] = getClusterBuddies(clusterIndices, self.startCoverIndex, clusterEndpoints);
            
            self.ICs = [startPoint; 1i/phaseDerivs{2}(startPoint)];
            %solve ODE to approximate contour
            %ODEorder = self.paramOrder;
%             [p,H] = ode45(@(t,y) NSDpathODE(t,y,self.ODEorder-1,phaseDerivs, self.ICs, false, 0), [0 self.paramPathLength], self.ICs, odeset('RelTol', self.coarseTol) );
%             self.coarsePath = H(:,1);
%             self.coarsePathGrad = 1i/phaseDerivs{2}(self.coarsePath);
            
            %new streamlined version of ODE solver, much simpler than orig
            %PathFinder:
            [p, self.coarsePath, self.coarsePathGrad] = SDpathODE(self.paramPathLength, phaseDerivs{2}, 1, self.ICs(1), self.coarseTol);
            
            %add the first p=0 to the above, just incase we stray
            %immediately into a NaN:
            p = [0; p];
            self.coarsePath = [self.ICs(1); self.coarsePath];
            self.coarsePathGrad = [self.ICs(2); self.coarsePathGrad];
            
            %check if path isin any of the covers, truncate it if it is
            
            contourInCover = zeros(size(self.coarsePath));
            contourNaNcover = zeros(size(self.coarsePath));
            
            for cover = otherCovers
                if iscell(cover)
                    cover = cover{1};
                end
                contourInCover_yn = zeros(size(self.coarsePath));
                contourInCover_yn = contourInCover_yn + cover.isIn(self.coarsePath);
                contourInCover = max( contourInCover , contourInCover_yn.*cover.index);
                contourNaNcover = max( contourNaNcover , isnan(self.coarsePath) );
                %NaNs are typically a sign of passing through another
                %stationary point, although this will only happen if
                %inside another ComplexCover anyway
            end
            contourEndIndex = min([find(contourInCover,true),find(contourNaNcover,true)]);
            
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
                [self.endClusterIndices, self.endClusterIntervalEndpoints] = getClusterBuddies(clusterIndices, self.endCoverIndex, clusterEndpoints);
                %contourEndIndex = max(contourEndIndex-1,1); %take one off, to be sure of ending before it hits
                contourEndIndex = max(contourEndIndex,2);
                self.length = p(contourEndIndex);
                self.coarsePath = self.coarsePath(1:contourEndIndex);
                self.endValley = [];
                self.endPoint = self.coarsePath(contourEndIndex);
            end
        end
        
        function plot(self)
            plot(self.coarsePath,'-.k');
        end
        
        function [Z, W] = getQuad(self,freq,Npts)
            self.quadFreq = freq;
            if isinf(self.length)
                %get relevant weighted Gauss quad rule:
                [self.P0, self.Wgauss] = quad_gauss_exp(self.ODEorder, Npts);
                %scale by frequency and add zero
            else
                [self.P0, self.Wgauss] = gauss_quad(0,self.length*freq,Npts);
                self.P0=flipud(self.P0);
            end
            
            [~, self.h, self.dhdp] = SDpathODE(self.P0, self.phaseDerivs{2}, freq, self.ICs(1), self.fineTol);
            
            %this adjusts for small deviations from the path:
            weightWatchers = exp(1i*(freq*self.phaseDerivs{1}(self.h)-1i*self.P0.^self.ODEorder - freq*self.phaseDerivs{1}(self.startPoint)));
            
            if isinf(self.length)
                %absorb h'(p) and other constants into weights.
                W= exp(1i*freq*self.phaseDerivs{1}(self.startPoint)).*self.dhdp.*self.Wgauss.*weightWatchers;
            else
               W = self.dhdp.*self.Wgauss.*exp(1i*freq*self.phaseDerivs{1}(self.h));
            end
            Z=self.h;
        end
         
        function [Z, W] = reuseQuad(self, G, errThresh)
            if nargin == 2
                errThresh = inf;
            end
            if ~isinf(errThresh) %tweak old SD path using Newton iteration
                Zold=self.h;
                p = self.P0;
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
                weightWatchers = exp(1i*(self.quadFreq*g(Z)-1i*self.P0.^self.ODEorder - self.quadFreq*g(self.startPoint)));
                %absorb h'(p) and other constants into weights.
%                 W = (1/(self.quadFreq^(1/self.ODEorder)))*exp(1i*self.quadFreq*g(self.startPoint))...
%                     .*dZdp.*self.Wgauss.*weightWatchers;
                W = exp(1i*self.quadFreq*g(self.startPoint)).*dZdp.*self.Wgauss.*weightWatchers;
            else
                W = dZdp.*self.Wgauss.*exp(1i*self.quadFreq*g(Z)) ;
            end
            
        end
    end
end

