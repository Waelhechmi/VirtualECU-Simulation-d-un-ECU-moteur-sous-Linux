#include <stdio.h>
#include "controller.h"


void check_test(const char* name, int condition, double value) {
    if(condition)
        printf("%s: PASS ✅ (Value=%.2f)\n", name, value);
    else
        printf("%s: FAIL ❌ (Value=%.2f)\n", name, value);
}

int main() {
    printf("=== Test Controller Module ===\n");

    PID pid = {0.1, 0.01, 0.05, 0, 0};
    SensorData s = {750, 0, 70};
    double target_rpm = 800;

    ActuatorData a = update_controller(s, &pid, target_rpm);

    check_test("Injector command", a.injector_ms > 0, a.injector_ms);
    check_test("Throttle target", a.throttle_target >= 0 && a.throttle_target <= 100, a.throttle_target);
    check_test("Ignition", a.ignition_on == 1, (double)a.ignition_on);

    printf("=== Controller tests completed ===\n");
    return 0;
}
