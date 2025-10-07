#include "timing.h"
#include <sys/time.h>
#include <unistd.h>

static Task tasks[MAX_TASKS];
static int task_count = 0;

uint64_t get_time_ms(void){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (uint64_t)(tv.tv_sec*1000 + tv.tv_usec/1000);
}

void scheduler_init(void){
    task_count = 0;
    for(int i=0;i<MAX_TASKS;i++){
        tasks[i].task_fn = NULL;
        tasks[i].period_ms = 0;
        tasks[i].next_call_ms = 0;
    }
}

int scheduler_add_task(void (*fn)(void), uint32_t period_ms){
    if(task_count >= MAX_TASKS) return -1;
    tasks[task_count].task_fn = fn;
    tasks[task_count].period_ms = period_ms;
    tasks[task_count].next_call_ms = get_time_ms() + period_ms;
    task_count++;
    return 0;
}

void scheduler_run(void){
    while(1){
        uint64_t now = get_time_ms();
        for(int i=0;i<task_count;i++){
            if(now >= tasks[i].next_call_ms){
                tasks[i].task_fn();
                tasks[i].next_call_ms += tasks[i].period_ms;
            }
        }
        usleep(1000); // CPU friendly
    }
}
