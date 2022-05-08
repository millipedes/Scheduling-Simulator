/**
 * @file process.c
 * @brief this file contains the functions relating to the process structure.
 * @author Matthew C. Lindeman
 * @date May 04, 2022
 * @bug None known
 * @todo Nothing
 */
#include"include/process.h"

/**
 * This function initializes a process struct
 * @param   tb - the ticket bundle associated with the process
 * @param   pt - the process type
 * @return N/a
 */
process * init_process(ticket_bundle * tb, process_type pt) {
  process * p = calloc(1, sizeof(struct PROCESS_T));
  p->tb = tb;
  p->pt = pt;
  p->id = tb->id;
  return p;
}

/**
 * This function is used in deubugging
 * @param    p - the process to be printed
 * @return N/a
 */
void process_print_specs(process * p) {
  printf("============================\n");
  printf("PROCESS TICKET BUNDLE\n");
  printf("============================\n");
  if(p->tb) {
    ticket_bundle_dump_stats(p->tb);
  }
  printf("----------------------------\n");
  printf("Process Type: %s\n", p->pt == 0 ? "MEMORY" : "IO");
  printf("Process ID: %d\n", p->id);
}

/**
 * This function frees a given process structure
 * @param    p - the process
 * @return N/a
 */
void free_process(process * p) {
  if(p) {
    if(p->tb) {
      free_ticket_bundle(p->tb);
      p->tb = NULL;
    }
    free(p);
  }
  p = NULL;
}
