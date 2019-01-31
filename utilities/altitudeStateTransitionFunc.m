function xhat = altitudeStateTransitionFunc(x, v)
%ALTITUDESTATETRANSITIONFUNC State Transition Function for Altitude sensor
%fusion

%#codegen

dt = 1; %time step
xhat = x + v(3)/dt; %step with Z velocity

end

