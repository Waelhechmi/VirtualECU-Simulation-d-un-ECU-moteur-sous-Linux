#ifndef SENSORS_H
#define SENSORS_H

void sensors_init(void);
int read_rpm(void);
int read_temperature(void);
int read_map_pressure(void);

#endif