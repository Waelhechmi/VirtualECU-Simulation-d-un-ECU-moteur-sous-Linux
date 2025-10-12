#include "actuators.h"
#include <zephyr/sys/printk.h>

void actuators_init(void) {
    printk("Actuators module initialized\n");
}

void control_injectors(int time) {
    // Simulation actionneurs
}

void control_ignition(int angle) {
    // Simulation actionneurs
}