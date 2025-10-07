#include "sensors.h"

// Pour le moment, capteurs simulés simples
static SensorData current_sensor = {0.0, 0.0};

SensorData read_sensors(void){
    // throttle peut évoluer si tu veux simuler un pilote
    current_sensor.throttle += 0.1; 
    if(current_sensor.throttle > 100) current_sensor.throttle = 0;
    return current_sensor;
}

void update_sensor_rpm(double rpm){
    current_sensor.rpm = rpm;
}
