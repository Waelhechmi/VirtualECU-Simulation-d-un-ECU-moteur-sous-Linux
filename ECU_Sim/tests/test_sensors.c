#include <stdio.h>
#include "sensors.h"

void check_test(const char* name, int condition, double value) {
    if(condition)
        printf("%s: PASS ✅ (Value=%.2f)\n", name, value);
    else
        printf("%s: FAIL ❌ (Value=%.2f)\n", name, value);
}

int main() {
    printf("=== Test Sensors Module ===\n");

    SensorData s = read_sensors();

    check_test("RPM sensor", s.rpm >= 700 && s.rpm <= 900, s.rpm);
    check_test("Temperature sensor", s.temp >= 70 && s.temp <= 80, s.temp);
    check_test("Throttle sensor", s.tps >= 0 && s.tps <= 100, s.tps);

    printf("=== Sensors tests completed ===\n");
    return 0;
}
