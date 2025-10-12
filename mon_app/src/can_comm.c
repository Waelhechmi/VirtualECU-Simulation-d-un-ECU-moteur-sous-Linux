#include "can_comm.h"
#include <zephyr/sys/printk.h>

static int message_count = 0;

void can_comm_init(void) {
    printk("CAN communication initialized\n");
}

void send_engine_data(struct engine_data_s *data) {
    message_count++;
    if (message_count % 20 == 0) {
        printk("CAN: Sent data - RPM:%d, TEMP:%d\n", data->rpm, data->temperature);
    }
}

void process_can_messages(void) {
    // Simulation réception CAN
}