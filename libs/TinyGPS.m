classdef TinyGPS < matlab.System & coder.ExternalDependency & matlab.system.mixin.Propagates & matlab.system.mixin.SampleTime
    
    %#codegen
    %#ok<*EMCA>
    
    
    methods(Access = protected)
        function setupImpl(~)
            if coder.target('Rtw')
                coder.cinclude('TinyGPSWrapper.h');
                coder.ceval('GPSInit');
            end
        end

        function [out,out2,out3,out4,out5] = getOutputSizeImpl(~)
            % Return size for each output port
            out = 1;
            out2 = 1;
            out3 = 1;
            out4 = 1;
            out5 = 1;
        end

        function [out,out2,out3,out4,out5] = getOutputDataTypeImpl(~)
            % Return data type for each output port
            out = "single";
            out2 = "single";
            out3 = "single";
            out4 = "single";
            out5 = "single";
        end

        function [out,out2,out3,out4,out5] = isOutputComplexImpl(~)
            % Return true for each output port with complex data
            out = false;
            out2 = false;
            out3 = false;
            out4 = false;
            out5 = false;
        end

        function [out,out2,out3,out4,out5] = isOutputFixedSizeImpl(~)
            % Return true for each output port with fixed size
            out = true;
            out2 = true;
            out3 = true;
            out4 = true;
            out5 = true;
        end

        function sts = getSampleTimeImpl(obj)
            % Define sample time type and parameters
            sts = obj.createSampleTime("Type", "Discrete", "SampleTime", 0.15);

            % Example: specify discrete sample time
            % sts = obj.createSampleTime("Type", "Discrete", ...
            %     "SampleTime", 1);
        end

        function flag = allowModelReferenceDiscreteSampleTimeInheritanceImpl(~)
            % Return true if sample time inheritance is allowed in Model
            % blocks
            flag = false;
        end
        
        function [lat, lon, speed, course, alt] = stepImpl(~)
            if coder.target('Rtw')
                coder.ceval('GPSUpdate');
                lat = single(0);
                lon = single(0);
                speed = single(0);
                course = single(0);
                alt = single(0);
                lat = coder.ceval('getLat');
                lon = coder.ceval('getLng');
                speed = coder.ceval('getSpeed');
                course = coder.ceval('getCourse');
                alt = coder.ceval('getAlt');
            else
                lat = single(0);
                lon = single(0);
                speed = single(0);
                course = single(0);
                alt = single(0);
            end
%             lat = values(1);
%             lon = values(2);
%             speed = values(3);
%             course = values(4);
%             alt = values(5);
        end
        
    end
    
    methods(Static)
        function name = getDescriptiveName()
            name = 'TinyGPS';
        end
        
        function b = isSupportedContext(context)
            b = context.isCodeGenTarget('rtw');
        end
        
        % Update the build-time buildInfo
        function updateBuildInfo(buildInfo, context)
            if context.isCodeGenTarget('rtw')
                % Add include paths and source files for code generation
                
                [~, hardwaredir] = codertarget.arduinobase.internal.getArduinoIDERoot('hardware');
                librarydir = fullfile(hardwaredir, 'arduino', 'avr' , 'libraries');
                
                % get current directory path
                src_dir = mfilename('fullpath');
                [current_dir] = fileparts(src_dir);
                
                % add the include paths
                buildInfo.addIncludePaths(fullfile(librarydir, 'SoftwareSerial'));
                buildInfo.addIncludePaths(fullfile(current_dir,'..','nativelibs', 'include'));
                buildInfo.addIncludePaths(fullfile(librarydir, 'SoftwareSerial','src'));
                buildInfo.addIncludePaths(fullfile(hardwaredir, 'arduino', 'avr' , 'cores', 'arduino'));
                
                % add the source paths
                srcPaths = {...
                    fullfile(librarydir, 'SoftwareSerial'), ...s
                    fullfile(librarydir, 'SoftwareSerial','src'),...
                    fullfile(current_dir,'..','nativelibs','src'),...
                    fullfile(hardwaredir, 'arduino', 'avr' , 'cores', 'arduino')};
                buildInfo.addSourcePaths(srcPaths);
                
                
                % add the source files
                srcFiles = { 'TinyGPS++.cpp', 'TinyGPSWrapper.cpp'};
                buildInfo.addSourceFiles(srcFiles);
                
            end
        end
    end

    methods(Access = protected, Static)
        function simMode = getSimulateUsingImpl
            % Return only allowed simulation mode in System block dialog
            simMode = "Code Generation";
        end
    end
end
