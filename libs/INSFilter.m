classdef INSFilter < matlab.System
    
    %#codegen
    %#ok<*EMCA>
    
    % Public, tunable properties
    properties

    end
    
    properties(Nontunable)
        SampleRate = 0.01; %Sample Rate
        RefLoc = [0 0 0]; %Reference Location
        initPos = [0, 0, 0]; %Initial Position
        initVel = [0, 0, -1]; %Initial Linear Velocity
%         initOrient = ones(1, 'quaternion'); %Initial Orientation (Quarternion)
        
        accelBias = 0.19; % Constant Accelorometer Bias
        gyroBias = deg2rad(3.125); % Constant Gyroscope Bias        
        localMagField = [19.84 0.2 44.4]; % Local Magnetic Field Vector
        magBias = 100; % Constant Magnetometer Bias
    end
    
    % Pre-computed constants
    properties(Access = private)
        fil = insfilter('Magnetometer', true);
    end
    
    methods(Access = protected)
        function setupImpl(obj)
            obj.fil.IMUSampleRate = obj.SampleRate;
            obj.fil.ReferenceLocation = obj.RefLoc;
            
            initstate = zeros(22,1);
            initstate(1:4) = [1 0 0 0];
            initstate(5:7) = obj.initPos;
            initstate(8:10) = obj.initVel;
            initstate(11:13) =  obj.gyroBias./obj.SampleRate;
            initstate(14:16) =  obj.accelBias./obj.SampleRate;
            initstate(17:19) =  obj.localMagField;
            initstate(20:22) = obj.magBias./obj.SampleRate;
            
            obj.fil.State = initstate;
        end
        
        function [fusedPosition, fusedOrientation] = stepImpl(obj, accel, gyro, mag)
            predict(obj.fil, accel, gyro);
            [fusedPosition, fusedOrientation] = pose(obj.fil);
            fusemag(obj.fil, mag, 0.1);
            
        end
        
    end
    
    methods(Static)
        function name = getDescriptiveName()
            name = 'INS Filter';
        end      
    end
end
