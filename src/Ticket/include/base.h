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
#include"bid.h"

typedef struct BASE_T {
  ticket_bundle ** general_population;
  b_id * bid;
  int available_space;
  int total_space;
}base;

base * init_base(int total_space);
void add_ticket_bundle(base * b, int partition_qty);
void delete_ticket_bundle(base * b, int id);
void left_shift_general_population(base * b, int id);
void delete_last_member(base * b);
int find_ticket_bundle(base * b, int id);
void free_base(base * b, int free_tb);
void base_dump_stats(base * b);

#endif
