/**
 * @file ticket_bundle.c
 * @brief This file contains the functions relating to the ticket_bundle
 * @author Matthew C. Lindeman
 * @date May 03, 2022
 * @bug None known
 * @todo Nothing
 */
#include"include/ticket_bundle.h"

/**
 * This function initializes a ticket_bundle and returns it
 * @param   id - the id of the ticket bundle
 * @param size - the total scalar quantity of tickets
 * @return  tb - the ticket_bundle
 */
ticket_bundle * init_ticket_bundle(int id, int size) {
  ticket_bundle * tb = calloc(1, sizeof(struct TICKET_BUNDLE_T));
  tb->tickets = NULL;
  tb->size = size;
  return tb;
}

/**
 * This funciton adds a ticket to the ticket bundle.
 * @param ticket - This is the ticket that will be added to the ticket_bundle
 * @return N/a
 */
void add_ticket(ticket_bundle * tb, ticket * ticket) {
  tb->size++;
  if(tb->tickets) {
    tb->tickets = realloc(tb->tickets, tb->size * sizeof(struct TICKET_T *));
  } else {
    tb->tickets = calloc(tb->size, sizeof(struct TICKET_T *));
  }
  tb->tickets[tb->size - 1] = ticket;
}


/**
 * This funciton frees a ticket_bundle
 * @param tb - the ticket bundle that will be freed
 * @return N/a
 */
void free_ticket_bundle(ticket_bundle * tb) {
  if(tb) {
    if(tb->tickets) {
      for(int i = 0; i < tb->size; i++) {
        free_ticket(tb->tickets[i]);
      }
      free(tb->tickets);
    }
    free(tb);
  }
}
