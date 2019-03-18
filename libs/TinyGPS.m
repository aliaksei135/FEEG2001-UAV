classdef TinyGPS < matlab.System & coder.ExternalDependency
    
    %#codegen
    %#ok<*EMCA>
    

    methods(Access = protected)
        function setupImpl(~)
            if coder.target('Rtw')
                coder.cinclude('TinyGPSWrapper.h');
                coder.ceval('GPSInit');
            end
        end
        
        function [lat, lon, speed, course, alt, sats] = stepImpl(~)
            values = single(zeros(7,1));
            if coder.target('Rtw')
                coder.ceval('GPSRead', coder.wref(values));
            end
%             if(values(7) < 2000)
%                 valid = true;
                lat = single(values(1));
                lon = single(values(2));
                speed = single(values(3));
                course = single(values(4));
                alt = single(values(5));
                sats = single(values(6));
%             else
%                 valid = false;
%                 lat = single(0);
%                 lon = single(0);
%                 speed = single(0);
%                 course = single(0);
%                 alt = single(0);
%                 sats = single(0);
%             end
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
                    fullfile(librarydir, 'SoftwareSerial'), ...
                    fullfile(librarydir, 'SoftwareSerial','src'),...
                    fullfile(current_dir,'..','nativelibs','src'),...
                    fullfile(hardwaredir, 'arduino', 'avr' , 'cores', 'arduino')};
                buildInfo.addSourcePaths(srcPaths);
                
                
                % add the source files
                srcFiles = {'SoftwareSerial.cpp', 'TinyGPS++.cpp', 'TinyGPSWrapper.cpp'};
                buildInfo.addSourceFiles(srcFiles);
                
            end
        end
    end
end
