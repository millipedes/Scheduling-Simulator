#ifndef CPUT_H
#define CPUT_H

#include<stdlib.h>
#include"thread.h"

struct CPU_T {
  thread ** threads;
  int thread_count;
  int current_time;
}cpu_t;

cpu_t * init_cpu(int thread_count);
void process_time_quantum(cpu_t * cpu);
void free_cpu(cpt_t * cpu);

#endif
