/**
 * @file thread.c
 * @brief one of the few files where I coded to an implementation rather than an
 * interface as threads are pretty specialized in their nature
 * @author Matthew C. Lindeman
 * @date May  04, 2022
 * @bug None known
 * @todo Nothing
 */
#include"include/thread.h"

/**
 * This function initializes a thread
 * @param work_qty - the total quatity of work that the thread can perform for a
 * given time quantum
 * @return     N/a
 */
thread * init_thread(int work_qty) {
  thread * t = calloc(1, sizeof(struct THREAD_T));
  t->work_qty = work_qty;
  return t;
}

/**
 * This is used as a debugging function for the thread structure
 * @param    t - the thread
 * @return N/a
 */
void thread_print_specs(thread * t) {
  printf("-----------------------------------------\n");
  printf("THREAD WORK QTY: %d\n", t->work_qty);
  printf("-----------------------------------------\n");
}

/**
 * This function is just an alias for smart free to look nice
 * @param    t - the ticket to be freed
 * @return N/a
 */
void free_thread(thread * t) {
  if(t) {
    free(t);
  }
} 
