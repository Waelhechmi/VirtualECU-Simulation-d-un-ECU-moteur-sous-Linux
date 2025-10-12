#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include "engine.h"
#include "sensors.h"
#include "actuators.h"
#include "can_comm.h"

int main(void)
{
    struct engine_data_s data;
    int counter = 0;
    
    printk("*** ECU VIRTUEL AVEC MODULES ***\n");
    
    // Initialisation des modules
    engine_init();
    sensors_init();
    actuators_init();
    can_comm_init();
    
    printk("Tous les modules sont initialises\n");
    
    while (1) {
        counter++;
        
        // Lecture des capteurs
        data.rpm = read_rpm();
        data.temperature = read_temperature();
        data.map_pressure = read_map_pressure();
        
        // Traitement ECU
        ecu_processing(&data);
        
        // Contrôle actionneurs
        control_injectors(data.injection_time);
        control_ignition(data.ignition_angle);
        
        // Communication CAN
        send_engine_data(&data);
        process_can_messages();
        
        // Affichage statut
        if (counter % 5 == 0) {
            printk("STATUT: RPM=%d, TEMP=%dC, MAP=%d, INJ=%dms, IGN=%ddeg\n",
                   data.rpm, data.temperature, data.map_pressure,
                   data.injection_time, data.ignition_angle);
        }
        
        k_msleep(500);
    }
    
    return 0;
}