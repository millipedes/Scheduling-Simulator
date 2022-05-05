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

struct CPU_T {
  thread ** threads;
  void * sched_algo;
  scheduling_type st;
  int thread_count;
  int current_time;
}cpu_t;

cpu_t * init_cpu(void * sched_algo, scheduling_type st, int thread_count
    int thread_work_qty);
void process_time_quantum(cpu_t * cpu, proc_list * pl);
void free_cpu(cpt_t * cpu);

#endif
