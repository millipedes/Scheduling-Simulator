/**
 * @file process.h
 * @brief this file contains the functions definitions for process.c
 * @author Matthew C. Lindeman
 * @date May 04, 2022
 * @bug None known
 * @todo Nothing
 */
#ifndef PROC_H
#define PROC_H

#include<stdlib.h>
#include"process_type.h"
#include"../../Ticket/include/ticket_bundle.h"

typedef struct PROCESS_T {
  ticket_bundle * tb;
  process_type pt;
}process;

process * init_process(ticket_bundle * tb, process_type pt);
void free_process(process * p);

#endif
