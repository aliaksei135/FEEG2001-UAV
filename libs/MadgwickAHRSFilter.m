classdef MadgwickAHRSFilter < matlab.System
    
    %#codegen
    
    % Public, tunable properties
    properties
        SamplePeriod = 0.01;
        Beta = 0.1;               	% algorithm gain
    end
    
    methods(Access = protected)
        
        function quat = stepImpl(obj, Gyroscope, Accelerometer, Magnetometer, q)
%             if (norm(Magnetometer) ~= 0)
%                 quat = UpdateIMU(obj, Gyroscope, Accelerometer, q);
%             else
                quat = Update(obj, Gyroscope, Accelerometer, Magnetometer, q);
%             end
        end
    end
    
    methods
        function q = Update(obj, Gyroscope, Accelerometer, Magnetometer, q)
            
            % Reference direction of Earth's magnetic feild
            h = quatmultiply(q, quatmultiply([0 Magnetometer], quatconj(q)));
            b = [0 norm([h(2) h(3)]) 0 h(4)];
            
            % Gradient decent algorithm corrective step
            F = [2*(q(2)*q(4) - q(1)*q(3)) - Accelerometer(1)
                2*(q(1)*q(2) + q(3)*q(4)) - Accelerometer(2)
                2*(0.5 - q(2)^2 - q(3)^2) - Accelerometer(3)
                2*b(2)*(0.5 - q(3)^2 - q(4)^2) + 2*b(4)*(q(2)*q(4) - q(1)*q(3)) - Magnetometer(1)
                2*b(2)*(q(2)*q(3) - q(1)*q(4)) + 2*b(4)*(q(1)*q(2) + q(3)*q(4)) - Magnetometer(2)
                2*b(2)*(q(1)*q(3) + q(2)*q(4)) + 2*b(4)*(0.5 - q(2)^2 - q(3)^2) - Magnetometer(3)];
            J = [-2*q(3),                 	2*q(4),                    -2*q(1),                         2*q(2)
                2*q(2),                 	2*q(1),                    	2*q(4),                         2*q(3)
                0,                         -4*q(2),                    -4*q(3),                         0
                -2*b(4)*q(3),               2*b(4)*q(4),               -4*b(2)*q(3)-2*b(4)*q(1),       -4*b(2)*q(4)+2*b(4)*q(2)
                -2*b(2)*q(4)+2*b(4)*q(2),	2*b(2)*q(3)+2*b(4)*q(1),	2*b(2)*q(2)+2*b(4)*q(4),       -2*b(2)*q(1)+2*b(4)*q(3)
                2*b(2)*q(3),                2*b(2)*q(4)-4*b(4)*q(2),	2*b(2)*q(1)-4*b(4)*q(3),        2*b(2)*q(2)];
            step = (J'*F);
            step = step / norm(step);	% normalise step magnitude
            
            % Compute rate of change of quaternion
            qDot = 0.5 * quatmultiply(q, [0 Gyroscope(1) Gyroscope(2) Gyroscope(3)]) - obj.Beta * step';
            
            % Integrate to yield quaternion
            q = q + qDot * obj.SamplePeriod;
            q = q / norm(q); % normalise quaternion
        end
%         function q = UpdateIMU(obj, Gyroscope, Accelerometer, q)
%             
%             % Gradient decent algorithm corrective step
%             F = [2*(q(2)*q(4) - q(1)*q(3)) - Accelerometer(1)
%                 2*(q(1)*q(2) + q(3)*q(4)) - Accelerometer(2)
%                 2*(0.5 - q(2)^2 - q(3)^2) - Accelerometer(3)];
%             J = [-2*q(3),	2*q(4),    -2*q(1),	2*q(2)
%                 2*q(2),     2*q(1),     2*q(4),	2*q(3)
%                 0,         -4*q(2),    -4*q(3),	0    ];
%             step = (J'*F);
%             step = step / norm(step);	% normalise step magnitude
%             
%             % Compute rate of change of quaternion
%             qDot = 0.5 * quatmultiply(q, [0 Gyroscope(1) Gyroscope(2) Gyroscope(3)]) - obj.Beta * step';
%             
%             % Integrate to yield quaternion
%             q = q + qDot * obj.SamplePeriod;
%             q = q / norm(q); % normalise quaternion
%         end
    end
end
