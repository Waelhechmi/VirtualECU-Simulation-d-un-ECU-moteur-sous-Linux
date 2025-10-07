#include <stdio.h>
#include "timing.h"
#include "sensors.h"
#include "controller.h"
#include "logger.h"

// Variables globales pour le scheduler
SensorData current_sensor;
ActuatorData current_actuator;
PID pid = {0.1,0.01,0.05,0,0};
double target_rpm = 800;

// Modèle moteur simple
void task_sensors(void){
    current_sensor = read_sensors();
}

void task_controller(void){
    current_actuator = update_controller(current_sensor, &pid, target_rpm);
    // Modèle moteur dynamique simple
    current_sensor.rpm += (current_actuator.injector_ms - current_sensor.rpm)*0.05;
    if(current_sensor.rpm<0) current_sensor.rpm=0;
}

void task_logger(void){
    static double start_time = 0;
    if(start_time==0) start_time = get_time_ms()/1000.0;
    double t = get_time_ms()/1000.0 - start_time;
    log_data(t, current_sensor, current_actuator);
    printf("Time: %.2fs | RPM: %.1f | Injector: %.2f\n", t, current_sensor.rpm, current_actuator.injector_ms);
}

int main(){
    init_logger();

    scheduler_init();
    scheduler_add_task(task_sensors, 10);     // 10 ms
    scheduler_add_task(task_controller, 10);  // 10 ms
    scheduler_add_task(task_logger, 100);     // 100 ms

    scheduler_run();

    close_logger();
    return 0;
}
