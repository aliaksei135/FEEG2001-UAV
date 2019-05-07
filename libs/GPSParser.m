classdef GPSParser < matlab.System...
        & matlab.system.mixin.Propagates ...
        & matlab.system.mixin.CustomIcon ...
        & coder.ExternalDependency ...
        & matlab.system.mixin.internal.SampleTime
    
    % GPSParser Parses the NMEA sentences received from GPS module.
    %
    % Takes the input from the Arduino Serial block.
    % Outputs the data selected by user on block mask (such as latitude, 
    % longitude, etc.)
    %
    % Copyright 2017 The MathWorks, Inc.
    %#codegen
    %#ok<*EMCA>
    
    % ------------------Properties of NMEA sentence------------------------
    % Used for a generic parser with specified characters for
    % Start, End, Separator, Checksum, and specified Buffer size
    properties(Nontunable)
        %Start Char -$ (dollar)
        StartChar = 36;
        %End Char - CR (carriage return)
        EndChar = 13;
        %Separator - , (comma)
        Separator = 44;
        %Character preceeding checksum - *(asterisk)
        CheckChar = 42;
        %BufferSize
        BufferSize = 80;
    end
    
    %-------- User entered logical values to be the block output ----------
    properties(Logical,Nontunable)
        % Time
        TimeOpt = false;
        % Latitude
        LatOpt = false;
        % Longitude
        LonOpt = false;
        % Number of Satellites Used
        NoSatOpt = false;
        % HDOP
        HdopOpt = false;
        % Altitude
        AltOpt = false;
        % Mean Sea Level
        MslOpt = false;
        % Speed
        SpeedOpt = false;
        % Track Angle
        TckAngOpt = false;
        % Date
        DateOpt = false;
    end
    
    %======================================================================
    methods
        % Constructor
        function obj = GPSParser(varargin)
            % Support name-value pair arguments when constructing the object.
            setProperties(obj,nargin,varargin{:});
        end
    end
    %======================================================================
    methods (Static, Access=protected)
        % Mask display
        function groups = getPropertyGroupsImpl()
            sentenceGroup = matlab.system.display.SectionGroup(...
                'Title', 'Output Selection',...
                'PropertyList', {'TimeOpt','LatOpt'...
                'LonOpt','NoSatOpt','HdopOpt','AltOpt','MslOpt',...
                'SpeedOpt','DateOpt','TckAngOpt'});
            groups = [sentenceGroup];
        end
        %------------------------------------------------------------------
        function simMode = getSimulateUsingImpl(~)
            simMode = 'Interpreted execution';
        end
        %------------------------------------------------------------------
        function isVisible = showSimulateUsingImpl
            isVisible = false;
        end
    end
    %======================================================================
    methods (Access=protected)
        %------------------------------------------------------------------
        function setupImpl(obj) %#ok<MANU>
            if isempty(coder.target)
                % Place simulation setup code here
            else
                % Call C-function implementing device initialization
                coder.cinclude('gps_parser.h');
                % Evaluate the serialSetup function
                coder.ceval('initialSetup', obj.BufferSize);
            end
        end
        %------------------------------------------------------------------
        function [statusOut, varargout] = stepImpl(obj,inData)   %#ocmdk<MANU>
            yout = uint8(zeros(obj.BufferSize,1));
            
            status = int8(0);    % Status for the gps parser  
            
            % Ouputs of the block
            statusOut = int8(0); % Output Status         
            time = uint32(0);       % Time
            latitude = 0;           % Latitude
            longitude = 0;          % Longitude
            noSat = uint8(0);       % Number of satellites 
            hdop = 0;               % HDOP
            alti = 0;               % Altitude
            msl = 0;                % Mean Sea Level
            speed = 0;              % Speed
            tckAngle = 0;           % Track Angle
            date = uint32(0);       % Date
            
            
            BytesToRead=length(inData);
            if isempty(coder.target)
                % Place simulation output code here
            else
                
                % Call C-function implementing device output
                coder.ceval('readData', inData, uint8(BytesToRead)...
                    , uint8(obj.StartChar), uint8(obj.EndChar)...
                    , uint8(obj.Separator), uint8(obj.CheckChar)...
                    , coder.wref(yout), uint8(obj.BufferSize)...
                    , coder.wref(status));
                
                if (status == 1)
                    coder.ceval('parseData'...
                        , yout ...
                        , coder.wref(time)...
                        , coder.wref(latitude)...
                        , coder.wref(longitude)...
                        , coder.wref(noSat)...
                        , coder.wref(hdop)...
                        , coder.wref(alti)...
                        , coder.wref(msl)...
                        , coder.wref(speed)...
                        , coder.wref(tckAngle)...
                        , coder.wref(date)...
                        , uint8(obj.BufferSize)...
                        , uint8(obj.Separator)...
                        , coder.wref(statusOut)...
                       );
                elseif (status < 0)
                    statusOut = status;
                end
                
                token=1;
                
                if obj.TimeOpt
                    varargout{token} = time;
                    token= token + 1;
                end
                if obj.LatOpt
                    varargout{token} = latitude;
                    token = token + 1;
                end
                if obj.LonOpt
                    varargout{token} = longitude;
                    token = token + 1;
                end
                if obj.NoSatOpt
                    varargout{token} = noSat;
                    token = token + 1;
                end
                if obj.HdopOpt
                    varargout{token} = hdop;
                    token = token + 1;
                end
                if obj.AltOpt
                    varargout{token} = alti;
                    token = token + 1;
                end
                if obj.MslOpt
                    varargout{token} = msl;
                    token = token + 1;
                end
                if obj.SpeedOpt
                    varargout{token} = speed;
                    token = token + 1;
                end
                if obj.TckAngOpt
                    varargout{token} = tckAngle;
                    token = token + 1;
                end
                if obj.DateOpt
                    varargout{token} = date;
                    token = token + 1;
                end
                
            end
        end
        %-----------------------------------------------------------------
        function releaseImpl(obj) %#ok<MANU>
            if isempty(coder.target)
                % Place simulation termination code here
            else
                % Call C-function implementing device termination
                coder.ceval('releaseBuffer');
            end
        end
        %------------------------------------------------------------------
        function num = getNumInputsImpl(~)
            num = 1;
        end
        %------------------------------------------------------------------
        function num = getNumOutputsImpl(obj)
            num = getOutputPortNum(obj);
        end
        %------------------------------------------------------------------
        function flag = isOutputSizeLockedImpl(~,~)
            flag = true;
        end
        %------------------------------------------------------------------
        function varargout = isOutputFixedSizeImpl(obj)
            varargout = fixedSizeOut(obj);
        end
        % -----------------------------------------------------------------
        function varargout = getOutputNamesImpl(obj)
            % Return the output names for the System block
            varargout = getOutName(obj);
        end
        %------------------------------------------------------------------
        function flag = isOutputComplexityLockedImpl(~,~)
            flag = true;
        end
        %------------------------------------------------------------------
        function varargout = isOutputComplexImpl(obj)
            varargout = getOutCompType(obj);
        end
        %------------------------------------------------------------------
        function varargout = getOutputSizeImpl(obj)
            varargout = getOutSz(obj);
        end
        %------------------------------------------------------------------
        function varargout = getOutputDataTypeImpl(obj)
            varargout = getOutputDtType(obj);
        end
        %------------------------------------------------------------------
        function icon = getIconImpl(~)
            % Define a string as the icon for the System block in Simulink.
            icon = 'GPSParser';
        end
        %------------------------------------------------------------------
        %------------------------------------------------------------------
        function num = getOutputPortNum(obj)
            % Returns the number of outputs expected from the System
            % object based on the number of statistics ports selected
            
            % The default status port
            num = 1;
            if obj.TimeOpt
                num = num + 1;
            end
            if obj.LatOpt
                num = num + 1;
            end
            if obj.LonOpt
                num = num + 1;
            end
            if obj.NoSatOpt
                num = num + 1;
            end
            if obj.HdopOpt
                num = num + 1;
            end
            if obj.AltOpt
                num = num + 1;
            end
            if obj.MslOpt
                num = num + 1;
            end
            if obj.SpeedOpt
                num = num + 1;
            end
            if obj.TckAngOpt
                num = num + 1;
            end
            if obj.DateOpt
                num = num + 1;
            end
        end
        %-----------------------------------------------------------------
        function outComplexity = getOutCompType(obj)
            % Returns the complexity of output and signals based on the
            % number of statistics ports selected by the user
            
            % All real outputs
            outComplexity = repmat({false},1,getOutputPortNum(obj));
        end
        %------------------------------------------------------------------
        function dataType = getOutputDtType(obj)
            dataType = {'int8'};
            
            if obj.TimeOpt
                dataType = [dataType, {'uint32'}];
            end
            if obj.LatOpt
                dataType = [dataType, {'double'}];
            end
            if obj.LonOpt
                dataType = [dataType, {'double'}];
            end
            if obj.NoSatOpt
                dataType = [dataType, {'uint8'}];
            end
            if obj.HdopOpt
                dataType = [dataType, {'double'}];
            end
            if obj.AltOpt
                dataType = [dataType, {'double'}];
            end
            if obj.MslOpt
                dataType = [dataType, {'double'}];
            end
            if obj.SpeedOpt
                dataType = [dataType, {'double'}];
            end
            if obj.TckAngOpt
                dataType = [dataType, {'double'}];
            end
            if obj.DateOpt
                dataType = [dataType, {'uint32'}];
            end
        end
        %------------------------------------------------------------------
        function outName = getOutName(obj)
            % Returns the names of the output ports from System object
            % based on the statistics ports selected by the user
            
            % For the entity exit
            outName = {'Status'};
            
            if obj.TimeOpt
                outName = [outName, {'Time'}];
            end
            if obj.LatOpt
                outName = [outName, {'Latitude'}];
            end
            if obj.LonOpt
                outName = [outName, {'Longitude'}];
            end
            if obj.NoSatOpt
                outName = [outName, {'Satellite'}];
            end
            if obj.HdopOpt
                outName = [outName, {'HDOP'}];
            end
            if obj.AltOpt
                outName = [outName, {'Altitude'}];
            end
            if obj.MslOpt
                outName = [outName, {'MSL'}];
            end
            if obj.SpeedOpt
                outName = [outName, {'Speed'}];
            end
            if obj.TckAngOpt
                outName = [outName, {'TrackAngle'}];
            end
            if obj.DateOpt
                outName = [outName, {'Date'}];
            end
        end
        %------------------------------------------------------------------
        function outSize = getOutSz(obj)
            outSize = repmat({[1 1]}, 1, getOutputPortNum(obj));
        end
        %------------------------------------------------------------------
        function fixOut = fixedSizeOut(obj)
            fixOut = repmat({true}, 1, getOutputPortNum(obj));
        end
    end
    %======================================================================
    methods (Static)
        %------------------------------------------------------------------
        function name = getDescriptiveName()
            name = 'Source';
        end
        %------------------------------------------------------------------
        function b = isSupportedContext(context)
            b = context.isCodeGenTarget('rtw');
        end
        %------------------------------------------------------------------
        function updateBuildInfo(buildInfo, context)
            if context.isCodeGenTarget('rtw')
                % Update buildInfo
                srcDir = fullfile(fileparts(mfilename('fullpath')),'src'); %#ok
                includeDir = fullfile(fileparts(mfilename('fullpath')),'include');
                addIncludePaths(buildInfo,includeDir);
                addSourceFiles(buildInfo,'gps_parser.cpp', srcDir);
                
            end
        end
    end
end
