cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(mon_app)

target_sources(app PRIVATE 
    src/main.c
    src/engine.c
    src/sensors.c
    src/actuators.c
    src/can_comm.c
)

target_include_directories(app PRIVATE src)