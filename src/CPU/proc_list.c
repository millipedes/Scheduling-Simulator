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
  return pl;
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
 * This function finds a particular ticket partition (which is represented by a
 * ticket_bundle in the code fyi) via the process's index in the prcess list.
 * Looking back this makes some pretty gross pointer stuff may do it different
 * next time
 * @param        pl - the process list
 * @param ticket_no - the ticket no selected by the lottery
 * @return -1 - Something went wrong
 *          i - the index of the ticket for that partition
 */
int find_ticket_partition_process_index(proc_list * pl, int ticket_no) {
  int ticket_sum = 0;
  for(int i = 0; i < pl->size; i++) {
    // Some entries will be NULL!
    if(pl->p_list[i]) {
      /**
       * Essentially just sum up the total number of tickets to simulate a
       * physical partition for each process
       */
      if(pl->p_list[i]->tb) {
        ticket_sum += pl->p_list[i]->tb->size;
      }
      if(ticket_sum >= ticket_no) {
        return i;
      }
    }
  }

  return -1;
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
  if(pl->size <= index) {
    pl->p_list[index] = np;
    pl->size++;
  } else {
    pl->list_fault++;
  }
}

/**
 * This function reduces a ticket bundle by some number of tickets
 * @param         b - the base which backs the currency
 * @param reduction - the quantity to reduce the ticket_bundle by
 * @param        id - the id of the ticket_bundle
 * @return
 */
void reduce_bundle(proc_list * pl, int reduction, int id) {
  int process_index = tbid_to_pid(pl, id);
  int tmp_size = 0;
  int tbid = find_ticket_bundle(pl->b, id);
  ticket_bundle * tmp;
  if(process_index > -1 && tbid > -1) {
    if(pl->b->general_population[tbid]) {
      tmp = pl->b->general_population[tbid];
      tmp_size = tmp->size;
      reduce_ticket_bundle_size(tmp, reduction);
      if(tmp_size > reduction) {
        pl->b->available_space += (tmp_size - tmp->size);
      } else {
        pl->b->available_space += tmp_size;
      }

      if(tmp->size == 0) {
        invalidate_tb(pl, process_index);
        delete_ticket_bundle(pl->b, tmp->id);
      }
    }
  }
}

void invalidate_tb(proc_list * pl, int process_index) {
  pl->p_list[process_index]->tb = NULL;
}

/**
 * This function converts a ticket bundle id to a process id
 * @param tbid - the ticket_bundle id
 * @return i - the index of the process
 *        -1 - not found!
 */
int tbid_to_pid(proc_list * pl, int tbid) {
  for(int i = 0; i < pl->size; i++) {
    if(pl->p_list[i]) {
      if(pl->p_list[i]->tb) {
        if(pl->p_list[i]->tb->id == tbid) {
          return i;
        }
      }
    }
  }
  return -1;
}

/**
 * This function removes a process with a given id from the process list
 * @param   pl - the process list
 * @param  pid - the process id
 * @return N/a
 */
void remove_process(proc_list * pl, int index) {
  if(pl->p_list[index]) {
    free_process(pl->p_list[index]);
    pl->p_list[index] = NULL;
    pl->size--;
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
 * This function prints the process list data
 * @param   pl - the process list to printed
 * @return N/a
 */
void print_proc_list_specs(proc_list * pl) {
  for(int i = 0; i < pl->size; i++) {
    // Some entries are NULL!
    if(pl->p_list[i]) {
      process_print_specs(pl->p_list[i]);
    }
  }
  base_dump_stats(pl->b);
  printf("----------------------------\n");
  printf("PROC LIST SIZE: %d\n", pl->size);
  printf("PROC LIST LIST FAULT: %d\n", pl->list_fault);
  printf("----------------------------\n");
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
        // Some will be NULL
        if(pl->p_list[i]) {
          free_process(pl->p_list[i]);
        }
      }
      free(pl->p_list);
    }

    if(pl->b) {
      free_base(pl->b, 0);
    }
    free(pl);
  }
}
