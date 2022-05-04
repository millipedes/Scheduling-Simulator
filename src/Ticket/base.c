/**
 * @file base.c
 * @brief This file contains the functions relating to the way tickets are
 * distributed by the base
 * @NOTE in this file I talk about partitions but as we only care about memory
 * as a scalar not a vector, its technically not a "partition"
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
base * init_base(int total_space) {
  base * b = calloc(1, sizeof(struct BASE_T *));
  b->general_population = NULL;
  b->available_space = total_space;
  b->total_space = total_space;
  b->total_fault_count = 0;
  return b;
}

/**
 * This function initializes a base id structure that is used to partition the
 * general population
 * @return bid - the base id structure
 */
b_id * init_b_id(void) {
  b_id * bid = calloc(1, sizeof(struct B_ID_T));
  bid->id_space = NULL;
  bid->active_ids = NULL;
  bid->current_id = 0;
  bid->size = 0;
  return bid;
}

/**
 * This function makes a new partition in the general population for the 
 * @param             b - the base to be added onto
 * @param           bid - the base id struct for the given base
 * @param partition_qty - the total quantity of the partition
 * @return
 */
void add_ticket_bundle(base * b, b_id * bid, int partition_qty) {
  bid->size++;
  bid->current_id++;
  b->available_space -= partition_qty;
  if(b->general_population) {
    b->general_population = realloc(b->general_population, bid->size
        * sizeof(struct TICKET_BUNDLE_T *));
  } else {
    b->general_population = calloc(bid->size, sizeof(struct TICKET_BUNDLE_T *));
  }
  b->general_population[bid->size - 1] = init_ticket_bundle(bid->current_id, partition_qty);
}

/**
 * This function removes a ticket bundle with id id from the base
 * @param   b - the base
 * @param bid - the id structure for the base
 * @param  id - the id of the ticket bundle to be removed
 * @return
 */
void delete_ticket_bundle(base * b, b_id * bid, int id) {
  if(find_ticket_bundle(b, bid, id) == -1) {
    fprintf(stderr, "[FREE_TICKET_BUNDLE]: ID: `%d` not found. Exiting\n", id);
    exit(1);
  }
}

int find_ticket_bundle(base * b, b_id * bid, int id) {
  for(int i = 0; i < bid->size; i++) {
    if(b->general_population[i]->id == id) {
      return i;
    }
  }
  return -1;
}

void free_b_id(b_id * tbid) {
}

void free_base(base * b, b_id * bid) {
  if(b) {
    if(b->general_population) {
      for(int i = 0; i < bid->size; i++) {
        free_ticket_bundle(b->general_population[i]);
      }
      free(b->general_population);
    }
    free(b);
  }
}
