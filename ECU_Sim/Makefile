
CC ?= gcc

CFLAGS ?= -Iinclude -Wall -O2
LDFLAGS ?=

SRC = src/main.c src/sensors.c src/actuators.c src/controller.c src/logger.c
OBJ = $(SRC:.c=.o)

TEST_SRC = tests/test_sensors.c tests/test_controller.c tests/test_integration.c
TESTS = test_sensors test_controller test_integration


.PHONY: all clean tests run_tests

all: ecu_sim

ecu_sim: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

tests: $(TESTS)

test_sensors: tests/test_sensors.c src/sensors.c src/controller.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

test_controller: tests/test_controller.c src/controller.c src/sensors.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

test_integration: tests/test_integration.c src/sensors.c src/controller.c src/actuators.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

run_tests: tests
ifeq ($(CC),arm-linux-gnueabihf-gcc)
	qemu-arm ./test_sensors
	qemu-arm ./test_controller
	qemu-arm ./test_integration
else
	./test_sensors
	./test_controller
	./test_integration
endif

clean:
	rm -f src/*.o ecu_sim $(TESTS)
