#include "actuators.h"
#include <stdio.h>

void apply_actuators(ActuatorData a) {
    printf("Injector=%.2f ms, Throttle=%.2f%%, Ignition=%d\n",
           a.injector_ms, a.throttle_target, a.ignition_on);
}
