#include "controller.h"

ActuatorData update_controller(SensorData s, PID *pid, double target_rpm) {
    ActuatorData a;
    double error = target_rpm - s.rpm;
    pid->integral += error;
    double derivative = error - pid->last_error;
    double output = pid->kp*error + pid->ki*pid->integral + pid->kd*derivative;
    pid->last_error = error;

    a.injector_ms = 1.5 + output*0.01;
    a.throttle_target = 10.0 + output*0.1;
    if(a.throttle_target < 0) a.throttle_target = 0;
    if(a.throttle_target > 100) a.throttle_target = 100;
    a.ignition_on = 1;

    return a;
}
