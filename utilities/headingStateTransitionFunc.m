function xhat = headingStateTransitionFunc(V_b)
%HEADINGSTATETRANSITIONFUNC State Transition Function for Heading sensor
%fusion

%#codegen

dt = 1; %1 sec time step
xhat = x + atan2(V_b(1), V_b(2))/dt; %step with angle between X and Y velocities

end