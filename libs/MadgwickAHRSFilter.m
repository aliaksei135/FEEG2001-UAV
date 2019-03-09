classdef MadgwickAHRSFilter < matlab.System

    % Public, tunable properties
    properties
        SamplePeriod = 0.02;
        Beta = 0.1;               	% algorithm gain
    end
    
    methods(Access = protected)

        function stepImpl(obj, Gyroscope, Accelerometer, Magnetometer)
            global q;
            
            % Normalise accelerometer measurement
            if(norm(Accelerometer) == 0), return; end	% handle NaN
            Accelerometer = Accelerometer / norm(Accelerometer);	% normalise magnitude

            % Normalise magnetometer measurement
            if(norm(Magnetometer) == 0)
                % Gradient decent algorithm corrective step
                F = [2*(q(2)*q(4) - q(1)*q(3)) - Accelerometer(1)
                    2*(q(1)*q(2) + q(3)*q(4)) - Accelerometer(2)
                    2*(0.5 - q(2)^2 - q(3)^2) - Accelerometer(3)];
                J = [-2*q(3),	2*q(4),    -2*q(1),	2*q(2)
                    2*q(2),     2*q(1),     2*q(4),	2*q(3)
                    0,         -4*q(2),    -4*q(3),	0    ];
                step = (J'*F);
                step = step / norm(step);	% normalise step magnitude
                
                % Compute rate of change of quaternion
                qDot = 0.5 * quatmultiply(q, [0 Gyroscope(1) Gyroscope(2) Gyroscope(3)]) - obj.Beta * step';
                
                % Integrate to yield quaternion
                q = q + qDot * obj.SamplePeriod;
                q = q / norm(q); % normalise quaternion
                return;
            end
            Magnetometer = Magnetometer / norm(Magnetometer);	% normalise magnitude
            
            mag = [0 Magnetometer(1) Magnetometer(2) Magnetometer(3)];
            % Reference direction of Earth's magnetic feild
            h = quatmultiply(q, quatmultiply(mag, quatconj(q)));
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
            q = q / quatnorm(q); % normalise quaternion
        end

    end
end
