#include "controller.h"

ActuatorData update_controller(SensorData s, PID *pid, double target_rpm){
    double error = target_rpm - s.rpm;
    pid->integral += error * 0.01; // dt=0.01s
    double derivative = (error - pid->prev_error)/0.01;
    double output = pid->Kp*error + pid->Ki*pid->integral + pid->Kd*derivative;
    pid->prev_error = error;

    // Commande injecteur simulée
    ActuatorData a = {output};
    return a;
}
