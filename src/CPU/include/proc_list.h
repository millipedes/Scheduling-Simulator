/**
 * @file proc_list.h
 * @brief This file contains the function definitions for proc_list.c
 * @author Matthew C. Lindeman
 * @date May 04, 2022
 * @bug None known
 * @todo Nothing
 */
#ifndef PL_H
#define PL_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"../../Process/include/process.h"
#include"../../Process/include/process_type.h"
#include"../../Ticket/include/base.h"
#include"../../constants_macros/include/contants.h"

typedef struct PROC_LIST_T {
  process ** p_list;
  base * b;
  int size;
  int list_fault;
}proc_list;

proc_list * init_mem_proc_list(int size);
void populate_generation(proc_list * pl);
int find_ticket_partition_process_index(proc_list * pl, int ticket_no);
void add_process(proc_list * pl, process * np);
void remove_process(proc_list * pl, int pid);
process * generate_process(proc_list * base, process_type type, int work_qty);
void free_proc_list(proc_list * pl);

#endif
