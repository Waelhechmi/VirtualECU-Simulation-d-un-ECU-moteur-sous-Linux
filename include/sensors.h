#ifndef SENSORS_H
#define SENSORS_H

typedef struct {
    double rpm;
    double throttle;  // 0-100%
} SensorData;

SensorData read_sensors(void);

#endif
