/**
 * @file ticket.c
 * @brief This file contains all relevant functions for the ticket object
 * @author Matthew C. Lindeman
 * @date May 03, 2022
 * @bug None known
 * @todo Nothing
 */
#include"include/ticket.h"

/**
 * This funciton initializes a ticket
 * @param qty - the quantity for which the ticket should be evaluated
 * @param  id - the id of the ticket
 * @return  t - the ticket
 */
ticket * init_ticket(int qty, int id) {
  ticket * t = calloc(1, sizeof(struct TICKET_T));
  t->qty = qty;
  t->qty = id;
  return t;
}

/**
 * This function frees a ticket, essentially a free alias
 * @param t - the ticket to be freed
 * @return N/a
 */
void free_ticket(ticket * t) {
  if(t) {
    free(t);
  }
}

void ticket_dump_stats(ticket * t) {
  printf("-------------------------------");
  printf("QTY: %d", t->qty);
  printf(" ID: %d", t->id);
  printf("-------------------------------");
}
