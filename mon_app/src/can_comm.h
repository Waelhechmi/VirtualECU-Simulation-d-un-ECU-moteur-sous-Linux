#ifndef CAN_COMM_H
#define CAN_COMM_H

#include "engine.h"

void can_comm_init(void);
void send_engine_data(struct engine_data_s *data);
void process_can_messages(void);

#endif