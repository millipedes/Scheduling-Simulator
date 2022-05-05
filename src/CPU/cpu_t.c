/**
 * @file cput_t.c
 * @brief this file contains the functions relating to the cpu with respect to
 * the program
 * @author Matthew C. Lindeman
 * @date May 04, 2022
 * @bug None known
 * @todo Nothing
 */
#include"include/cpu_t.h"

/**
 * This function initializes a cpu
 * @param    thread_count - the total number of threads that a cpu will have
 * @param thread_work_qty - the total amount of work a thread is capable of
 * provessing in one time quantum
 * @return
 */
cpu_t * init_cpu(void * sched_algo, schedule_type st, int thread_count,
    int thread_work_qty) {
  cpu_t * cpu = calloc(1, sizeof(struct CPU_T));
  cpu->thread_count = thread_count;
  cpu->st = st;
  cpu->threads = init_cpu_threads(thread_count, thread_work_qty);
  cpu->sched_algo = sched_algo;
  return cpu;
}

/**
 * This funciton initilizes the threads of the cpu
 * @param    thread_count - the number of threads to allocate
 * @param thread_work_qty - the qty of work a thread can complete over a tq
 * @return
 */
thread ** init_cpu_threads(int thread_count, int thread_work_qty) {
  thread ** threads = calloc(thread_count, sizeof(struct THREAD_T *));
  for(int i = 0; i < thread_count; i++) {
    threads[i] = init_thread(thread_work_qty);
  }
  return threads;
}

/**
 * This function processes on time quantum for the processor
 * @param  cpu - the cpu that will process the time quantum
 * @param   pl - the process list that will be read/written to
 * @return N/a
 */
void process_time_quantum(cpu_t * cpu, proc_list * pl) {
  populate_generation(pl);
}

/**
 * This function frees the cpu
 * @param  cpu - the cpu to be freed
 * @return N/a
 */
void free_cpu(cpu_t * cpu) {
  if(cpu) {
    if(cpu->threads) {
      for(int i = 0; i < cpu->thread_count; i++) {
        if(cpu->threads[i]) {
          free_thread(cpu->threads[i]);
        }
      }
      free(cpu->threads);
    }
    free(cpu);
  }
} 
