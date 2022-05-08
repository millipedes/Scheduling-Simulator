/**
 * @file cput_t.h
 * @brief this file contains the function definitions for cpu_t.c
 * @author Matthew C. Lindeman
 * @date May 04, 2022
 * @bug None known
 * @todo Nothing
 */
#ifndef CPUT_H
#define CPUT_H

#include<stdlib.h>
#include"thread.h"
#include"proc_list.h"
#include"../../Schedulers/include/scheduling_type.h"
#include"../../Schedulers/include/lottery.h"

typedef struct CPU_T {
  thread ** threads;
  schedule_type st;
  int thread_count;
  int current_time;
}cpu_t;

cpu_t * init_cpu(schedule_type st, int thread_count, int thread_work_qty);
thread ** init_cpu_threads(int thread_count, int thread_work_qty);
void process_time_quantum(cpu_t * cpu, proc_list * pl);
void cpu_print_specs(cpu_t * cpu);
void free_cpu(cpu_t * cpu);

#endif
