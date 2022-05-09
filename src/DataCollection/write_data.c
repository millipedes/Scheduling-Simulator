/**
 * @file write_data.c
 * @brief This file contains the functions which conduct tests and write data
 * from those tests to files.
 * @author Matthew C. Lindeman
 * @date May 08, 2022
 * @bug None known
 * @todo Nothing
 */
#include"include/write_data.h"

void conduct_test(void) {
  int testing_time = 30;
  FILE * fp = fopen("data_out/data.txt", "w");

  cpu_t * cpu = init_cpu(LOTTERY, THREAD_NO, THREAD_WORK);
  proc_list * pl = init_mem_proc_list(P_LIST_INITIAL_SIZE);
  for(int i = 0; i < testing_time; i++) {
    process_time_quantum(cpu, pl);
    fprintf(fp, "%d,%d\n", pl->b->available_space, i);
  }
  fclose(fp);
  free_cpu(cpu);
  free_proc_list(pl);
}
