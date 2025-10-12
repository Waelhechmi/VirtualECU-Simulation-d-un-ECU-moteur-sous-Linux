#include "engine.h"
#include <zephyr/sys/printk.h>

static struct engine_data_s current_data;

void engine_init(void) {
    current_data.rpm = 800;
    current_data.temperature = 85;
    current_data.map_pressure = 100;
    printk("Engine module initialized\n");
}

void ecu_processing(struct engine_data_s *data) {
    // Logique simple
    data->injection_time = 25 + data->rpm / 100;
    data->ignition_angle = 10 + data->rpm / 200;
    
    if (data->rpm > 4500) {
        printk("ALERTE: RPM eleve: %d\n", data->rpm);
    }
    if (data->temperature > 105) {
        printk("ALERTE: Temperature elevee: %dC\n", data->temperature);
    }
    
    current_data = *data;
}

int get_current_rpm(void) { return current_data.rpm; }
int get_current_temperature(void) { return current_data.temperature; }