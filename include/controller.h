#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "sensors.h"

typedef struct {
    double Kp;
    double Ki;
    double Kd;
    double integral;
    double prev_error;
} PID;

typedef struct {
    double injector_ms;
} ActuatorData;

ActuatorData update_controller(SensorData s, PID *pid, double target_rpm);

#endif
