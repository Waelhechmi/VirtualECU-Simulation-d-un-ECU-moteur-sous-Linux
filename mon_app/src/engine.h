#ifndef ENGINE_H
#define ENGINE_H

// Structure de données
struct engine_data_s {
    int rpm;
    int temperature;
    int map_pressure;
    int injection_time;
    int ignition_angle;
};

// Fonctions
void engine_init(void);
void ecu_processing(struct engine_data_s *data);
int get_current_rpm(void);
int get_current_temperature(void);

#endif