classdef SDLogger < matlab.System & coder.ExternalDependency
    
    %#codegen
    %#ok<*EMCA>

    methods(Access = protected)
        function setupImpl(~)
            if coder.target('rtw')
                coder.cinclude('SDLogger.h');
                coder.ceval('SDLoggerInit');
            end
        end
        
        function stepImpl(~,data)
            if coder.target('rtw')

               coder.ceval('SDLoggerLog', data, numel(data)) 
            end
        end
        
        function releaseImpl(~)
           if coder.target('rtw')
               coder.ceval('SDLoggerDestroy');
           end
        end
    end
    
    methods(Static)
        function name = getDescriptiveName()
            name = 'SDLogger';
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
                buildInfo.addIncludePaths(fullfile(codertarget.arduinobase.internal.getArduinoIDERoot('libraries'), 'SD'));
                buildInfo.addIncludePaths(fullfile(codertarget.arduinobase.internal.getArduinoIDERoot('libraries'), 'SD', 'src'));
                buildInfo.addIncludePaths(fullfile(codertarget.arduinobase.internal.getArduinoIDERoot('libraries'), 'SD', 'src', 'utility'));
                buildInfo.addIncludePaths(fullfile(librarydir, 'SPI'));
                buildInfo.addIncludePaths(fullfile(current_dir,'..','nativelibs', 'include'));
                buildInfo.addIncludePaths(fullfile(librarydir, 'SPI','src'));
                buildInfo.addIncludePaths(fullfile(hardwaredir, 'arduino', 'avr' , 'cores', 'arduino'));
                
                % add the source paths
                srcPaths = {...
                    fullfile(codertarget.arduinobase.internal.getArduinoIDERoot('libraries'), 'SD', 'src', 'utility'), ...
                    fullfile(codertarget.arduinobase.internal.getArduinoIDERoot('libraries'), 'SD', 'src'), ...
                    fullfile(librarydir, 'SPI'), ...
                    fullfile(librarydir, 'SPI','src'),...
                    fullfile(current_dir,'..','nativelibs','src'),...
                    fullfile(hardwaredir, 'arduino', 'avr' , 'cores', 'arduino')};
                buildInfo.addSourcePaths(srcPaths);
                
                
                % add the source files
                srcFiles = {'SPI.cpp', 'SD.cpp', 'SdFile.cpp', 'SdVolume.cpp', 'File.cpp', 'Sd2Card.cpp', 'SDLogger.cpp'};
                buildInfo.addSourceFiles(srcFiles);
            end
        end
    end
end