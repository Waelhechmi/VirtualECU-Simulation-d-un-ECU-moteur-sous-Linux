#ifndef ACTUATORS_H
#define ACTUATORS_H

typedef struct {
    double injector_ms;
    int ignition_on;
    double throttle_target;
} ActuatorData;

void apply_actuators(ActuatorData a);

#endif
