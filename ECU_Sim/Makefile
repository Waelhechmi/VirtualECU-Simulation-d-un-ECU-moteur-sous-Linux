CC=gcc
CFLAGS=-Iinclude -Wall -O2
.PHONY: all clean tests

SRC=src/main.c src/sensors.c src/actuators.c src/controller.c src/logger.c
OBJ=$(SRC:.c=.o)

all: ecu_sim

ecu_sim: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

tests:
	$(CC) $(CFLAGS) tests/test_sensors.c src/sensors.c src/controller.c  -o test_sensors
	$(CC) $(CFLAGS) tests/test_controller.c src/controller.c src/sensors.c  -o test_controller
	$(CC) $(CFLAGS) tests/test_integration.c src/sensors.c src/controller.c  src/actuators.c -o test_integration

clean:
	rm -f src/*.o ecu_sim test_sensors test_controller test_integration
