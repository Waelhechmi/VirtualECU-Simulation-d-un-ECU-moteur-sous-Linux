#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "sensors.h"
#include "actuators.h"

typedef struct {
    double kp;
    double ki;
    double kd;
    double integral;
    double last_error;
} PID;

ActuatorData update_controller(SensorData s, PID *pid, double target_rpm);

#endif
