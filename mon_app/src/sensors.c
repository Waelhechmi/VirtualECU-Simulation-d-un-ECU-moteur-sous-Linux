#include "sensors.h"
#include <zephyr/kernel.h>

static int counter = 0;

void sensors_init(void) {
    printk("Sensors module initialized\n");
}

int read_rpm(void) {
    counter++;
    int rpm = 800 + (counter % 80) * 60;
    if (rpm > 5000) rpm = 800;
    return rpm;
}

int read_temperature(void) {
    int temp = 80 + (counter % 40) * 2;
    if (temp > 120) temp = 80;
    return temp;
}

int read_map_pressure(void) {
    return 90 + (counter % 30);
}