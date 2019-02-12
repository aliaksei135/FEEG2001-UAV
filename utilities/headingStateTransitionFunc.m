function xhat = headingStateTransitionFunc(V_b)
%HEADINGSTATETRANSITIONFUNC State Transition Function for Heading sensor
%fusion

%#codegen

xhat = atan2(V_b(1), V_b(2)); %angle between X and Y velocities

end