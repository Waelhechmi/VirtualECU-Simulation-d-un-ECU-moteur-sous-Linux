#include <stdio.h>
#include "sensors.h"
#include "controller.h"
#include "actuators.h"


void check_test(const char* name, int condition, double value) {
    if(condition)
        printf("%s: PASS ✅ (Value=%.2f)\n", name, value);
    else
        printf("%s: FAIL ❌ (Value=%.2f)\n", name, value);
}

int main() {
    printf("=== Test Integration ECU ===\n");

    PID pid = {0.1, 0.01, 0.05, 0, 0};
    double target_rpm = 800;

    for(int i=0; i<5; i++) {
        SensorData s = read_sensors();
        ActuatorData a = update_controller(s, &pid, target_rpm);
        apply_actuators(a); 

        check_test("RPM sensor", s.rpm >= 700 && s.rpm <= 900, s.rpm);
        check_test("Injector command", a.injector_ms > 0, a.injector_ms);
        check_test("Throttle target", a.throttle_target >= 0 && a.throttle_target <= 100, a.throttle_target);
    }

    printf("=== Integration tests completed ===\n");
    return 0;
}
