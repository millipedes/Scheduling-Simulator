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

void host_lottery(thread * t, proc_list * pl) {
  time_t ti;
  srand((unsigned) time(&ti));
  int winning_ticket = rand() % pl->size;
}
