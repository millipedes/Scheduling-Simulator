/**
 * @file lottery.c
 * @brief This file contains the functions required to process a process_list in
 * a logical manner with respect to the lottery algorithm
 * @author Matthew C. Lindeman
 * @date May 05, 2022
 * @bug None known
 * @todo Nothing
 */
#include"include/lottery.h"


/**
 * This function is responsible for hosting one lottery (to include the
 * allocation of resources [coded as the reduction of the ticket bundle of] to
 * the process)
 * @param  t - the ticket
 * @param pl - the process list
 * @return
 */
void host_lottery(thread * t, proc_list * pl) {
  time_t ti;
  srand((unsigned) time(&ti));
  int windex = (pl->b->total_space - pl->b->available_space);
  int winner = 0;
  if(windex > 0) {
    winner = rand() % windex;
  }
  int reduction_index = find_ticket_partition_process_index(pl, winner);
  reduce_bundle(pl->b, t->work_qty, pl->p_list[reduction_index]->tb->id);
}
