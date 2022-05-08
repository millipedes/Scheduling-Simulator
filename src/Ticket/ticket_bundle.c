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
ticket_bundle * init_ticket_bundle(int id) {
  ticket_bundle * tb = calloc(1, sizeof(struct TICKET_BUNDLE_T));
  tb->tickets = NULL;
  tb->id = id;
  tb->size = 0;
  return tb;
}

/**
 * This funciton adds a ticket to the ticket bundle.
 * @param ticket - This is the ticket that will be added to the ticket_bundle
 * @return N/a
 */
void add_ticket(ticket_bundle * tb, int qty) {
  tb->size++;
  if(tb->tickets) {
    tb->tickets = realloc(tb->tickets, tb->size * sizeof(struct TICKET_T *));
  } else {
    tb->tickets = calloc(tb->size, sizeof(struct TICKET_T *));
  }
  tb->tickets[tb->size - 1] = init_ticket(qty, tb->size - 1);
}

/**
 * This function reduces the size of a ticket_bundle
 * @param       tmp - the ticket bundle to be reduced
 * @param reduction - the qty of tickets to reduce by
 * @return          - the qty the tb was reduced by
 */
int reduce_ticket_bundle_size(ticket_bundle * tmp, int reduction) {
  if(tmp->size >= reduction) {
    for(int i = (tmp->size - reduction); i < tmp->size; i++) {
      free_ticket(tmp->tickets[i]);
      tmp->tickets[i] = NULL;
      tmp->size--;
    }
    return reduction;
  } else {
    for(int i = 0; i < tmp->size; i++) {
      free_ticket(tmp->tickets[i]);
      tmp->tickets[i] = NULL;
      tmp->size--;
    }
    return tmp->size;
  }
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

/**
 * This function is used for debuggindg, it prints all data related to the
 * ticket bundle
 * @param   tb - the ticket bundle
 * @return N/a
 */
void ticket_bundle_dump_stats(ticket_bundle * tb) {
  printf("===============================\n");
  printf("\tTICKET STATS\n");
  printf("===============================\n");
  for(int i = 0; i < tb->size; i++) {
    ticket_dump_stats(tb->tickets[i]);
  }
  printf("===============================\n");
  printf("-------------------------------\n");
  printf("SIZE: %d\n", tb->size);
  printf("  ID: %d\n", tb->id);
  printf("-------------------------------\n");
}
