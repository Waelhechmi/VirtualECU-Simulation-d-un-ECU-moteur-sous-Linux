#include "logger.h"
#include <stdio.h>

static FILE *fp = NULL; // bien static pour garder la valeur entre les appels

void init_logger(void){
    fp = fopen("logs/engine_data.csv","w");
    if(!fp) {
        perror("Failed to open log file");
        return;
    }
    fprintf(fp,"time,rpm,throttle,injector_ms\n");
}

void log_data(double t, SensorData s, ActuatorData a){
    if(fp){
        fprintf(fp,"%.3f,%.2f,%.2f,%.3f\n", t, s.rpm, s.throttle, a.injector_ms);
        fflush(fp); // <--- très important pour forcer l’écriture
    }
}

void close_logger(void){
    if(fp) fclose(fp);
}
