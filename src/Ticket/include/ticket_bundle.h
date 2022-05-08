/**
 * @file ticket_bundle.h
 * @brief This file contains the function definitions for ticket_bundle.c
 * @author Matthew C. Lindeman
 * @date May 03, 2022
 * @bug None known
 * @todo Nothing
 */
#ifndef TKB_H
#define TKB_H

#include<stdio.h>
#include<stdlib.h>
#include"ticket.h"

typedef struct TICKET_BUNDLE_T {
  ticket ** tickets;
  int size;
  int id;
}ticket_bundle;

ticket_bundle * init_ticket_bundle(int id);
void add_ticket(ticket_bundle * tb, int qty);
void reduce_ticket_bundle_size(ticket_bundle * tmp, int reduction);
void free_ticket_bundle(ticket_bundle * tb);
void ticket_bundle_dump_stats(ticket_bundle * tb);


#endif
