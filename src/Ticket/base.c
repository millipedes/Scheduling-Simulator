/**
 * @file base.c
 * @brief This file contains the functions relating to the way tickets are
 * distributed by the base
 * @author Matthew C. Lindeman
 * @date May 03, 2022
 * @bug None known
 * @todo Nothing
 */
#include"include/base.h"

/**
 * This funciton initializes the base for the universe
 * @param available_space - the total base units for the base
 * @return              b - the base
 */
base * init_base(int available_space) {
  base * b = calloc(1, sizeof(BASE_T *));
  b->general_population = NULL;
  b->available_space = available_space;
  return b;
}

/**
 * This function initializes a base id structure that is used to partition the
 * general population
 * @return bid - the base id structure
 */
b_id * init_b_id(void) {
  b_id * bid = calloc(1, sizeof(struct B_ID_T));
  b->id_space = NULL;
  b->active_ids = NULL;
  size = 0;
  return bid;
}

/**
 * This function makes a new partition in the general population for the 
 * @param
 * @return
 */
void add_ticket_bundle(base * b, b_id * bid, int partition_qty) {
}

void compact_base(base * b, b_id bid) {
}

void free_ticket_bundle(base * b, int id) {
}

void free_tb_id(tb_id * tbid) {
}

void free_base(base * b) {
  if(b) {
    if(b->general_population) {
      for(int i = 0; i < b->size; i++) {
        free_ticket_bundle(b->general_population[i]);
      }
      free(b->general_population);
      if(b->id_space) {
        free(b->id_space);
      }
      if(b->active_ids) {
        free(b->active_ids);
      }
    }
    free(b);
  }
}
