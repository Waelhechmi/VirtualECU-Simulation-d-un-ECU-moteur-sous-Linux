#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "sensors.h"
#include "actuators.h"
#include "controller.h"
#include "logger.h"

int main() {
    PID pid = {0.1, 0.01, 0.05, 0, 0};
    double target_rpm = 800;
    init_logger();

    for(int i=0; i<1000; i++) {
        SensorData s = read_sensors();
        ActuatorData a = update_controller(s, &pid, target_rpm);
        apply_actuators(a);
        log_data(i*0.01, s, a); 
        usleep(10000); // 100 Hz
    }

    close_logger();
    return 0;
}
