#ifndef SENSORS_H
#define SENSORS_H

typedef struct {
    double rpm;     // RPM 
    double tps;   // throttle 
    double temp;  // °C
} SensorData;

SensorData read_sensors();

#endif
