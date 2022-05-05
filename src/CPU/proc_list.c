/**
 * @file proc_list.c
 * @brief This file contains the functions relating to randomly feeding
 * processes into the CPU
 * @author Matthew C. Lindeman
 * @date May 04, 2022
 * @bug None known
 * @todo Nothing
 */
#include"include/proc_list.h"

/**
 * This funciton initializes a process list struct
 * @param size - the size of the mem proc list 
 * @return N/a
 */
proc_list * init_mem_proc_list(int size) {
  proc_list * pl = calloc(1, sizeof(struct PROC_LIST_T));
  pl->b = init_base(size); // This is total number of tickets
  pl->p_list = calloc(P_LIST_INITIAL_SIZE, sizeof(struct PROCESS_T *));
  for(int i = 0; i < P_LIST_INITIAL_SIZE; i++) {
    pl->p_list[i] = NULL;
  }
  pl->size = 0;
  pl->list_fault = 0;
  return proc_list;
}

/**
 * This funciton populates a process list for a given time quantum
 * @param   pl - the process list to which the new generation is written
 * @return N/a
 */
void populate_generation(proc_list * pl) {
  time_t t;
  srand((unsigned) time(&t));
  int gen_procs = rand() % MAX_NG_PROCS; // how many new procs to make
  int mem_flag = 0;
  int work_qty = 0;
  for(int i = 0; i < gen_procs; i++) {
    mem_flag = rand() % MEM_PROP;      // prop of mem to io
    work_qty = rand() % MAX_PROC_WORK; // qty of work for proc
    // This constant can be anything <= MEM_PROP just rep of U(1) prob dist
    if(mem_flag == 1) {
      add_process(pl, generate_process(pl, IO, work_qty));
    } else {
      add_process(pl, generate_process(pl, MEMORY, work_qty));
    }
  }
}

/**
 * This function adds a process to a process list otherwise faults if full
 * @param   pl - the process list
 * @param   np - the new process
 * @return N/a
 */
void add_process(proc_list * pl, process * np) {
  int index = 0;
  while(pl->p_list[index] != NULL) {
    index++;
  }
  if(pl->p_list[index]) {
    pl->p_list[index] = np;
  } else {
    pl->list_fault++;
  }
}

/**
 * This function removes a process with a given id from the process list
 * @param   pl - the process list
 * @param  pid - the process id
 * @return N/a
 */
void remove_process(proc_list * pl, int pid) {
  int index = 0;
  while(pl->p_list[index]->tb->id != pid) {
    index++;
  }
  if(pl->p_list[index]) {
    free_process(pl->p_list[index]);
    pl->p_list[index] = NULL;
  }
}

/**
 * This function makes a new partition in the base and returns a process with
 * the correct ticket_bundle
 * @param     base - the base for the universe
 * @param     type - the type for the process
 * @param work_qty - the total quantity of work that the process requires to
 * complete
 * @return     N/a
 */
process * generate_process(proc_list * pl, process_type type, int work_qty) {
  add_ticket_bundle(pl->b, work_qty);
  return init_process(pl->b->general_population[pl->b->bid->size - 1], type);
}

/**
 * This function frees a process list
 * @param   pl - the process list to be freed
 * @return N/a
 */
void free_proc_list(proc_list * pl) {
  if(pl) {
    if(pl->p_list) {
      for(int i = 0; i < pl->size; i++) {
        free_process(pl->p_list[i]);
      }
      free(pl->p_list);
    }
    free(pl);
  }
}
