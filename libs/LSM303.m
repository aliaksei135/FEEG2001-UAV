classdef LSM303 < matlab.System & coder.ExternalDependency
    
    %#codegen
    %#ok<*EMCA>

    methods(Access = protected)
        function setupImpl(~)
            if coder.target('Rtw')
                coder.cinclude('LSM303Wrapper.h');
                coder.ceval('LSM303Init');
            end
        end
        
        function [accel, mag] = stepImpl(~)
            values = single(zeros(6,1));
            if coder.target('Rtw')
                coder.ceval('LSM303Read', coder.wref(values));
            end
            accel = values(1:3);
            mag = values(4:6);
        end

    end
    
    methods(Static)
        function name = getDescriptiveName()
            name = 'LSM303';
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
                buildInfo.addIncludePaths(fullfile(hardwaredir, 'arduino', 'avr' , 'cores', 'arduino'));
                
                % add the source paths
                srcPaths = {...
                    fullfile(librarydir, 'Wire'), ...
                    fullfile(librarydir, 'Wire', 'utility'),...
                    fullfile(librarydir, 'Wire','src'),...
                    fullfile(librarydir, 'Wire','src','utility'),...
                    fullfile(current_dir,'..','nativelibs','src'),...
                    fullfile(hardwaredir, 'arduino', 'avr' , 'cores', 'arduino')};
                buildInfo.addSourcePaths(srcPaths);
                
                
                % add the source files
                srcFiles = {'Wire.cpp', 'twi.c', 'Adafruit_LSM303_U.cpp', 'LSM303Wrapper.cpp'};
                buildInfo.addSourceFiles(srcFiles);
                
            end
        end
    end
end
