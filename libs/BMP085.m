classdef BMP085 < matlab.System & coder.ExternalDependency
    
    %#codegen
    %#ok<*EMCA>
    
    % Public, tunable properties
    properties
        Reference_Pressure = 101325; %Reference Pressure (Pa)
    end
    
    properties(DiscreteState)
        
    end
    
    % Pre-computed constants
    properties(Access = private)
        
    end
    
    methods(Access = protected)
        function setupImpl(obj)
            if coder.target('Rtw')
                coder.cinclude('BMP085Wrapper.h');
            end
        end
        
        function [press, temp, alt] = stepImpl(obj)
            if coder.target('Rtw')
                values = single(zeros(3,1));
                values(3) = obj.Reference_Pressure;
                coder.cinclude('BMP085Wrapper.h');
                coder.ceval('BMP085Read', coder.wref(values));
            end
            
            press = values(1);
            temp = values(2);
            alt = values(3);
            
        end
        
        function releaseImpl(obj)
            %
        end
    end
    
    methods(Static)
        function name = getDescriptiveName()
            name = 'BMP085';
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
                buildInfo.addIncludePaths(fullfile(librarydir, 'Wire'));
                buildInfo.addIncludePaths(fullfile(librarydir, 'Wire','utility'));
                buildInfo.addIncludePaths(fullfile(current_dir,'..','nativelibs', 'include'));
                buildInfo.addIncludePaths(fullfile(librarydir, 'Wire','src'));
                buildInfo.addIncludePaths(fullfile(librarydir, 'Wire','src','utility'));
                
                % add the source paths
                srcPaths = {...
                    fullfile(librarydir, 'Wire'), ...
                    fullfile(librarydir, 'Wire', 'utility'),...
                    fullfile(librarydir, 'Wire','src'),...
                    fullfile(librarydir, 'Wire','src','utility'),...
                    fullfile(current_dir,'..','nativelibs','src')};
                buildInfo.addSourcePaths(srcPaths);
                
                
                % add the source files
                srcFiles = {'Wire.cpp', 'twi.c', 'Adafruit_BMP085.cpp', 'BMP085Wrapper.cpp'};
                buildInfo.addSourceFiles(srcFiles);
                
            end
        end
    end
end
