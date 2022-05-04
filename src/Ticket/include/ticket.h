/**
 * @file ticket.h
 * @brief This file contains all funciton definitons for ticket.c
 * @author Matthew C. Lindeman
 * @date May 03, 2022
 * @bug None known
 * @todo Nothing
 */
#ifndef TICK_H
#define TICK_H

#include<stdio.h>
#include<stdlib.h>

typedef struct TICKET_T {
  int qty;
  int id;
}ticket;

ticket * init_ticket(int qty, int id);
void free_ticket(ticket * t);
void ticket_dump_stats(ticket * t);

#endif
