/**
 * @file base.h
 * @brief This file contains the functions definitions for base.c
 * @author Matthew C. Lindeman
 * @date May 03, 2022
 * @bug None known
 * @todo Nothing
 */
#ifndef BAS_H
#define BAS_H

#include<stdio.h>
#include<stdlib.h>
#include"ticket_bundle.h"

typedef struct BASE_T {
  ticket_bundle ** general_population;
  int available_space;
  int total_space;
  int total_fault_count;
}base;

typedef struct B_ID_T {
  int * id_space;
  int * active_ids; // 1 - active; 0 - inactive
  int current_id;
  int size;
}b_id;

base * init_base(int total_space);
b_id * init_b_id(void);
void add_ticket_bundle(base * b, b_id * bid, int partition_qty);
void delete_ticket_bundle(base * b, b_id * bid, int id);
int find_ticket_bundle(base * b, b_id * bid, int id);
void free_b_id(b_id * tbid);
void free_base(base * b, b_id * bid);

#endif
