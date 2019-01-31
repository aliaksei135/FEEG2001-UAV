function xhat = headingStateTransitionFunc(x, v)
%HEADINGSTATETRANSITIONFUNC State Transition Function for Heading sensor
%fusion

%#codegen

dt = 1; %1 sec time step
xhat = x + atan2(v(1), v(2))/dt; %step with angle between X and Y velocities

end