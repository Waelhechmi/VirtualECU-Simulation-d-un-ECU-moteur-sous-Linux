#ifndef LOGGER_H
#define LOGGER_H
#include "sensors.h"
#include "actuators.h"

void init_logger();
void log_data(double t, SensorData s, ActuatorData a);
void close_logger();

#endif
