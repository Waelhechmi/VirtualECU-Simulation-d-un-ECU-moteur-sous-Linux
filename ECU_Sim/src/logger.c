#include "logger.h"
#include <stdio.h>

static FILE *logfile;

void init_logger() {
    logfile = fopen("logs/ecu_log.csv", "w");
    fprintf(logfile, "time,rpm,tps,temp,injector_ms,throttle_target,ignition\n");
}

void log_data(double t, SensorData s, ActuatorData a) {
    fprintf(logfile, "%.3f,%.1f,%.1f,%.1f,%.2f,%.2f,%d\n",
            t, s.rpm, s.tps, s.temp, a.injector_ms, a.throttle_target, a.ignition_on);
}

void close_logger() {
    fclose(logfile);
}
