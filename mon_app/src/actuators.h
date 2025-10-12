#ifndef ACTUATORS_H
#define ACTUATORS_H

void actuators_init(void);
void control_injectors(int time);
void control_ignition(int angle);

#endif