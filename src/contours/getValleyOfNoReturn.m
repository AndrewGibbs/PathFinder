function v_out = getValleyOfNoReturn(h,V)%(h,Cnr,argBeta,V)
    [~,min_valley_index] = min(abs(exp(1i*angle(V))-exp(1i*angle(h))));
    v_out = V(min_valley_index);
%     order = length(V);
%     R = abs(h(end));
%     theta_end = mod(angle(h(end)),2*pi);
%     theta_diff = 0.95*pi/(2*order);
% 
%     no_valley = true;
%     for v_count = 1:length(V)
%         v = mod(angle(V(v_count)),2*pi);
%         %first check if theta_end is pointing sufficiently close to valley
%         theta_L = mod(v-theta_diff,2*pi);
%         theta_R = mod(v+theta_diff,2*pi);
%         in_arc = false;
%         if theta_L<theta_R
%             if theta_L<theta_end && theta_end< theta_R
%                 in_arc = true;
%             end
%         else % arc endpoints are either side of zero=2pi
%             if theta_L<theta_end % case where theta_L is to left of zero=2pi
%                 in_arc = true;
%             elseif theta_end<theta_R % case where theta_L is to right of zero=2pi
%                 in_arc = true;
%             end
%         end
% 
%         if in_arc && R>1 && R*min(sin(order*(v+theta_diff-argBeta)),cos(order*(v-theta_diff-argBeta)))>Cnr && theta_diff<pi/(2*order)
%             v_out = V(v_count);
%             no_valley = false;
%         end
%     end
%     
%     if no_valley
%         error('No valley found. Try increasing paramPathLength in ContourSD');
%     end
end