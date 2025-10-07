#ifndef TIMING_H
#define TIMING_H

#include <stdint.h>

#define MAX_TASKS 10

typedef struct {
    void (*task_fn)(void);
    uint32_t period_ms;
    uint64_t next_call_ms;
} Task;

void scheduler_init(void);
int scheduler_add_task(void (*fn)(void), uint32_t period_ms);
void scheduler_run(void);
uint64_t get_time_ms(void);

#endif
