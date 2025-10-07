#ifndef LOGGER_H
#define LOGGER_H

#include "sensors.h"
#include "controller.h"

void init_logger(void);
void log_data(double t, SensorData s, ActuatorData a);
void close_logger(void);

#endif
