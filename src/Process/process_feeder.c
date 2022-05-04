/**
 * @file process_feeder.c
 * @brief This file contains the functions relating to randomly feeding
 * processes into the CPU
 * @author Matthew C. Lindeman
 * @date May 04, 2022
 * @bug None known
 * @todo Nothing
 */
#include"include/process_feeder.h"

/**
 * This function makes a new partition in the base and returns a process with
 * the correct ticket_bundle
 * @param     base - the base for the universe
 * @param     type - the type for the process
 * @param work_qty - the total quantity of work that the process requires to
 * complete
 * @return     N/a
 */
process * generate_process(base * base, process_type type, int work_qty) {
  add_ticket_bundle(base, work_qty);
  return init_process(base->general_population[base->bid->size - 1], type);
}
