/**
 * @file main.c
 * @brief This file contains the entry point for the project
 * @author Matthew C. Lindeman
 * @date May 03, 2022
 * @bug None known
 * @todo Nothing
 */
#include<stdio.h>
#include"CPU/include/cpu_t.h"
#include"constants_macros/include/contants.h"
#include"Schedulers/include/scheduling_type.h"
#include"CPU/include/proc_list.h"


int main(void) {
  cpu_t * cpu = init_cpu(LOTTERY, THREAD_NO, THREAD_WORK);
  cpu_print_specs(cpu);

  proc_list * pl = init_mem_proc_list(P_LIST_INITIAL_SIZE);
  process_time_quantum(cpu, pl);
  print_proc_list_specs(pl);

  free_cpu(cpu);
  //free_proc_list(pl);
  return 0;
}
