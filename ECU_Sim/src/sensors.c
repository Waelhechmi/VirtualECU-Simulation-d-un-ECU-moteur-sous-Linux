#include "sensors.h"
#include <stdlib.h>

SensorData read_sensors() {
    SensorData s;
    s.rpm = 800 + rand()%50;     // RPM idle + bruit
    s.tps = 0;                    // throttle fermé
    s.temp = 70.0 + (rand()%10)/10.0;
    return s;
}
